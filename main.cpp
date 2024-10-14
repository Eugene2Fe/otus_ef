#include <iostream>
#include <string>
#include "random_value.h"
#include "high_scores.h"

int main(int argc, char** argv) {

    int max_random_val = 10;

    if(argv[1] and argv[2] and !(argv[3])){
        std::string arg1_value{argv[1]};
        if (arg1_value == "--max" and (isdigit(atoi(argv[2])))) {
            int max_random_val = 0;
            if (argc < 3) {
                std::cout << "Wrong usage! The argument '--max 10' requires some INT value! \n Using default val" << std::endl;
                return -1;
            }
            max_random_val = std::atoi(argv[2]);
            std::cout << "Max value bay be before 0 and " << argv[2] << std::endl;
        }
        else{
                std::cout << "Wrong usage! The argument '--max 10' requires some INT value! \n Using default val" << std::endl;
        }
    }
    else
    {
        std::cout << "Max value bay be before 0 and " << max_random_val << std::endl;
    }


    bool win = false;
    std::string gamer_name;
	const int target_value = gen_random_value(max_random_val);
	int current_value = 0;
    int attempts_count = 1;

    const std::string high_scores_filename = "../high_scores.txt";

    print_top_results(high_scores_filename);
    gamer_name = ask_name(gamer_name);
	std::cout << "Welcome: " << gamer_name << std::endl;

    while (!(win))
    {

	std::cout << "Enter your number: " << std::endl;
    std::cin >> current_value;
	std::cout << "INFO: Your number is: " << current_value << std::endl;

	if (current_value > target_value) {
		std::cout << "less than " << current_value << std::endl;
        attempts_count++;
	}
	else if (current_value < target_value) {
		std::cout << "greater than " << current_value << std::endl;
        attempts_count++;
	}
	else {
		std::cout  << gamer_name << ", you win! "<< std::endl;
        win = true;
        std::cout << "Count of attemps: " << attempts_count << std::endl;
		break;
	}

    }

    save_top_results(gamer_name, attempts_count, high_scores_filename);

	return 0;
}