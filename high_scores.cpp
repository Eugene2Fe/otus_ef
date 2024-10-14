#include <iostream>
#include <fstream>
#include <string>
#include "high_scores.h"


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

void print_top_results(std::string high_scores_filename)
	{
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
