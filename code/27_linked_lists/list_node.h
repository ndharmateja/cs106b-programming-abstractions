#ifndef _list_node_h
#define _list_node_h

#include <iostream>

struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int data = 0, ListNode *next = NULL) : data(data), next(next) {}
};

#endif
