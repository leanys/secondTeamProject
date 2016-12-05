#include "COP3503.h"

//constructor initializes everything to -1
COP3503::COP3503() {
	groupProject = -1;
	for (int i = 0; i < 20; i++) {
		if (i < 3) {
			assignments[i] = -1;
			tempAssignments[i] = -1;
		}
		exams[i] = -1;
	}
}
//these methods take in a new grade value and change or set the existing value
void COP3503::updateAssignments(int assignmentNumber, double newScore) {
	assignments[assignmentNumber] = newScore;
	tempAssignments[assignmentNumber] = newScore;
}
void COP3503::updateGroupProject(double newScore) {
	groupProject = newScore;
}
void COP3503::updateExams(int examNumber, double newScore) {
	exams[examNumber] = newScore;
}
//this is a generic thing that adds up the contents of an array and returns the value
double COP3503::pointSummer(double grades[], int arraySize) {
	double total = 0;
	for (int i = 0; i < arraySize; i++) {
		total += grades[i];
	}
	return total;
}
double COP3503::examPointSummer(double examGrades[20]) {
	double total = 0;
	for (size_t i = 0; i < 20; i++) {
		//this check makes it so only grades that have been entered are added to the total
		if (examGrades[i] != -1) {
			total += examGrades[i];
		}
	}
	return total;
}
//This method condenses all the points as percentages and then sets the gpa value accordingly
//calcs gpa based on syllabus
//does not add in grades that are -1 which means that they have not been set
void COP3503::calcGpa() {
	double percentage = 0;
	double divisor = 0;
	//count assignment grades
	int assignmentCount = 0;
	for (int i = 0; i < 3; i++) {
		if (assignments[i] != -1) {
			assignmentCount++;
		}
	}
	if (assignmentCount != -1) {
		percentage += ((pointSummer(assignments, 3) / assignmentCount) * 0.3);
		divisor += 30;
	}
	//count exam grades
	int examCount = 0;
	for (int i = 0; i < 2; i++) {
		if (exams[i] != -1) {
			examCount++;
		}
	}
	if (examCount != -1) {
		percentage += ((examPointSummer(exams) / examCount) * 0.4);
		divisor += 40;
	}
	if (groupProject != -1) {
		percentage += (groupProject * 0.3);
		divisor += 30;
	}
	if (divisor != 0) {
		percentage /= divisor;
		percentage *= 100;
	}
	else {
		percentage = -1;
	}
	//these ifs serve to set the gpa according to the total percentage value
	if (percentage >= 93) {
		gpa = 4.0;
	}
	else if (percentage >= 90 && percentage < 93) {
		gpa = 3.67;
	}
	else if (percentage >= 87 && percentage < 90) {
		gpa = 3.33;
	}
	else if (percentage >= 83 && percentage < 87) {
		gpa = 3;
	}
	else if (percentage >= 80 && percentage < 83) {
		gpa = 2.67;
	}
	else if (percentage >= 77 && percentage < 80) {
		gpa = 2.33;
	}
	else if (percentage >= 73 && percentage < 77) {
		gpa = 2;
	}
	else if (percentage >= 70 && percentage < 73) {
		gpa = 1.67;
	}
	else if (percentage >= 67 && percentage < 70) {
		gpa = 1.33;
	}
	else if (percentage >= 63 && percentage < 67) {
		gpa = 1;
	}
	else if (percentage >= 60 && percentage < 63) {
		gpa = 0.67;
	}
	else if (percentage >= 0 && percentage < 60) {
		gpa = 0;
	}
	else {
		gpa = -1;
	}
}
//prints all of the grade values for the class
void COP3503::printAll()
{

	cout << "COP3503" << endl;

	cout << "Group Project : " << groupProject << endl;
	cout << endl;

	cout << "Programming Assignments : " << endl;
	for (size_t i = 0; i < 3; i++) {
		if (tempAssignments[i] >= 0)
		{
			cout << i + 1 << ". " << tempAssignments[i] << endl;
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