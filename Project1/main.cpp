
#include <iostream>

#include "test_prime.h"

using namespace std;


int main() {

    for (unsigned int i = 2; i < 50; i++) {
        cout << "is " << i << " prime? " << (is_prime(i) ? "yes" : "no") << endl;
    }

    return 0;
}