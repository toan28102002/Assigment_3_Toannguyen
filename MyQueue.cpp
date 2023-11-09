#include "MyQueue.h"

template <typename T>
void MyQueue<T>::enqueue(const T& element) {
    elements.push(element);
    std::cout << "Element " << element << " inserted at the rear of the queue." << std::endl;
}

template <typename T>
T MyQueue<T>::dequeue() {
    if (!isEmpty()) {
        T frontElement = elements.front();
        elements.pop();
        std::cout << "Element " << frontElement << " removed from the front of the queue." << std::endl;
        return frontElement;
    }
    else {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return T(); // Return a default value for the type to indicate an empty queue.
    }
}

template <typename T>
T MyQueue<T>::front() const {
    if (!isEmpty()) {
        return elements.front();
    }
    else {
        std::cout << "Queue is empty. No front element to return." << std::endl;
        return T(); // Return a default value for the type to indicate an empty queue.
    }
}

template <typename T>
bool MyQueue<T>::isEmpty() const {
    return elements.empty();
}

template <typename T>
size_t MyQueue<T>::size() const {
    return elements.size();
}

// Explicit instantiation for int and string
template class MyQueue<int>;
template class MyQueue<std::string>;
