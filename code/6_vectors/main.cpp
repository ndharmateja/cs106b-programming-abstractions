/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "vector.h"
using namespace std;


int main()
{
    Vector<int> v;
    v.add(5);
    v.add(10);
    cout << v << endl;

    Vector<string> v1;
    v1.add("dharma");
    v1.add("teja");
    v1.insert(1, "nuli");
    cout << v1 << endl;

    v1.clear();
    cout << v1 << endl;

    return 0;
}
