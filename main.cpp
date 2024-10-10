#include <iostream>
#include <string>

int main() {

    bool win = false;
    std::string gamer_name;
	const int target_value = 5;
	int current_value = 0;

	std::cout << "Hi, enter you nickname:" << std::endl;
    std::cin >> gamer_name;
	std::cout << "Welcome: " << gamer_name << std::endl;

    while (!(win))
    {

	std::cout << "Enter your number:" << std::endl;
    std::cin >> current_value;
	std::cout << "INFO: Your number is:" << current_value << std::endl;

	if (current_value > target_value) {
		std::cout << "less than " << current_value << std::endl;
	}
	else if (current_value < target_value) {
		std::cout << "greater than " << current_value << std::endl;
	}
	else {
		std::cout << "you win!" << std::endl;
        win = true;
		break;
	}

    }

	return 0;
}