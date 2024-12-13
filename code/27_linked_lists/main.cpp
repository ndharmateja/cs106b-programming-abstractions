/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "linked_list.h"
using namespace std;

int main()
{
    LinkedList list;
    for (int i = 0; i < 5; i++)
    {
        list.add(i);
        list.print();
    }
    for (int i = 0; i < 5; i++)
    {
        list.addFirst(100);
        list.print();
    }

    list.set(0, -100);
    list.print();

    list.insert(10, -100);
    list.print();

    list.remove(10);
    list.print();
    list.remove(0);
    list.print();

    list.clear();
    list.print();

    return 0;
}
