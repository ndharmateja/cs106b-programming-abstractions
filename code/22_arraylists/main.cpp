/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "ArrayList.h"
using namespace std;

ArrayList create() {
    ArrayList list;
    list.add(22);
    return list;
}

int main()
{
    ArrayList list;
    for (int i = 0; i < 20; ++i)
    {
        list.add(i);
        cout << list << endl;
    }

    ArrayList list3 = create();
    cout << list3<< endl;

    list.insert(20, 100);
    cout << list << endl;

    // test the add method
    ArrayList list2;
    for (int i = 0; i < 10; ++i)
    {
        list2.add(i);
    }
    cout << list2 << endl;

    // test the get method
    for (int i = 0; i < 10; ++i)
    {
        int value = list2.get(i);
        cout << value << endl;
    }

    // test the remove method
    list2.remove(3);
    cout << list2 << endl;

    // test the remove method when the index is out of range
    // try
    // {
    //     list2.remove(10);
    // }
    // catch (const std::out_of_range &oor)
    // {
    //     cout << oor.what() << endl;
    // }

    // test the set method
    list2.set(0, 100);
    cout << list2 << endl;

    // test the set method when the index is out of range
    // try
    // {
    //     list2.set(10, 200);
    // }
    // catch (const std::out_of_range &oor)
    // {
    //     cout << oor.what() << endl;
    // }

    // test the size method
    cout << "Size of list2: " << list2.size() << endl;

    // test the clear method
    list2.clear();
    cout << list2 << endl;

    // test the isEmpty method
    cout << "Is list2 empty? " << (list2.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
