#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <chrono>
#include <thread>  // 
#include <mutex>   // 

// #define EXIT_FAILURE -1; // WAS BAD example // THIS macro redifined -> <cstdlib> have definition == 1, not -1

const size_t TOPK = 10;

using Counter = std::map<std::string, std::size_t>;

std::string tolower(const std::string &str);

void count_words(std::istream& stream, Counter& counter);

void print_topk(std::ostream& stream, const Counter&, const size_t k);

void merge_counters(Counter& global_counter, const Counter& local_counter, std::mutex& mtx); // will merge in the end

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: topk_words [FILES...] [--single-thread | --multi-thread]\n";
        return EXIT_FAILURE;
    }

    // One or multithreads run program? Parse args
    bool will_use_multithreading = false;
    if (argc > 2 && std::string(argv[argc - 1]) == "--multi-thread") {
        will_use_multithreading = true;
        argc--;
    } else if (argc > 2 && std::string(argv[argc - 1]) == "--single-thread") {
        argc--;
    }

    auto start = std::chrono::high_resolution_clock::now();
    Counter global_freq_dict;
    std::mutex mtx; 
    if (will_use_multithreading) {
        std::vector<std::thread> threads;
        for (int i = 1; i < argc; ++i) {
            threads.emplace_back([i, &mtx, &global_freq_dict, argv]() {
                std::ifstream input{argv[i]};
                if (!input.is_open()) {
                    std::cerr << "Failed to open file " << argv[i] << '\n';
                    return;
                }

                Counter local_counter;
                count_words(input, local_counter);
                merge_counters(global_freq_dict, local_counter, mtx);
            });
        }
        for (auto& t : threads) { // wait all threads
            t.join();
        }
    } else { // 1 thread:
        for (int i = 1; i < argc; ++i) {
            std::ifstream input{argv[i]};
            if (!input.is_open()) {
                std::cerr << "Failed to open file " << argv[i] << '\n';
                return EXIT_FAILURE;
            }
            count_words(input, global_freq_dict);
        }
    }

    print_topk(std::cout, global_freq_dict, TOPK);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time is " << elapsed_ms.count() << " us = "  << elapsed_ms.count()/1000  << " ms\n";
}

std::string tolower(const std::string &str) {
    std::string lower_str;
    std::transform(std::cbegin(str), std::cend(str),
                   std::back_inserter(lower_str),
                   [](unsigned char ch) { return std::tolower(ch); });
    return lower_str;
}

void count_words(std::istream& stream, Counter& counter) {
    std::for_each(std::istream_iterator<std::string>(stream),
                  std::istream_iterator<std::string>(),
                  [&counter](const std::string &s) { ++counter[tolower(s)]; });    
}

void print_topk(std::ostream& stream, const Counter& counter, const size_t k) {
    std::vector<Counter::const_iterator> words;
    words.reserve(counter.size());
    for (auto it = std::cbegin(counter); it != std::cend(counter); ++it) {
        words.push_back(it);
    }

    std::partial_sort(
        std::begin(words), std::begin(words) + k, std::end(words),
        [](const Counter::const_iterator& lhs, const Counter::const_iterator& rhs) {
            return lhs->second > rhs->second;
        });

    std::for_each(
        std::begin(words), std::begin(words) + k,
        [&stream](const Counter::const_iterator &pair) {
            stream << std::setw(4) << pair->second << " " << pair->first
                      << '\n';
        });
}

void merge_counters(Counter& global_counter, const Counter& local_counter, std::mutex& mtx) {
    std::lock_guard<std::mutex> lock(mtx);  // here protect access for 'global_counter'
    for (const auto& pair : local_counter) {
        global_counter[pair.first] += pair.second;
    }
}
