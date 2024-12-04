/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "vector.h"
#include <iostream>
using namespace std;


void printBinary(int digits, Vector<int> &prefix)
{
    if (digits == 0)
    {
        for (int bit : prefix)
            cout << bit;
        cout << endl;
        return;
    }

    prefix.add(0);
    printBinary(digits-1, prefix);
    prefix.remove(prefix.size() - 1);
    prefix.add(1);
    printBinary(digits-1, prefix);
    prefix.remove(prefix.size() - 1);
}

void printBinary(int digits) {
    Vector<int> v;
    printBinary(digits, v);
}

int main()
{
    printBinary(3);
    return 0;
}
