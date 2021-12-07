
#include <iostream>
#include <string>

#include "complex.h"

using namespace std;

#define STR_SIZE 3

int main() {
    Complex a(3, 5);
    Complex b(2, 7);
    cout << "a+b: " << a + b << endl;
    cout << "a-b: " << a - b << endl;
    cout << "a*b: " << a * b << endl;
}