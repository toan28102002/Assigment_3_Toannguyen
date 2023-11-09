#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <queue>

template <typename T>
class MyQueue {
private:
    // Private member variable to store elements using std::queue
    std::queue<T> elements;

public:
    // Function to enqueue an element into the queue
    void enqueue(const T& element);

    // Function to dequeue an element from the front of the queue
    T dequeue();

    // Function to get the element at the front of the queue without removing it
    T front() const;

    // Function to check if the queue is empty
    bool isEmpty() const;

    // Function to get the number of elements in the queue
    size_t size() const;
};

#endif // MYQUEUE_H
