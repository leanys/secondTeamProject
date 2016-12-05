#include "Course.h"
class Phy2049 : public Course {
private:
	//specific grades for this class
	double quizzes[10];
	double homework[13];
	double hittPoints;

public:
	//calculate gpa based on all grades in class
	void calcGpa();
	//setters for the private variables
	void updateExam(int examNum, double score);
	void updateFinal(double score);
	void updateQuiz(int quizNum, double score);
	void updateHomework(int homeworkNum, double score);
	void updateHittPoints(double score);
	void printAll();
	Phy2049();
};