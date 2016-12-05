
#ifndef _MAC2312_H_
#define _MAC2312_H_
#pragma once
#include "Course.h"
#include <iostream>
using namespace std;
//this bit says that this particular class is a child of Course
class MAC2312 : public Course {
private:
	//NOTE: 3 exams 60 points each, 80 point final
	//course grade is out of 400 points
	double hittPoints; //35 points
	double participation; //4 points
	double webAssign;//50 max out of 54.5 points, a double because no specific number of assignments is given in syllabus
	double quizzes[8]; //best 6 of 8, 6 points each
	double tempQuizzes[8];
	double writtenHomework[3]; //3 collected, 5 points each
	double tempWrittenHomework[3];
	//helper functions for calc gpa
	double pointSummer(double[], int);
	double examPointSummer(double [20]);
	double bestOfQuizzes(double[]);

public:
	//constructor
	MAC2312();
	//calculate gpa based on all grades in class
	void calcGpa();
	//setters for private variables
	void updateHittPoints(double);
	void updateWebAssign(double);
	void updateQuiz(int, double);
	void updateWrittenHomework(int, double);
	void updateParticipation(double);
	void updateExam(int, double);
	void updateFinal(double);
	//prints all of the grade values
	void printAll();
};
#endif