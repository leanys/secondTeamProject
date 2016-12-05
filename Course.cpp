#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include <algorithm>
#include "Course.h"


using namespace std;
//getter for couse name
string Course::getCourseName() {
	return courseName;
}

//setter for course name
void Course::setCourseName(string courseName) {
	this->courseName = courseName;
}

//getter for credits
int Course::getCredits() {
	return credits;
}

//setter for credits
void Course::setCredits(int credits) {
	this->credits = credits;
}

//getter for gpa
double Course::getGpa() {
	return gpa;
}

//setter for gpa
void Course::setGpa(double gpa) {
	this->gpa = gpa;
}

//prints a general summary of the class
void Course::printCourse() {
	if (gpa < 0) {
		cout << courseName.c_str() << ": " << "\n\t" << "GPA: N/A" << ", Credit Hours: " << credits << endl;
	}
	else {
		cout << courseName.c_str() << ": " << "\n\t" << "GPA: " << gpa << ", Credit Hours: " << credits << endl;
	}
}