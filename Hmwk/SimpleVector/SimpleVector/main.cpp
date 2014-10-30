/*
* Jose Sandoval
* CIS-17C: C++ Programming
* September 17, 2014
* Homework #2: Simple Vector
* Description: A simple vector data structure
*/

// Header Files
#include "SimpleVector.h"

// Execution begins here
int main(int argc, char** argv)
{
	// Declare SimpleVector object
	SimpleVector<int> *intSimpleVector = new SimpleVector<int>(10);

	cout << "Simple Vector Size: " << intSimpleVector->size() << endl;
	cout << "Last Element: " << intSimpleVector->getElementAt(intSimpleVector->size() -1) << endl;

	intSimpleVector->pushElement(3);
	

	

	// Delete SimpleVector object
	delete intSimpleVector;

	// Exit stage right
	return 0;
}