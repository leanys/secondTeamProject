#ifndef MAC2311_H
#define MAC2311_H


#include "Course.h"

//the ifndef and define stuff was a bug fix relating to something called a header guard

//this bit says that this particular class is a child of Course
class MAC2311 : public Course {
private:
	//NOTE: Exams and Final in this course are out of 75 points each
	//Course grade is based on 450 available points
	//Final grade can replace lowest exam grade if it is better
	double hittPoints; //40 points
	double webAssign[13]; // total maxes at 50 points, enter these grades as percentages
	double webAssignPrint[13];
	double quizzes[10]; //best 8 of 10, 6 points each
	double quizzesPrint[10];
	double writtenHomework[5]; //best 4 of 5, 3 points each
	double writtenHomeworkPrint[5];
	double examsPrint[20];
	void examReplace(double[20], double);
	//helper functions for calc gpa function
	double pointSummer(double[], int);
	double examPointSummer(double[20]);
	double bestOfQuizzes(double[]);
	double bestOfWrittenHomework(double[]);
	double webAssignCalculator(double[]);

public:
	//constructor
	MAC2311();
	//calculate gpa based on all grades in class
	void calcGpa();
	//setters for private variables
	void updateHittPoints(double);
	void updateWebAssign(int, double);
	void updateQuiz(int, double);
	void updateWrittenHomework(int, double);
	void updateExam(int, double);
	void updateFinal(double);
	//prints all of the grade values for this class
	void printAll();
};
#endif // !MAC2311_H