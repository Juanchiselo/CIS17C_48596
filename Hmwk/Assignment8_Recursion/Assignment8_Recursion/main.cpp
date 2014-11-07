/*
* Jose Sandoval
* CIS-17C: C++ Programming
* November 4, 2014
* Assignment #8: Recursion
* Description: Recursive function that predicts savings based on present
			   value, annual interest rate in percentage and number of
			   years.
*/

// System Libraries
#include <iostream>

using namespace std;

float savings(float, float, int);

int main(int argc, char** argv)
{
	// Declare Variables
	float presentValue;
	float interestRate;
	int years;

	// Ask for user input
	cout << "What is the Present Value? " << endl;
	cin >> presentValue;
	cout << "What is the annual interest rate %? " << endl;
	cin >> interestRate;
	cout << "How many years?" << endl;
	cin >> years;

	// Print result
	cout << "Your Future Value is " << savings(presentValue, (interestRate / 100), years) << endl;
	return 0;
}

float savings(float presentValue, float interestRate, int years)
{
	/*if (years > 0)
		return (savings(presentValue, interestRate, years - 1) * (1 + interestRate));

	return presentValue;*/

	if (years == 1)
		return (presentValue / 2) * (1 + interestRate) * (1 + interestRate);

	int halfway = years / 2;
	int top = years - halfway;

	float m1 = savings(presentValue, interestRate, halfway);
	float m2 = savings(presentValue, interestRate, top);

	return (m1 + m2);


	
}