#include <iostream>
#include <string>
#include "random_value.h"
#include "high_scores.h"

int main() {

    bool win = false;
    std::string gamer_name;
	// const int target_value = 5;
	const int target_value = gen_random_value(10);
	int current_value = 0;
    int attempts_count = 1;
    const std::string high_scores_filename = "../high_scores.txt";

    print_top_results(high_scores_filename);
    gamer_name = ask_name(gamer_name);
	std::cout << "Welcome: " << gamer_name << std::endl;

    while (!(win))
    {

	std::cout << "Enter your number:" << std::endl;
    std::cin >> current_value;
	std::cout << "INFO: Your number is:" << current_value << std::endl;

	if (current_value > target_value) {
		std::cout << "less than " << current_value << std::endl;
        attempts_count++;
	}
	else if (current_value < target_value) {
		std::cout << "greater than " << current_value << std::endl;
        attempts_count++;
	}
	else {
		std::cout << "you win!" << std::endl;
        win = true;
        std::cout << "Count of attemps:" << attempts_count << std::endl;
		break;
	}

    }

    save_top_results(gamer_name, attempts_count, high_scores_filename);

	return 0;
}