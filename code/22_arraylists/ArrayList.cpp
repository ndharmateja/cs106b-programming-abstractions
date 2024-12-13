#include "ArrayList.h"

ArrayList::ArrayList()
{
    numElements = 0;
    capacity = 10;
    elements = new int[capacity]();
}

void ArrayList::add(int element)
{
    resize();
    elements[numElements++] = element;
}

void ArrayList::resize()
{
    if (numElements < capacity)
        return;

    int *newArray = new int[capacity * 2]();
    for (int i = 0; i < capacity; i++)
        newArray[i] = elements[i];

    capacity = capacity * 2;
    delete[] elements;
    elements = newArray;
}

int ArrayList::get(int index) const
{
    if (index < 0 || index >= numElements)
        throw "Invalid index";
    return elements[index];
}

void ArrayList::remove(int index)
{
    if (index < 0 || index >= numElements)
        throw "Invalid index";
    for (int i = index; i < numElements - 1; i++)
        elements[i] = elements[i + 1];
    numElements--;
}

int ArrayList::size() const
{
    return this->numElements;
}

void ArrayList::clear()
{
    this->numElements = 0;
}

void ArrayList::set(int index, int element)
{
    if (index < 0 || index >= numElements)
        throw "Invalid index";
    elements[index] = element;
}

bool ArrayList::isEmpty() const
{
    return this->numElements == 0;
}

void ArrayList::insert(int index, int element)
{
    if (index < 0 || index > numElements)
        throw "Invalid index";

    resize();
    for (int i = numElements; i > index; i--)
    {
        elements[i] = elements[i - 1];
    }
    elements[index] = element;
    numElements++;
}

int ArrayList::operator[](int index) const
{
    return this->elements[index];
}

ostream &operator<<(ostream &out, const ArrayList &list)
{
    out << "{";
    int n = list.numElements;
    for (int i = 0; i < n; i++)
    {
        out << list[i];
        if (i != n - 1)
            out << ", ";
    }
    out << "}";
    return out;
}

ArrayList::~ArrayList()
{
    delete[] this->elements;
}
