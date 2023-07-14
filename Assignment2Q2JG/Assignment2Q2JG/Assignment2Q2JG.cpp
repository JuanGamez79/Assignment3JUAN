#include "Class.hpp"

int main()
{
	Queue linkedList;
	int elem = 0;
	std::cout << "How many elements do you want in the Queue:";
	std::cin >> elem;

	// Adding elements to the queue
	for (auto i = 0; i < elem; i++) {
		data temp;
		std::cout << "Assign this element a number:";
		std::cin >> temp.order;
		linkedList.addElement(temp);
	}

	// Removing and printing elements from the queue
	while (linkedList.getNum() != 0) {
		std::cout << "The first element " << linkedList.delElement().order << " had been removed\n";
		if (linkedList.listIsEmpty())
			break;
		std::cout << "The new first element is " << linkedList.peek().order << std::endl;
	}

	std::cout << "The list is now empty";

	//linkedList.printList(); testing
}
