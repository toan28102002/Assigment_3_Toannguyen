#pragma once
#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H

#include <string>

class ExpressionManager {
public:
    // Function to check if a character is an operand
    static bool isOperand(char charac);

    // Function to check if a character is an operator
    static bool isOperator(char charac);

    // Function to determine the precedence of an operator
    static int precedence(char operatorChar);

    // Function to convert an infix expression to postfix
    static std::string infixToPostfix(const std::string& inputExp);

    // Function to check if parentheses in an expression are balanced
    static bool isParenthesisBalanced(const std::string& exp);
};

#endif 
