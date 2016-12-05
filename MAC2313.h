#pragma once
#include "Course.h"
#include <iostream>
using namespace std;

//this bit says that this particular class is a child of Course
class MAC2313 : public Course {
private:
	//NOTE: this class is entirely percentage based according to the syllabus
	//This means grades need to be entered as percentage values
	//For example, if they got a 95% on the first exam and 87% on the next two
	//They would enter 95, 87, and 87 
	//There are 3 exams and a final in this class
	double participation;
	double webAssign[27];
	double tempWebAssign [27];
	double quizzes[13];
	double tempQuizzes[13];
	//helper functions for calc gpa
	double pointSummer(double[], int);
	double examPointSummer(double[20]);

public:
	//constructor
	MAC2313();
	//calculates the gpa for the given class
	void calcGpa();
	//setters for private variables
	void updateParticipation(double);
	void updateWebAssign(int, double);
	void updateQuiz(int, double);
	void updateExam(int, double);
	void updateFinal(double);
	//prints all grade values for given class
	void printAll();
};