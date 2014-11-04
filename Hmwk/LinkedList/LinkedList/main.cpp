/*
* Jose Sandoval
* CIS-17C: C++ Programming
* October 7, 2014
* Homework #5: Extended Linked List
* Description: Linked list data structure with added functions.
*/

// Libraries
#include "LinkedList.h"

int main(int argc, char** argv) 
{
	//Create a linkedList
	LinkedList<int> list;
	
	// Testing append() function
	int clinks = 4;
	for (int i = 1; i <= clinks; i++)
	{
		list.append(i);
	}

	// Test toString() function
	cout << "Elements in the list:" << endl;
	list.toString();
	cout << "Size of the linked list: " << list.size() << "\n" << endl;

	// Test first() and last() functions
	cout << "First element in the list: " << list.first() << endl;
	cout << "Last element in the list: " << list.last() << "\n" << endl;

	// Test prepend() function
	list.prepend(5);
	cout << "List after prepend(5) function:" << endl;
	list.toString();
	cout << "Size of the linked list: " << list.size() << "\n" << endl;

	// Test extract() function
	list.extract(3);
	cout << "List after extract(3) function:" << endl;
	list.toString();
	cout << "Size of the linked list: " << list.size() << "\n" << endl;

	// Test insertAfter() function
	list.insertAfter(list.findNode(1), 9);
	cout << "List after inserting 9 using the insertAfter() function:" << endl;
	list.toString();
	cout << "Size of the linked list: " << list.size() << "\n" << endl;

	// Test insertBefore() function
	list.insertBefore(list.findNode(1), 15);
	cout << "List after inserting 15 using the insertBefore() function:" << endl;
	list.toString();
	cout << "Size of the linked list: " << list.size() << "\n" << endl;

	// Testing the copy constructor
	LinkedList<int> copyList = list;
	cout << "Linked list created with the copy constructor: " << endl;
	copyList.toString();
	cout << "Size of the linked list: " << copyList.size() << "\n" << endl;

	// Testing the overloaded = operator
	LinkedList<int> anotherList;
	anotherList = list;
	cout << "Linked list created with overloaded = operator: " << endl;
	anotherList.toString();
	cout << "Size of the linked list: " << anotherList.size() << "\n" << endl;

	// String Linked List
	LinkedList<string> stringList;
	cout << "String linked list: " << endl;
	stringList.append("l");
	stringList.prepend("H");
	stringList.append("o");
	stringList.insertAfter(stringList.findNode("l"), "l");
	stringList.insertBefore(stringList.findNode("l"), "e");
	stringList.toString();
	cout << "Size of the linked list: " << stringList.size() << "\n" << endl;
	
	//Exit stage right!
	return 0;
}