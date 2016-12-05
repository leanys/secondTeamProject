#include "MAS3114.h"

MAS3114::MAS3114() {
	participation = -1;
	quiz = -1;
	finals = -1;
	for (int i = 0; i < 30; i++) {
		if (i < 20) {
			exams[i] = -1;
		}
		if (i < 5) {
			projects[i] = -1;
			tempProjects[i] = -1;
		}
		homework[i] = -1;
		tempHomework[i] = -1;
	}
}
//these methods take in a new grade value and change or set the existing value
void MAS3114::updateHomework(int homeworkNumber, double newScore) {
	homework[homeworkNumber] = newScore;
	tempHomework[homeworkNumber] = newScore;
}
void MAS3114::updateProjects(int projectNumber, double newScore) {
	projects[projectNumber] = newScore;
	tempProjects[projectNumber] = newScore;
}
void MAS3114::updateParticipation(double newScore) {
	participation = newScore;
}
void MAS3114::updateQuiz(double newScore) {
	quiz = newScore;
}
void MAS3114::updateExams(int examNumber, double newScore) {
	exams[examNumber] = newScore;
}
//this is a generic thing that adds up the contents of an array and returns the value
double MAS3114::pointSummer(double grades[], int arraySize) {
	double total = 0;
	for (int i = 0; i < arraySize; i++) {
		//this check makes it so only grades that have been entered are added to the total
		if (grades[i] != -1) {
			total += grades[i];
		}
	}
	return total;
}
double MAS3114::examPointSummer(double examGrades[20]) {
	double total = 0;
	for (size_t i = 0; i < 20; i++) {
		//this check makes it so only grades that have been entered are added to the total
		if (examGrades[i] != -1) {
			total += examGrades[i];
		}
	}
	return total;
}
//This method condenses all the points and then sets the gpa value accordingly
void MAS3114::calcGpa() {
	double totalPoints = 0;
	double divider = 0;
	//count number of homeworks entered
	int homeworkCount = 0;
	for (int i = 0; i < 30; i++) {
		if (homework[i] != -1) {
			homeworkCount++;
		}
	}
	if (homeworkCount > 0) {
		totalPoints += ((pointSummer(homework, 30) / homeworkCount) * 0.9);
		divider += 90;
	}
	//count number of projects entered
	int projectCount = 0;
	for (int i = 0; i < 5; i++) {
		if (projects[i] != -1) {
			projectCount++;
		}
	}
	if (projectCount > 0) {
		totalPoints += ((pointSummer(projects, 5) / projectCount) * 1.3);
		divider += 130;
	}
	//count number of exams entered
	int examCount = 0;
	for (int i = 0; i < 20; i++) {
		if (exams[i] != -1) {
			examCount++;
		}
	}
	if (examCount > 0) {
		totalPoints += ((examPointSummer(exams) / examCount) * 2.4);
		divider += 240;
	}
	if (participation != -1) {
		totalPoints += (participation * 0.525);
		divider += 52.5;
	}
	if (quiz != -1) {
		totalPoints += (quiz * 0.6);
		divider += 60;
	}
	double percentage;
	if (divider != 0) {
		percentage = (totalPoints / divider) * 100;
	}
	else {
		percentage = -1;
	}
	//these ifs serve to set the gpa according to the total point value
	//the syllabus based the final grade on percentage so I converted it for the checks
	if (percentage >= 90) {
		gpa = 4.0;
	}
	else if (percentage >= 86 && percentage < 90) {
		gpa = 3.67;
	}
	else if (percentage >= 82 && percentage < 86) {
		gpa = 3.33;
	}
	else if (percentage >= 78 && percentage < 82) {
		gpa = 3;
	}
	else if (percentage >= 74 && percentage < 78) {
		gpa = 2.67;
	}
	else if (percentage >= 70 && percentage < 74) {
		gpa = 2.33;
	}
	else if (percentage >= 66 && percentage < 70) {
		gpa = 2;
	}
	else if (percentage >= 62 && percentage < 66) {
		gpa = 1.67;
	}
	else if (percentage >= 58 && percentage < 62) {
		gpa = 1.33;
	}
	else if (percentage >= 54 && percentage < 58) {
		gpa = 1;
	}
	else if (percentage >= 50 && percentage < 54) {
		gpa = 0.67;
	}
	else if (percentage >= 0 && percentage < 50) {
		gpa = 0;
	}
	else {
		gpa = -1;
	}
}
//prints all of the grade values for the course
void MAS3114::printAll()
{

	cout << "MAS311" << endl;

	cout << "Homework: " << endl;
	for (size_t i = 0; i < 30; i++) {

		if (tempHomework[i] >= 0)
		{
			cout << i + 1 << ". " << tempHomework[i] << endl;
		}

	}

	cout << endl;
	cout << "Participation Points: " << participation << endl;
	cout << endl;

	cout << endl;
	cout << "Quiz: " << quiz << endl;
	cout << endl;


	cout << "Projects: " << endl;
	for (size_t i = 0; i < 5; i++) {
		if (tempProjects[i] >= 0)
		{
			cout << i + 1 << ". " << tempProjects[i] << endl;
		}

	}

	cout << endl;
	cout << "Exams: " << endl;

	for (size_t i = 0; i < 20; i++) {
		if (exams[i] >= 0)
		{
			cout << i + 1 << ". " << exams[i] << endl;
		}

	}
	cout << endl;


}