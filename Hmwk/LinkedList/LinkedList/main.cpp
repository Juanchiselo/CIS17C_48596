/*
* Jose Sandoval
* CIS-17C: C++ Programming
* September 24, 2014
* Homework #4: Linked List
* Description: Linked list data structure
*/

// Libraries
#include "LinkedList.h"

int main(int argc, char** argv) 
{
	//Create a linkedList
	LinkedList list;
	
	// Testing append() function
	int clinks = 4;
	for (int i = 1; i <= clinks; i++)
	{
		list.append(i);
	}

	// Test toString() function
	cout << "Elements in the list:" << endl;
	cout << list.toString();
	cout << "Size of the linked list: " << list.size() << "\n" << endl;

	// Test first() and last() functions
	cout << "First element in the list: " << list.first() << endl;
	cout << "Last element in the list: " << list.last() << "\n" << endl;

	// Test prepend() function
	list.prepend(5);
	cout << "List after prepend(5) function:" << endl;
	cout << list.toString();
	cout << "Size of the linked list: " << list.size() << "\n" << endl;

	// Test extract() function
	list.extract(3);
	cout << "List after extract(3) function:" << endl;
	cout << list.toString();
	cout << "Size of the linked list: " << list.size() << "\n" << endl;

	// Test insertAfter() function
	list.insertAfter(list.findNode(1), 9);
	cout << "List after inserting 9 using the insertAfter() function:" << endl;
	cout << list.toString();
	cout << "Size of the linked list: " << list.size() << "\n" << endl;

	// Test insertBefore() function
	list.insertBefore(list.findNode(1), 15);
	cout << "List after inserting 15 using the insertBefore() function:" << endl;
	cout << list.toString();
	cout << "Size of the linked list: " << list.size() << "\n" << endl;

	// Testing the copy constructor
	LinkedList copyList = list;
	cout << "Linked list created with the copy constructor: " << endl;
	cout << copyList.toString();
	cout << "Size of the linked list: " << copyList.size() << "\n" << endl;

	// Testing the overloaded = operator
	LinkedList anotherList;
	anotherList = list;
	cout << "Linked list created with overloaded = operator: " << endl;
	cout << anotherList.toString();
	cout << "Size of the linked list: " << anotherList.size() << "\n" << endl;
	
	//Exit stage right!
	return 0;
}