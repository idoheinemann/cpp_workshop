
#include <iostream>

#include "memory_manager.h"

using namespace std;

int main() {
    int* x = new int(3);
    *x = 7;
    print_allocations();
    bool* b = new bool(false);
    *b = true;
    char* chr = new char[50];
    chr[10] = 'i';
    delete b;
    print_allocations();
    delete[] chr;
    print_allocations();
    char* chr2 = new char[20];
    chr2[1] = '3'; // should replace old 50, size remains 50
    print_allocations();
    return 0;
}