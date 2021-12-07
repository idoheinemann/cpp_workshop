
#include <iostream>
#include "String.h"

using namespace std;

int main() {
    String s1("hello");
    String s2(" world");
    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;
    cout << (s1 + s2).c_str() << endl;
    String s3 = s2;
    s3.~String(); // should not delete s2, copy constructor
    cout << s2.c_str() << endl;
    s3 = s1;
    s3.~String(); // should not delete s1, assignment overload
    cout << s1.c_str() << endl;
    s3 = s1.replace(String("l"), String("go"));
    cout << s3.c_str() << endl;
    s3 = s2.insert(String("ww."), 2);
    cout << s3.c_str() << endl;
}