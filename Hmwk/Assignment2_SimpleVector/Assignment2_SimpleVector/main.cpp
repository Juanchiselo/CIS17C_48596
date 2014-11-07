/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * September 17, 2014
 * Assignment #2: Simple Vector
 * Description: A simple vector data structure
 */

// Header Files
#include "Vector.h"
#include <string>

int main(int argc, char** argv)
{
	// Declare Vector object for integers
	cout << "Creating Vector object...\n" << endl;
	Vector<int> *intVector = new Vector<int>(3);

	// Test size() function
	cout << "Vector Size: " << intVector->size() << endl;
	cout << endl;

	// Test getElementAt() function
	cout << "Elements inside the vector: " << endl;
	for (int i = 0; i < intVector->size(); i++)
	{
		cout << "Element #" << i + 1 << ": "
			 << intVector->getElementAt(i) << endl;
	}
	
	// Test pushElement() function
	for (int i = 1; i <= 5; i++)
		intVector->pushElement(i);

	cout << endl;
	cout << "Vector Size after push: " << intVector->size() << endl;
	cout << endl;

	cout << "Elements inside the vector after push: " << endl;
	for (int i = 0; i < intVector->size(); i++)
	{
		cout << "Element #" << i + 1 << ": "
			 << intVector->getElementAt(i) << endl;
	}

	// Test pullElement() function
	for (int i = 0; i <= 3; i++)
		intVector->pullElement();

	cout << endl;
	cout << "Vector Size after pull: " << intVector->size() << endl;
	cout << endl;

	cout << "Elements inside the vector after pull: " << endl;
	for (int i = 0; i < intVector->size(); i++)
	{
		cout << "Element #" << i + 1 << ": "
			 << intVector->getElementAt(i) << endl;
	}

	// Declare Vector object for strings
	cout << endl;
	cout << "Creating String Vector object...\n" << endl;
	Vector<string> stringVector;

	cout << "Vector size: " << stringVector.size() << endl;
	cout << endl;

	stringVector.pushElement("Hi");
	stringVector.pushElement("I'm");
	stringVector.pushElement("a Vector!");

	cout << "Elements inside the vector after push: " << endl;
	for (int i = 0; i < stringVector.size(); i++)
	{
		cout << "Element #" << i + 1 << ": "
			<< stringVector.getElementAt(i) << endl;
	}

	for (int i = 0; i < 2; i++)
		stringVector.pullElement();

	cout << endl;
	cout << "Vector Size after pull: " << stringVector.size() << endl;
	cout << endl;

	cout << "Elements inside the vector after pull: " << endl;
	for (int i = 0; i < stringVector.size(); i++)
	{
		cout << "Element #" << i + 1 << ": "
			<< stringVector.getElementAt(i) << endl;
	}


	// Exit stage right
	return 0;
}