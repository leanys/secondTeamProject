#include "Course.h"

//specific chem course
class Chm2045 : public Course {
	//specific private variables
private:
	double homework[10];
	double hittPoints;

public:
	//calculate gpa based on all grades in class
	void calcGpa();
	//setters for each specific variables
	void updateExam(int examNum, double score);
	void updateFinal(double score);
	void updateHomework(int homeworkNum, double score);
	void updateHittPoints(double score);
	//prints the values of each individual grade
	void printAll();
	//constructor
	Chm2045();
};