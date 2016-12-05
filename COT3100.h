#include "Course.h"
class Cot3100 : public Course {
public:
	//calcs the gpa based on the exam and final grades
	void calcGpa();
	//setters for private variables
	void updateExam(int examNum, double score);
	void updateFinal(double score);
	//prints the specific grade values
	void printAll();
	//constructor
	Cot3100();
};