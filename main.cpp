#include "ExpressionManager.h"
#include <iostream>
#include "MyQueue.h"

int main() {
    using namespace std;  // Add this line to use the std namespace

    string inputInfix;
    cout << "Enter infix expression: ";
    getline(cin, inputInfix);

    // Balanced Parentheses Check
    if (!ExpressionManager::isParenthesisBalanced(inputInfix)) {
        cout << "Invalid Expression - Unbalanced Parentheses" << endl;
    }
    else {
        string outputPostfix = ExpressionManager::infixToPostfix(inputInfix);
        cout << "Postfix expression: " << outputPostfix << endl;
    }

    cout << " \n";


    MyQueue<int> myIntQueue;
    MyQueue<string> myStringQueue;

    cout << "Is the integer queue empty? " << (myIntQueue.isEmpty() ? "Yes" : "No") << endl;

    myIntQueue.enqueue(10);
    myIntQueue.enqueue(20);
    myIntQueue.enqueue(30);

    cout << "Front element of the integer queue: " << myIntQueue.front() << endl;

    cout << "Is the integer queue empty? " << (myIntQueue.isEmpty() ? "Yes" : "No") << endl;

    cout << "Dequeued element from the integer queue: " << myIntQueue.dequeue() << endl;

    cout << "Front element of the integer queue: " << myIntQueue.front() << endl;

    cout << "Total elements in the integer queue: " << myIntQueue.size() << endl;

    cout << "Is the string queue empty? " << (myStringQueue.isEmpty() ? "Yes" : "No") << endl;

    myStringQueue.enqueue("Hello");
    myStringQueue.enqueue("World");

    cout << "Front element of the string queue: " << myStringQueue.front() << endl;

    cout << "Is the string queue empty? " << (myStringQueue.isEmpty() ? "Yes" : "No") << endl;

    cout << "Dequeued element from the string queue: " << myStringQueue.dequeue() << endl;

    cout << "Front element of the string queue: " << myStringQueue.front() << endl;

    cout << "Total elements in the string queue: " << myStringQueue.size() << endl;

    return 0;
}
