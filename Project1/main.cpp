
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    float number = 0;
    cout << "Enter Number: ";
    cin >> number;
    if (number >= 0) {
        cout << "The root is: " << sqrt(number) << endl;
        return 0;
    }
    else {
        cout << "Can't calculate root of negative number!" << endl;
        return 1;
    }
}