#ifndef _linked_list_h
#define _linked_list_h

#include "list_node.h"
using namespace std;

class LinkedList
{
    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list);

public:
    LinkedList();
    ~LinkedList();

    void add(int data);
    void addFirst(int data);
    void print() const;
    void insert(int index, int data);
    int get(int index);
    void set(int index, int data);
    void clear();
    string toString() const;
    void remove(int index);
    int size() const;
    bool isEmpty() const;

private:
    ListNode *head;
    int numElements;
    void deleteNodes();
    void insertAfter(ListNode *node, int data);
    void deleteAfter(ListNode *node);
};

#endif
