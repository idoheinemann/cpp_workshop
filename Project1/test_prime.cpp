#include "test_prime.h"

bool is_prime(unsigned int num) {
	for (unsigned int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}


void fill_with_primes(int* arr, unsigned int len) {
	unsigned int filled = 0;
	int prime_count = 2;
	while (filled < len) {
		if (is_prime(prime_count)) {
			arr[filled++] = prime_count;
		}
		prime_count++;
	}
}
