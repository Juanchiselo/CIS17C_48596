#ifndef TRIANGULARMATRIX_H
#define TRIANGULARMATRIX_H

// System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

template <class T>
class TriangularMatrix
{
private:
	int rows;
	T* columnArray;
	T** triangularArray;
	void fillColumnArray();

public:
	// Constructor
	TriangularMatrix(int);

	// Destructor
	~TriangularMatrix();
	
	// Methods
	void fillArray();
	void printArray();
	void destroyArray();
};

template <class T>
TriangularMatrix<T>::TriangularMatrix(int rows)
{
	this->rows = rows;
}

template <class T>
TriangularMatrix<T>::~TriangularMatrix()
{
	destroyArray();
}

template <class T>
void TriangularMatrix<T>::fillColumnArray()
{
	// Declare the 1D Column Array
	columnArray = new T[rows];

	// Fill the array with random numbers from 1 to 10
	for (int row = 0; row < rows; row++)
	{
		columnArray[row] = rand() % 9 + 2;
	}
}

template <class T>
void TriangularMatrix<T>::fillArray()
{
	fillColumnArray();

	// Declare the 2D Array
	triangularArray = new T*[rows];

	for (int row = 0; row < rows; row++)
	{
		triangularArray[row] = new T[columnArray[row]];
	}

	// Fill the array with random 2 digit numbers
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columnArray[row]; column++)
		{
			if (typeid(T) == typeid(int))
			{
				triangularArray[row][column] = rand() % 90 + 10;
			}
			else
			{
				triangularArray[row][column] =
					10.0f + static_cast<T> (rand()) / static_cast<T> (RAND_MAX / (90.0f - 10.0f));
			}	
		}
	}
}

template <class T>
void TriangularMatrix<T>::printArray()
{
	// Print column sizes
	for (int row = 0; row < rows; row++)
	{
		cout << "Column size of row #" << (row + 1) << " is "
			<< columnArray[row] << endl;
	}
	cout << endl;

	// Print the array
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columnArray[row]; column++)
		{
			cout << triangularArray[row][column] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

template <class T>
void TriangularMatrix<T>::destroyArray()
{
	//Destroy columns
	for (int row = 0; row < rows; row++)
	{
		delete[] triangularArray[row];
	}

	// Destroy row pointers of triangularArray
	delete[] triangularArray;

	// Destroy column pointers of columnArray
	delete[] columnArray;

	cout << "Arrays deleted!" << endl;
}

#endif