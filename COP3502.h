#include "Course.h"

class COP3502 : public Course {
	//specific grades to this class
private:
	double homework[10];
	double progAssignments[3];
	double labs[10];


public:
	//calculate gpa based on all grades in class
	void calcGpa();
	//setters for the class's private variables
	void updateExam(int examNum, double score);
	void updateFinal(double score);
	void updateHomework(int homeworkNum, double score);
	void updateLab(int hittNum, double score);
	void updateProgAssignments(int progNum, double score);
	//prints the specific grade values for this class
	void printAll();
	//constructor
	COP3502();
};