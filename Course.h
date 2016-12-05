// Coure Class
//COP3503TeamProject
//
//Created by Sabrina Vega 11/12/16
//
#ifndef COURSE
#define COURSE

using namespace std;
#include <string>

//Parent class to base our other classes off of 
class Course {
public:
	//constructor
	//sets credits and gpa to -1 to indicate that the grades have not been set
	Course() : courseName(), credits(-1), gpa(-1), exams(), finals() {};
	//setters for certain private values that would need to be set
	string getCourseName();

	void setCourseName(string courseName);

	void setGpa(double gpa);

	//getters for the private variables that need to be accessed
	int getCredits();

	void setCredits(int credits);

	double getGpa();


	//functions to be overrided by children
	//function to  calculate the gpa 
	virtual void calcGpa() {}
	//prints the course summary
	virtual void printCourse();


protected:
	//protected variables to be used by its children classes
	string courseName;
	int credits;
	double gpa;
	double exams[20];
	double finals;
};

#endif // !Course