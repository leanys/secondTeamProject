#include "Course.h"

class Phy2048 : public Course {
private:
	//specific grades for physics
	double quizzes[10];
	double homework[13];
	double hittPoints;

public:
	//calculate gpa based on all grades in class
	void calcGpa();
	//setters for private values
	void updateExam(int examNum, double score);
	void updateFinal(double score);
	void updateQuiz(int quizNum, double score);
	void updateHomework(int homeworkNum, double score);
	void updateHittPoints(double score);
	//prints all of the grades for this class
	void printAll();
	//constructor
	Phy2048();
};