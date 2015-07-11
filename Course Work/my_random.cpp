#include <random>
#include "my_random.h"

bool flip_coin(double probability) {
	return rand() % 100 < probability * 100;
}