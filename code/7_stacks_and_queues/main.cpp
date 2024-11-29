/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "queue.h"
#include "stack.h"
using namespace std;

void reverse_queue(Queue<int>& queue) {
    Stack<int> stack;

    // put all elements of queue in stack
    while (!queue.isEmpty())
        stack.push(queue.dequeue());

    // remove all elements from stack and put in queue
    while(!stack.isEmpty())
        queue.enqueue(stack.pop());
}

// {1, 2, 3} should become {1, 1, 2, 2, 3, 3}
void stutter(Queue<int>& q) {
    int size = q.size();
    for (int i = 0; i < size; ++i) {
        int element = q.dequeue();
        q.enqueue(element);
        q.enqueue(element);
    }
}

// {1, 2, 3} should become {1, 2, 3, 3, 2, 1}
void mirror(Queue<int>& q) {
    Stack<int> s;
    int size = q.size();
    for (int i = 0; i < size; ++i) {
        int element = q.dequeue();
        q.enqueue(element);
        s.push(element);
    }
    while(!s.isEmpty())
        q.enqueue(s.pop());
}

void init_queue(Queue<int>& q) {
    q.clear();
    for (int i = 1; i <= 4; ++i) {
        q.enqueue(i);
    }
}

int main()
{
    Queue<int> queue;

    init_queue(queue);
    cout << "before reverse: " << queue << endl;
    reverse_queue(queue);
    cout << "after reverse: " << queue << endl;

    init_queue(queue);
    cout << endl << "before stutter: " << queue << endl;
    stutter(queue);
    cout << "after stutter: " << queue << endl;

    init_queue(queue);
    cout << endl << "before mirror: " << queue << endl;
    mirror(queue);
    cout << "after mirror: " << queue << endl;

    return 0;
}
