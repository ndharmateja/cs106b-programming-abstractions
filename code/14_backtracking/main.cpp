/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "vector.h"
#include <iostream>
using namespace std;

void printDigit(int digit)
{
    if (digit < 10)
        cout << digit;
    else if (digit == 10)
        cout << "A";
    else if (digit == 11)
        cout << "B";
    else if (digit == 12)
        cout << "C";
    else if (digit == 13)
        cout << "D";
    else if (digit == 14)
        cout << "E";
    else if (digit == 15)
        cout << "F";
}

void printPermutations(int digits, Vector<int> &prefix, int base)
{
    if (digits == 0)
    {
        for (int digit : prefix)
            printDigit(digit);
        cout << endl;
        return;
    }

    for (int i = 0; i < base; ++i)
    {
        prefix.add(i);
        printPermutations(digits - 1, prefix, base);
        prefix.remove(prefix.size() - 1);
    }
}

void printBinary(int digits)
{
    Vector<int> v;
    printPermutations(digits, v, 2);
}

void printDecimal(int digits)
{
    Vector<int> v;
    printPermutations(digits, v, 10);
}

void printHexadecimal(int digits)
{
    Vector<int> v;
    printPermutations(digits, v, 16);
}

int main()
{
    cout << "printBinary(2):" << endl;
    printBinary(2);
    cout << "printDecimal(3):" << endl;
    printDecimal(3);
    cout << "printHexdecimal(2):" << endl;
    printHexadecimal(2);
    return 0;
}
