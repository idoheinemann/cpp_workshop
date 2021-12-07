
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

#define STR_SIZE 3

int main() {
    for (int i = 1; i < 12; i++) {
        for (int j = 1; j < 12; j++) {
            cout << setw(STR_SIZE) << i * j << "|";
        }
        cout << endl;
    }

    return 0;
}