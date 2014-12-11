/*
* Jose Sandoval
* CIS-17C: C++ Programming
* December 6, 2014
* Assignment #7: Hash Comparison
* Description: Compare time taken for
		linear, binary and hash searches,
		and prove their big O.
*/

// Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "LinkedList.h"

using namespace std;

// Function prototypes
string randomStringGenerator(int);
void fillArrays(string[], string[], int);
int linearSearch(string[], string, int);
int binarySearch(string[], string, int, int);
void createHashTable(string[], string[], int);
int hasher(string, int);
int hashSearch(LinkedList<string>[], string, int);
void statistics(string, float, int, int, int);

int main(int argc, char** argv)
{
	// Initialize the random number generator
	srand(static_cast<unsigned int>(time(0)));

	// Create variables for time analysis.
	clock_t startTime;
	clock_t endTime;
	float elapsedTime;

	// Create variables to hold quantity of
	// successful and failed searches.
	int found = 0;
	int notFound = 0;

	// Size of array.
	int SIZE;

	// Ask user for size of array.
	cout << "Enter the size of the array: ";
	cin >> SIZE;

	// Create dynamic arrays to hold the random
	// strings and the targets.
	string* randomStrings = new string[SIZE];
	string* targets = new string[SIZE];

	// Fill arrays with random generated strings of
	// 20 characters size.
	fillArrays(randomStrings, targets, SIZE);

	// Test and time the linear search algorithm.
	startTime = clock();
	for (int i = 0; i < SIZE; i++)
	{
		if (linearSearch(randomStrings, targets[i], SIZE) != -1)
			found++;
		else
			notFound++;
	}
	endTime = clock();
	
	elapsedTime = ((float)endTime - (float)startTime) / CLOCKS_PER_SEC;

	// Print out statistics of linear search algorithm.
	cout << endl;
	statistics("Linear", elapsedTime, SIZE, found, notFound);

	// Sort the binaryArray before using
	// the binary search function.
	sort(randomStrings, randomStrings + SIZE);

	found = 0;
	notFound = 0;

	// Test and time binary search algorithm.
	startTime = clock();
	for (int i = 0; i < SIZE; i++)
	{
		if (linearSearch(randomStrings, targets[i], SIZE) != -1)
			found++;
		else
			notFound++;
	}
	endTime = clock();

	elapsedTime = ((float)endTime - (float)startTime) / CLOCKS_PER_SEC;

	// Print out statistics of binary search algorithm.
	statistics("Binary", elapsedTime, SIZE, found, notFound);

	// Create hashTable.
	createHashTable(randomStrings, targets, SIZE);

	// Delete dynamic arrays.
	delete[] randomStrings;
	delete[] targets;

	//Exit stage right!
	return 0;
}

string randomStringGenerator(int length)
{
	const char alphaNumeric[] = "0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	string string;

	for (int i = 0; i < length; i++)
		string += alphaNumeric[rand() % (sizeof(alphaNumeric) - 1)];

	return string;
}

void fillArrays(string randomStrings[], string targets[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		string string = randomStringGenerator(20);
		randomStrings[i] = string;

		// Filling targets array with a 50-50 mix.
		if (i % 2 == 1)
			targets[i] = string;
		else
			targets[i] = randomStringGenerator(20);
	}
}

int linearSearch(string linear[], string target, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (linear[i] == target)
			return i;
	}

	return -1;
}

int binarySearch(string binary[], string target, int first, int last)
{
	while (first <= last)
	{
		int middle = (first + last) / 2;

		if (binary[middle] < target)
			first = middle + 1;
		else if (binary[middle] > target)
			last = middle - 1;
		else
			return middle;
	}

	return -1;
}

void createHashTable(string hash[], string targets[], int SIZE)
{
	LinkedList<string>* hashTable = new LinkedList<string>[SIZE * 2];

	for (int i = 0; i < SIZE * 2; i++)
	{
		LinkedList<string> list;
		hashTable[i] = list;
	}

	for (int i = 0; i < SIZE; i++)
	{
		string key = hash[i];

		int hash = hasher(key, SIZE);

		hashTable[hash].append(key);
	}
	
	clock_t startTime;
	clock_t endTime;
	float elapsedTime;

	int found = 0;
	int notFound = 0;

	// Test and time hash search algorithm.
	startTime = clock();
	for (int i = 0; i < SIZE; i++)
	{
		if (hashSearch(hashTable, targets[i], SIZE) != -1)
			found++;
		else
			notFound++;
	}
	endTime = clock();

	elapsedTime = ((float)endTime - (float)startTime) / CLOCKS_PER_SEC;

	statistics("Hash", elapsedTime, SIZE, found, notFound);

	delete[] hashTable;
}

int hasher(string key, int SIZE)
{
	int hashValue = 0;

	for (int i = 0; i < key.length(); i++)
	{
		char character = key.at(i);
		int ascii = (int)character;
		hashValue += ascii;
	}

	return hashValue % SIZE;
}

int hashSearch(LinkedList<string> hashTable[], string target, int SIZE)
{
	int hash = hasher(target, SIZE);

	if (!hashTable[hash].isEmpty()
		&& hashTable[hash].contains(target))
			return hash;
	else
		return -1;
}

void statistics(string method, float elapsedTime, int SIZE, int found, int notFound)
{
	cout << method << " search took " << elapsedTime << " seconds to search "
		<< "an array of " << SIZE << " elements.\n"
		<< "Average time per search is " << (elapsedTime / SIZE) << " seconds.\n"
		<< found << " elements were FOUND.\n"
		<< notFound << " elements were NOT FOUND.\n" << endl;
}
