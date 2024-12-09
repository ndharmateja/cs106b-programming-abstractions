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

void print(Vector<char> chosen)
{
    for (char c : chosen)
        cout << c;
    cout << endl;
}

void permute(string s, Vector<char> &chosen, HashSet<char> &chosenSet)
{
    if (chosen.size() == s.length())
        print(chosen);
    else
    {
        for (char c : s)
        {
            if (!chosenSet.contains(c))
            {
                // Choose
                chosen.add(c);
                chosenSet.add(c);

                // Explore
                permute(s, chosen, chosenSet);

                // Un-choose
                chosen.remove(chosen.size() - 1);
                chosenSet.remove(c);
            }
        }
    }
}

void permute(string s)
{
    HashSet<char> chosenSet;
    Vector<char> chosen;
    permute(s, chosen, chosenSet);
}

int main()
{
    permute("abc");
    return 0;
}
