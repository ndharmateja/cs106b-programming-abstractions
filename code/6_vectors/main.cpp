/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "vector.h"
using namespace std;

void remove_all(Vector<string>& v, string key) {
    int i = 0;
    while (i < v.size()) {
        if (v[i] == key)
            v.remove(i);
        else
            i++;
    }
}

int main()
{
    Vector<int> v;
    v += 5, 10;
    cout << v << endl;

    Vector<string> v1;
    v1.add("dharma");
    v1.add("teja");
    v1.insert(1, "nuli");
    cout << v1 << endl;

    for(string& s: v1) { s = "d"; }
    cout << v1 << endl;

    Vector<string> v2;
    v2 += "a", "b", "c", "b", "d", "a", "b"; // v2 = {a, b, c, b, d, a, b}
    cout << endl;
    cout << "Before removing bs: " << v2 << endl;
    remove_all(v2, "b"); // should make v2 = {a, c, d, a}
    cout << "After removing bs: " << v2 << endl;

    return 0;
}
