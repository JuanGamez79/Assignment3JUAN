#include "Functions.hpp"
// Function to check if parentheses in the infix expression are balanced
bool balancedParen(std::string infix) {
    std::stack<char> paren;
    for (char p : infix) {
        if (p == '(' || p == '{' || p == '[') {
            paren.push(p);
        }
        else if (p == ')' || p == '}' || p == ']') {
            if (paren.empty()) {
                return false; // If closing parenthesis encountered without a corresponding opening parenthesis, expression is unbalanced
            }
            char top = paren.top();
            paren.pop();
            if ((p == ')' && top != '(') || (p == '}' && top != '{') || (p == ']' && top != '[')) {
                return false; // If closing parenthesis doesn't match the top opening parenthesis, expression is unbalanced
            }
        }
    }
    return paren.empty(); // If all parentheses are balanced, the stack should be empty
}

// Function to convert infix expression to postfix expression
std::string postfix(std::string infix) {
    std::string post;
    std::stack<char> inf;
    for (char p : infix) {
        if (isalnum(p)) {
            post += p; // If character is an alphanumeric operand, add it to the postfix expression
        }
        else if (p == '{' || p == '(' || p == '[') {
            inf.push(p); // If character is an opening parenthesis, push it to the stack
        }
        else if (p == ')' || p == '}' || p == ']') {
            while (!inf.empty() && (inf.top() != '(' && inf.top() != '[' && inf.top() != '{')) {
                post += inf.top(); // Pop operators from stack and add them to the postfix expression until matching opening parenthesis is found
                inf.pop();
            }
            if (!inf.empty() && (inf.top() == '(' || inf.top() == '[' || inf.top() == '{')) {
                inf.pop(); // Pop the matching opening parenthesis from the stack
            }
        }
        else {
            while (!inf.empty() && (inf.top() != '(' && inf.top() != '[' && inf.top() != '{') &&
                (p == '*' || p == '/' || p == '%' || p == '+' || p == '-')) {
                if (inf.top() == '*' || inf.top() == '/' || inf.top() == '%') {
                    post += inf.top(); // Pop higher precedence operators from stack and add them to the postfix expression
                    inf.pop();
                }
                else {
                    break; // Break the loop if operator has lower precedence than the top of the stack
                }
            }
            inf.push(p); // Push the current operator to the stack
        }
    }
    while (!inf.empty()) {
        post += inf.top(); // Add remaining operators from stack to the postfix expression
        inf.pop();
    }
    return post;
}