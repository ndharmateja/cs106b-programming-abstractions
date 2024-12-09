/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "vector.h"
#include "hashset.h"
using namespace std;

void sublists(Vector<string> v, Vector<string> &chosen, int i)
{
    // Base case
    // If n reaches beyond the last index
    if (i == v.size())
    {
        cout << chosen << endl;
        return;
    }

    // We either choose the i'th string or not
    // 1. Permute with choosing
    chosen.add(v[i]);
    sublists(v, chosen, i + 1);
    chosen.remove(chosen.size() - 1);

    // 2. Permute without choosing
    sublists(v, chosen, i + 1);
}

void sublists(Vector<string> v)
{
    Vector<string> chosen;
    sublists(v, chosen, 0);
}

int main()
{
    Vector<string> v{"a", "b", "c"};
    sublists(v);
    return 0;
}
