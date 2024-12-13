#include "linked_list.h"
#include <cassert>

using namespace std;

LinkedList::LinkedList()
{
    head = new ListNode(-1);
    numElements = 0;
}

LinkedList::~LinkedList()
{
    deleteNodes();
}

void LinkedList::add(int data)
{
    // Move the curr pointer to the last node
    ListNode *curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    // Add after the last node
    insertAfter(curr, data);
    numElements++;
}

void LinkedList::addFirst(int data)
{
    insertAfter(head, data);
    numElements++;
}

void LinkedList::print() const
{
    cout << this->toString() << endl;
}

void LinkedList::insert(int index, int data)
{
    if (index < 0 || index > numElements)
        throw out_of_range("invalid index");

    // Make curr point to the element at "index - 1"
    ListNode *curr = head;
    for (int i = 0; i < index; i++)
        curr = curr->next;

    // Insert after that
    insertAfter(curr, data);
    numElements++;
}

int LinkedList::get(int index)
{
    if (index < 0 || index >= numElements)
        throw out_of_range("invalid index");

    // Make curr point to the element at "index"
    ListNode *curr = head->next;
    for (int i = 0; i < index; i++)
        curr = curr->next;

    return curr->data;
}

void LinkedList::set(int index, int data)
{
    if (index < 0 || index >= numElements)
        throw out_of_range("invalid index");

    // Make curr point to the element at "index"
    ListNode *curr = head->next;
    for (int i = 0; i < index; i++)
        curr = curr->next;

    curr->data = data;
}

void LinkedList::clear()
{
    deleteNodes();
    head = new ListNode(-1);
    numElements = 0;
}

std::string LinkedList::toString() const
{
    string out = "[size = ";
    out += to_string(numElements);
    out += "] ";
    for (ListNode *curr = head->next; curr != NULL; curr = curr->next)
    {
        out += to_string(curr->data);
        out += " -> ";
    }
    return out;
}

void LinkedList::remove(int index)
{
    if (index < 0 || index >= numElements)
        throw out_of_range("invalid index");

    // Make curr point to the element at "index - 1"
    ListNode *curr = head;
    for (int i = 0; i < index; i++)
        curr = curr->next;

    deleteAfter(curr);
    numElements--;
}

int LinkedList::size() const
{
    return numElements;
}

bool LinkedList::isEmpty() const
{
    return numElements == 0;
}

void LinkedList::deleteNodes()
{
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *next = curr->next;
        delete curr;
        curr = next;
    }
}

void LinkedList::insertAfter(ListNode *node, int data)
{
    assert(node != NULL);
    ListNode *newNode = new ListNode(data);
    newNode->next = node->next;
    node->next = newNode;
}

/**
 * Deletes the node after the given node.
 *
 * Precondition: node is not NULL and there is always a node after node.
 */
void LinkedList::deleteAfter(ListNode *node)
{
    assert(node->next != NULL);
    ListNode *nextNode = node->next;
    node->next = nextNode->next;
    delete nextNode;
}

ostream &operator<<(ostream &out, const LinkedList &list)
{
    out << list.toString();
    return out;
}
