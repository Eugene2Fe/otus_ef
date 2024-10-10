#include <iostream>
#include <cstdlib>
#include <ctime>
// #include "random_value.h"

int gen_random_value(int max_value) {
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	u_int8_t random_value = std::rand() % max_value;
	return random_value;
};