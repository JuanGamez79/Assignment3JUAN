#include "Class.hpp"

Queue::Queue() {
	headptr = nullptr;
}

void Queue::addElement(data data) {
	// Create a new node
	Node* newNode = new Node;
	newNode->data = data;
	newNode->nextPtr = nullptr;

	if (headptr == nullptr) {
		// If the queue is empty, make the new node the head
		headptr = newNode;
	}
	else {
		// Traverse to the end of the queue and add the new node
		Node* tempPtr = headptr;
		while (tempPtr->nextPtr != nullptr) {
			tempPtr = tempPtr->nextPtr;
		}
		tempPtr->nextPtr = newNode;
	}

	// Increment the count of elements in the queue
	listCount++;
}

data Queue::peek() const {
	// Return the data of the first element in the queue
	return headptr->data;
}

data Queue::delElement() {
	// Decrement the count of elements in the queue
	listCount--;

	// Get the data of the first element
	auto order = headptr->data;

	// Remove the first element from the queue
	Node* newNode = headptr;
	headptr = headptr->nextPtr;
	delete newNode;
	newNode = nullptr;

	return order;
}

bool Queue::listIsEmpty() {
	// Check if the queue is empty
	if (headptr == nullptr) {
		return true;
	}
	return false;
}

void Queue::printList() {
	// Print the elements in the queue
	Node* tempPtr = headptr;
	while (tempPtr != nullptr) {
		std::cout << tempPtr->data.order << std::endl;
		tempPtr = tempPtr->nextPtr;
	}
}

int Queue::getNum() {
	// Return the number of elements in the queue
	return listCount;
}
