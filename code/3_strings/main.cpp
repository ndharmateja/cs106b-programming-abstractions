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
    string s = "dharma teja";
    print_string(s);
    s.erase(2, 2);
    print_string(s);
    s.append(" nuli");
    print_string(s);

    string s1 = "world";
    string s2 = "hello" + s1;
    print_string(s1);
    print_string(s2);

    string s3 = "hi" + '?';
    print_string(s3);

    ifstream input;
    input.open("data.txt");
    string line;
    int total = 0;
    while (getline(input, line))
    {
        if (stringIsInteger(line))
        {
            total += stringToInteger(line);
        }
    }
    cout << "total: " << total << endl;
    input.close();

    return 0;
}
