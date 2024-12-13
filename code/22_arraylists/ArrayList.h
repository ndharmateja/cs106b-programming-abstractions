#ifndef _arraylist_h
#define _arraylist_h
#include <iostream>

using namespace std;

class ArrayList
{
    friend ostream &operator<<(ostream &out, const ArrayList &list);

public:
    ArrayList();
    ~ArrayList();
    void add(int element);
    int get(int index) const;
    void remove(int index);
    int size() const;
    void clear();
    void set(int index, int element);
    bool isEmpty() const;
    void insert(int index, int element);
    int operator[](int index) const;

private:
    int *elements;
    int numElements;
    int capacity;
    void resize();
};

#endif