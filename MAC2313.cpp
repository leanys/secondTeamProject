#include "MAC2313.h"

//constructor initializes everything to -1
MAC2313::MAC2313() {
	participation = -1;
	finals = -1;
	for (int i = 0; i < 27; i++) {
		if (i < 20) {
			exams[i] = -1;
		}
		if (i < 13) {
			quizzes[i] = -1;
			tempQuizzes[i] = -1;
		}
		webAssign[i] = -1;
		tempWebAssign[i] = -1;
	}
}
//these methods take in a new grade value and change or set the existing value
void MAC2313::updateParticipation(double newScore) {
	participation = newScore;
}
void MAC2313::updateWebAssign(int assignmentNumber, double newScore) {
	webAssign[assignmentNumber] = newScore;
	tempWebAssign[assignmentNumber] = newScore;
}
void MAC2313::updateQuiz(int quizNumber, double newScore) {
	quizzes[quizNumber] = newScore;
	tempQuizzes[quizNumber] = newScore;
}
void MAC2313::updateExam(int examNumber, double newScore) {
	exams[examNumber] = newScore;
}
void MAC2313::updateFinal(double newScore) {
	finals = newScore;
}
//this is a generic thing that adds up the contents of an array and returns the value
double MAC2313::pointSummer(double grades[], int arraySize) {
	double total = 0;
	for (int i = 0; i < arraySize; i++) {
		//this check makes it so only grades that have been entered are added to the total
		if (grades[i] != -1) {
			total += grades[i];
		}
	}
	return total;
}
double MAC2313::examPointSummer(double examGrades[20]) {
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
void MAC2313::calcGpa() {
	double percentage = 0;
	double divider = 0;
	if (participation != -1) {
		percentage += (participation * 0.05);
		divider += 5.0;
	}
	//count number of entered web assign grades
	int webAssignCount = 0;
	for (int i = 0; i < 27; i++) {
		if (webAssign[i] != -1) {
			webAssignCount++;
		}
	}
	if (webAssignCount > 0) {
		percentage += ((pointSummer(webAssign, 27) / webAssignCount) * 0.125);
		divider += 12.5;
	}
	//count quizzes entered
	int quizCount = 0;
	for (int i = 0; i < 13; i++) {
		if (quizzes[i] != -1) {
			quizCount++;
		}
	}
	if (quizCount > 0) {
		percentage += ((pointSummer(quizzes, 13) / quizCount) * 0.125);
		divider += 12.5;
	}
	//count exams
	int examCount = 0;
	for (int i = 0; i < 20; i++) {
		if (exams[i] != -1) {
			examCount++;
		}
	}
	if (examCount > 0) {
		percentage += ((examPointSummer(exams) / examCount) * 0.5);
		divider += 50;
	}
	if (finals != -1) {
		percentage += (finals * 0.2);
		divider += 20;
	}
	if (divider != 0) {
		percentage /= divider;
		percentage *= 100;
	}
	else {
		percentage = -1;
	}
	//these ifs serve to set the gpa according to the total percentage value
	//Keeran does not do minus grades apparently, which is why this one is shorter than the others
	if (percentage >= 90) {
		gpa = 4.0;
	}
	else if (percentage >= 87 && percentage < 90) {
		gpa = 3.33;
	}
	else if (percentage >= 80 && percentage < 87) {
		gpa = 3;
	}
	else if (percentage >= 77 && percentage < 80) {
		gpa = 2.33;
	}
	else if (percentage >= 70 && percentage < 77) {
		gpa = 2;
	}
	else if (percentage >= 67 && percentage < 70) {
		gpa = 1.33;
	}
	else if (percentage >= 60 && percentage < 67) {
		gpa = 1;
	}
	else if (percentage >= 0 && percentage < 60) {
		gpa = 0;
	}
	else {
		gpa = -1;
	}
}
//prints all of the grades for the course
void MAC2313::printAll()
{
	cout << courseName << endl;
	cout << "Participation Points: " << participation << endl;
	cout << endl;

	cout << "WebAssign: " << endl;
	for (size_t i = 0; i < 27; i++) {
		if (tempWebAssign[i] >= 0)
		{
			cout << i + 1 << ". " << tempWebAssign[i] << endl;
		}

	}
	cout << endl;

	cout << "Quizzes: " << endl;
	for (size_t i = 0; i < 13; i++) {
		if (tempQuizzes[i] >= 0)
		{
			cout << i + 1 << ". " << tempQuizzes[i] << endl;
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
	cout << "Finals: " << finals << endl;
	cout << endl;

}