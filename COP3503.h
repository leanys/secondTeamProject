#ifndef COP3503_H
#define COP3503_H
#pragma once
#include "Course.h"
#include <iostream>
using namespace std;

//this bit says that this particular class is a child of Course
class COP3503 : public Course {
private:
	//This course is percentage based, so scores will need to be entered by percentage
	//Example, if they get a 79% on the first exam, enter 79
	//not that complicated, but important distinction because other courses do a total sum of points
	//2 exams, no final
	double groupProject;
	double assignments[3];
	double tempAssignments[3];
	//helper functions for gpa calc to sum points when given an array of values
	double pointSummer(double[], int);
	double examPointSummer(double[20]);

public:
	//constructor
	COP3503();
	//calculates the gpa based on grade values
	void calcGpa();
	//setters for the private variables
	void updateAssignments(int, double);
	void updateGroupProject(double);
	void updateExams(int, double);
	//prints all of the specific grade values
	void printAll();
};
#endif // !COP3503_H

