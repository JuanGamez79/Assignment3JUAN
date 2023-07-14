#pragma once; 

#include <iostream>

struct data {
    int order;
};

struct Node {
    data data;
    Node* nextPtr;
};

class Queue {
private:
    Node* headptr; // Pointer to the head of the queue

public:
    Queue(); // Constructor
    void addElement(data data); // Adds an element to the end of the queue
    data peek() const; // Returns the data of the first element in the queue
    data delElement(); // Removes and returns the first element from the queue
    bool listIsEmpty(); // Checks if the queue is empty
    int listCount = 0; // Counter for the number of elements in the queue
    void printList(); // Prints the elements in the queue
    int getNum(); // Returns the number of elements in the queue
};
