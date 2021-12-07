
#include <iostream>

#include "test_prime.h"

using namespace std;


int main() {

    int amount = 0;
    cout << "Enter amount of primes: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "negative amount is not allowed!" << endl;
        return -1;
    }
    int* arr = new int[amount];
    fill_with_primes(arr, static_cast<unsigned int>(amount));
    for (int i = 0; i < amount; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}