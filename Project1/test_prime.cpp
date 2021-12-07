#include "test_prime.h"

bool is_prime(unsigned int num) {
	for (unsigned int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
