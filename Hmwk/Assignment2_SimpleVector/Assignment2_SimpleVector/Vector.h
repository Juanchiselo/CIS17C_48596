/*
 * Jose Sandoval
 * CIS-17C: C++ Programming
 * September 17, 2014
 * Assignment #2: Simple Vector
 * Description: A simple vector data structure
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function

using namespace std;

template <class T>
class Vector
{
private:
	T *aptr;          // To point to the allocated array
	int arraySize;    // Number of elements in the array
	void memoryError();  // Handles memory allocation errors
	void subscriptError();  // Handles subscripts out of range

public:
	Vector(); // Default constructor
	Vector(int); // Constructor declaration
	Vector(const Vector&); // Copy constructor declaration
	~Vector(); // Destructor declaration
	int size() const; // Accessor to return the array size
	T getElementAt(int); // Accessor to return a specific element
	T& operator[](const int&); // Overloaded [] operator declaration
	void pushElement(T); // Push method to increase the array by 1 element at the top,
						 // where this element will be stored
	void pullElement();  // Pull method that takes an element off of the top and
						 // decreases the array by 1
};

//*******************************************
// Default Constructor for Vector class.    *
//*******************************************

template <class T>
Vector<T>::Vector()
{
	aptr = 0;
	arraySize = 0;
}

//***********************************************************
// Constructor for Vector class. Sets the size of the       *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
Vector<T>::Vector(int arraySize)
{
	this->arraySize = arraySize;

	// Allocate memory for the array
	try
	{
		aptr = new T[arraySize];
	}
	catch (bad_alloc)
	{
		memoryError();
	}

	// Initialize the array
	for (int count = 0; count < this->arraySize; count++)
		*(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for Vector class.       *
//*******************************************

template <class T>
Vector<T>::Vector(const Vector& other)
{
	// Copy the array size
	arraySize = other.arraySize;

	// Allocate memory for the array
	aptr = new T[arraySize];
	if (aptr == 0)
		memoryError();

	// Copy the elements of other's array
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = *(other.aptr + count);
}

//**************************************
// Destructor for Vector class.        *
//**************************************

template <class T>
Vector<T>::~Vector()
{
	if (arraySize > 0)
		delete[] aptr;
}

//*******************************************************
// memoryError function. Displays an error message and  *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void Vector<T>::memoryError()
{
	cout << "ERROR: Cannot allocate memory." << endl;
	exit(EXIT_FAILURE);
}

//***********************************************************
// subscriptError function. Displays an error message and   *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void Vector<T>::subscriptError()
{
	cout << "ERROR: Subscript out of range." << endl;
	exit(EXIT_FAILURE);
}

//*******************************************************
// size function. Returns the size of the vector.       *
//*******************************************************

template <class T>
int Vector<T>::size() const
{
	return arraySize;
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// script in the array.                                 *
//*******************************************************

template <class T>
T Vector<T>::getElementAt(int subscript)
{
	if (subscript < 0 || subscript >= arraySize)
		subscriptError();
	return aptr[subscript];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T& Vector<T>::operator[](const int& subscript)
{
	if (subscript < 0 || subscript >= arraySize)
		subscriptError();
	return aptr[subscript];
}

//*******************************************************
// pushElement function. The argument is an element.    *
// This function pushes or stores an element into the   *
// vector, it places it at the top.                     *
//*******************************************************

template <class T>
void Vector<T>::pushElement(T element)
{
	// Increase array size variable by 1
	arraySize++;

	// Allocate memory for the temporary array
	T* tempArray = new T[arraySize];
	if (tempArray == 0)
		memoryError();

	// Copy the elements from the old array to the temporary array
	for (int count = 0; count < arraySize - 1; count++)
		tempArray[count] = aptr[count];

	// Add new element to the temporary array
	tempArray[arraySize - 1] = element;

	// Delete old array
	delete[] aptr;

	// Rebuild old array
	aptr = new T[arraySize];
	for (int count = 0; count < arraySize; count++)
		aptr[count] = tempArray[count];

	// Delete temporary array
	delete[] tempArray;
}

//*******************************************************
// pullElement function. This function removes an       *
// element from the top of the vector.                  *
//*******************************************************
template <class T>
void Vector<T>::pullElement()
{
	if (arraySize <= 0)
		cout << "ERROR: There are no elements to remove anymore." << endl;
	else
	{
		// Decrease array size variable by 1
		arraySize--;

		// Allocate memory for the temporary array.
		T* tempArray = new T[arraySize];
		if (tempArray == 0)
			memoryError();

		// Copy the elements from the old array to the temporary array.
		for (int count = 0; count < arraySize; count++)
			tempArray[count] = aptr[count];

		// Delete old array
		delete[] aptr;

		// Rebuild old array
		aptr = new T[arraySize];
		for (int count = 0; count < arraySize; count++)
			aptr[count] = tempArray[count];

		// Delete temporary array
		delete[] tempArray;
	}
}

#endif