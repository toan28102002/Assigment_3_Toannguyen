#include "ExpressionManager.h"
#include <stack>

// Function to check if a character is an operand
bool ExpressionManager::isOperand(char charac) {
    return (charac >= '0' && charac <= '9');
}

// Function to check if a character is an operator
bool ExpressionManager::isOperator(char charac) {
    return (charac == '+' || charac == '-' || charac == '*' || charac == '/' || charac == '%');
}

// Function to determine the precedence of an operator
int ExpressionManager::precedence(char operatorChar) {
    if (operatorChar == '+' || operatorChar == '-')
        return 1;
    else if (operatorChar == '*' || operatorChar == '/' || operatorChar == '%')
        return 2;
    else
        return 0;
}

// Function to convert an infix expression to postfix
std::string ExpressionManager::infixToPostfix(const std::string& inputExp) {
    std::stack<char> charStack;
    std::string outputPostfix = "";

    for (int i = 0; i < inputExp.length(); i++) {
        char currentChar = inputExp[i];

        if (isOperand(currentChar)) {
            outputPostfix += currentChar;
        }
        else if (isOperator(currentChar)) {
            while (!charStack.empty() && charStack.top() != '(' && precedence(currentChar) <= precedence(charStack.top())) {
                outputPostfix += charStack.top();
                charStack.pop();
            }
            charStack.push(currentChar);
        }
        else if (currentChar == '(') {
            charStack.push(currentChar);
        }
        else if (currentChar == ')') {
            while (!charStack.empty() && charStack.top() != '(') {
                outputPostfix += charStack.top();
                charStack.pop();
            }
            if (!charStack.empty() && charStack.top() == '(') {
                charStack.pop();
            }
            else {
                outputPostfix = "Invalid Expression";
                break;
            }
        }
    }

    while (!charStack.empty()) {
        if (charStack.top() == '(' || charStack.top() == ')') {
            outputPostfix = "Invalid Expression";
            break;
        }
        outputPostfix += charStack.top();
        charStack.pop();
    }

    return outputPostfix;
}

// Function to check if parentheses in an expression are balanced
bool ExpressionManager::isParenthesisBalanced(const std::string& exp) {
    std::stack<char> charStack;

    for (int i = 0; i < exp.length(); i++) {
        char currentChar = exp[i];

        if (currentChar == '{' || currentChar == '[' || currentChar == '(') {
            charStack.push(currentChar);
        }
        else if (currentChar == '}' || currentChar == ']' || currentChar == ')') {
            if (charStack.empty()) {
                return false;
            }
            if ((currentChar == '}' && charStack.top() == '{') || (currentChar == ']' && charStack.top() == '[') || (currentChar == ')' && charStack.top() == '(')) {
                charStack.pop();
            }
            else {
                return false;
            }
        }
    }

    return charStack.empty();
}
