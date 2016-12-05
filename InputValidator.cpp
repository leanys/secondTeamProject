#include <iostream>
#include <string>
#include "InputValidator.h"

using namespace std;

//this checks if cin failed and acts accordingly
bool checkIfCinFailed()
{
	//clears error flags and ignores the next 256 characters or until the '\n' character
	//returns a bool if cin failed
	if (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		return true;
	}
	return false;
}

string InputValidator::getString()
{
	//gets a string from cin and returns it
	string inputString;

	getline(cin, inputString);

	return inputString;
}

int InputValidator::getInt()
{
	int inputInt;
	cin >> inputInt;

	//checks if cin was a valid number
	if (checkIfCinFailed())
	{
		cerr << endl << "Error: the input must be a valid integer" << endl;
		return -1;
	}
	else
	{
		//returns the integer and cleans cin
		cin.clear();
		cin.ignore(256, '\n');
		return inputInt;
	}
}

double InputValidator::getDouble()
{
	double inputDouble;
	cin >> inputDouble;

	//checks if cin was a valid number
	if (checkIfCinFailed())
	{
		cerr << endl << "Error: the input must be a valid double" << endl;
		return -1;
	}
	else
	{
		//returns the integer and cleans cin
		cin.clear();
		cin.ignore(256, '\n');
		return inputDouble;
	}
}