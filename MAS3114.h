#ifndef MAS3114_H
#define MAS3114_H
#pragma once
#include "Course.h"
#include <iostream>
using namespace std;

//this bit says that this particular class is a child of Course
class MAS3114 : public Course {
private:
	//there are 4 exams, 240 points total
	//No separate final exam
	double participation; //52.5 points total
	double quiz; //60 points
	double homework[30]; // 90 points total
	double tempHomework[30];
	double projects[5]; //130 points total
	double tempProjects[5];
	//helper functions for calc gpa
	double pointSummer(double[], int);
	double examPointSummer(double[20]);

public:
	//constructor
	MAS3114();
	//calculate gpa based on all grades in class
	void calcGpa();
	//setters for private variables
	void updateHomework(int, double);
	void updateProjects(int, double);
	void updateParticipation(double);
	void updateQuiz(double);
	void updateExams(int, double);
	//prints all of the grade values for the class
	void printAll();

};
#endif // !MAS3114_H

