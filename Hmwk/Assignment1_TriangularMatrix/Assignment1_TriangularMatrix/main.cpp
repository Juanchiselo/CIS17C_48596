/*
* Jose Sandoval
* CIS-17C: C++ Programming
* September 9, 2014
* Assignment #1: Triangular Matrix
* Description: Triangular matrix, first data structure.
			   An array that has variable column size
			   on each row.
*/

// Header Files
#include "TriangularMatrix.h"

// Execution begins here
int main(int argc, char** argv)
{
	// Initialize the random number generator
	srand(static_cast<unsigned int>(time(0)));

	// Declare variables
	int rows;

	// Ask user for size of rows
	cout << "How many rows?" << endl;
	cin >> rows;
	cout << endl;

	// Declare TriangularMatrix objects
	TriangularMatrix<int> intTriangularMatrix(rows);
	TriangularMatrix<float> floatTriangularMatrix(rows);

	// Fill the arrays
	intTriangularMatrix.fillArray();
	floatTriangularMatrix.fillArray();

	// Print the triangular arrays
	cout << "Integer Triangular Matrix" << endl;
	intTriangularMatrix.printArray();

	cout << "Float Triangular Matrix" << endl;
	floatTriangularMatrix.printArray();

	// Exit stage right
	return 0;
}