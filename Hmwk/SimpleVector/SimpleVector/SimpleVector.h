// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
	T *aptr;          // To point to the allocated array
	int arraySize;    // Number of elements in the array
	void memError();  // Handles memory allocation errors
	void subError();  // Handles subscripts out of range

public:
	// Default constructor
	SimpleVector()
	{
		aptr = 0; arraySize = 0;
	}

	// Constructor declaration
	SimpleVector(int);

	// Copy constructor declaration
	SimpleVector(const SimpleVector &);

	// Destructor declaration
	~SimpleVector();

	// Accessor to return the array size
	int size() const
	{
		return arraySize;
	}

	// Accessor to return a specific element
	T getElementAt(int position);

	// Overloaded [] operator declaration
	T &operator[](const int &);

	// Push method to increase the array by 1 element at the top,
	// where this element will be stored
	void pushElement(T element);

	// Pull method that takes an element off of the top and
	// decreases the array by 1
	void pullElement();
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int arraySize)
{
	this->arraySize = arraySize;

	// Allocate memory for the array.
	try
	{
		aptr = new T[arraySize];
	}
	catch (bad_alloc)
	{
		memError();
	}

	// Initialize the array.
	for (int count = 0; count < this->arraySize; count++)
		*(aptr + count) = count; //Don't forget to change count back to 0
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
	// Copy the array size.
	arraySize = obj.arraySize;

	// Allocate memory for the array.
	aptr = new T[arraySize];
	if (aptr == 0)
		memError();

	// Copy the elements of obj's array.
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraySize > 0)
		delete[] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
	cout << "ERROR:Cannot allocate memory.\n";
	exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
	cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// script in the array.                                 *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int subscript)
{
	if (subscript < 0 || subscript >= arraySize)
		subError();
	return aptr[subscript];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &subscript)
{
	if (subscript < 0 || subscript >= arraySize)
		subError();
	return aptr[subscript];
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// script in the array.                                 *
//*******************************************************

template <class T>
void SimpleVector<T>::pushElement(T element)
{
	arraySize++;
	
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// script in the array.                                 *
//*******************************************************
template <class T>
void SimpleVector<T>::pullElement()
{
	if (arraySize == 0)
	{
		cout << "ERROR: There are no elements to remove." << endl;
		exit(EXIT_FAILURE);
	}
	
	arraySize--;
}

#endif
