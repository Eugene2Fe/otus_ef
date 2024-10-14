#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "high_scores.h"
#include <algorithm>
#include <map>


std::string ask_name(std::string user_name) {
	std::cout << "Hi! Enter your name, please:" << std::endl;
	// std::string user_name;
	std::cin >> user_name;
	return user_name;
}


void save_top_results(std::string user_name, int attempts_count, std::string high_scores_filename){
		std::ofstream out_file{high_scores_filename, std::ios_base::app};

		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			// return -1;
		}

		std::cout << "-> Saved results into file: " << high_scores_filename << std::endl;

		out_file << user_name << ' ' << attempts_count << std::endl;
		// out_file.close();
}

void print_all_results(std::string high_scores_filename){
		std::ifstream in_file{high_scores_filename};
		// in_file.open(high_scores_filename); // окрываем файл для чтения
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
			// return -1;
		}

		std::cout << "High scores table:" << std::endl;

		std::string username;
		int high_score = 0;
		while (true) {
			// Read the username first
			in_file >> username;
			// Read the high score next
			in_file >> high_score;
			// Ignore the end of line symbol
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}

			// Print the information to the screen
			std::cout << username << '\t' << high_score << std::endl;
		}
		std::cout << std::endl;
	}


struct Gamer_Ochki {
    std::string gamer;
    int ochkov;
};

bool compare_scores(const Gamer_Ochki &a, const Gamer_Ochki &b) {
    return a.ochkov < b.ochkov;
}

void print_top_results(std::string high_scores_filename) {
    std::cout << "Highest scores:" << std::endl;
    std::ifstream inputFile(high_scores_filename);

    if (inputFile.is_open()) {
        std::map<std::string, int> unique_games_results;
        std::string line;

        // Чтение и обновление результатов в map
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            Gamer_Ochki gamer_i_ochki;
            iss >> gamer_i_ochki.gamer >> gamer_i_ochki.ochkov;

            if (unique_games_results.find(gamer_i_ochki.gamer) == unique_games_results.end() ||
                unique_games_results[gamer_i_ochki.gamer] > gamer_i_ochki.ochkov) {
                   unique_games_results[gamer_i_ochki.gamer] = gamer_i_ochki.ochkov;
            }
        }

        inputFile.close();

        std::vector<Gamer_Ochki> all_games_results;
        for (const auto &entry : unique_games_results) {
            all_games_results.push_back({entry.first, entry.second});
        }

        std::sort(all_games_results.begin(), all_games_results.end(), compare_scores);

        for (const auto &one_gamer : all_games_results) {
            std::cout << one_gamer.gamer << " " << one_gamer.ochkov << std::endl;
        }

    } else {
        std::cout << "\nFailed to open file: " << high_scores_filename << std::endl;
    }
}
