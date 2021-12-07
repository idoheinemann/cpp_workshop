
#include <iostream>
#include <string>

using namespace std;

#define STR_SIZE 3

int main() {
    string str;
    for (int i = 1; i < 12; i++) {
        for (int j = 1; j < 12; j++) {
            str = to_string(i * j);
            str.resize(STR_SIZE, ' ');
            cout << str << "|";
        }
        cout << endl;
    }

    return 0;
}