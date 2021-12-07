
#include <iostream>
#include <string>
#include "calculator.h"

using namespace std;

#define STR_SIZE 3

int main() {
    Calculator calc;
    cout << "3+5: " << calc.calculate(3, '+', 5) << endl;
    cout << "4*3: " << calc.calculate(4, '*', 3) << endl;
    cout << "5/2: " << calc.calculate(5, '/', 2) << endl;
    try {
        cout << "2/0: " << calc.calculate(2, '/', 0) << endl;
    }
    catch (DivideByZeroException e) {
        cout << "Caused Exception: Divide by 0" << endl;
    }
    try {
        cout << "10^3: " << calc.calculate(10, '^', 3) << endl;
    }
    catch (UnknownOperatorException e) {
        cout << "Caused Exception: Unknown Operation" << endl;
    }

    return 0;
}