/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include <fstream>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;


int main()
{
    ifstream input;
    input.open("data.txt");
    string line;
    int total = 0;
    while(getline(input, line)) {
        if (stringIsInteger(line)){
            total += stringToInteger(line);
        }
    }
    cout << "total: " << total << endl;
    input.close();
    return 0;
}
