
#include <iostream>
#include "String.h"

using namespace std;

int main() {
    String s1("hello");
    String s2(" world");
    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;
    cout << (s1 + s2).c_str() << endl;
}