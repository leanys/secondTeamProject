#include "MAC2312.h"

//constructor initializes everything to -1
MAC2312::MAC2312() {
	hittPoints = -1;
	participation = -1;
	webAssign = -1;
	finals = -1;
	for (int i = 0; i < 20; i++) {
		if (i < 8) {
			quizzes[i] = -1;
			tempQuizzes[i] = -1;
		}
		if (i < 3) {
			writtenHomework[i] = -1;
			tempWrittenHomework[i] = -1;
		}
		exams[i] = -1;
	}
}
//these methods take in a new grade value and change the existing value
void MAC2312::updateHittPoints(double newScore) {
	hittPoints = newScore;
}
void MAC2312::updateWebAssign(double newScore) {
	webAssign = newScore;
}
void MAC2312::updateQuiz(int quizNumber, double newScore) {
	quizzes[quizNumber] = newScore;
	tempQuizzes[quizNumber] = newScore;
}
void MAC2312::updateWrittenHomework(int homeworkNumber, double newScore) {
	writtenHomework[homeworkNumber] = newScore;
	tempWrittenHomework[homeworkNumber] = newScore;
}
void MAC2312::updateParticipation(double newScore) {
	participation = newScore;
}
void MAC2312::updateExam(int examNumber, double newScore) {
	exams[examNumber] = newScore;
}
void MAC2312::updateFinal(double newScore) {
	finals = newScore;
}
//this is a generic thing that adds up the contents of an array and returns the value
double MAC2312::pointSummer(double grades[], int arraySize) {
	double total = 0;
	for (int i = 0; i < arraySize; i++) {
		//this check makes it so only grades that have been entered are added to the total
		if (grades[i] != -1) {
			total += grades[i];
		}
	}
	return total;
}
//this is exactly like point summer except that it takes in an array<T,V> type
double MAC2312::examPointSummer(double examGrades [20]) {
	double total = 0;
	for (size_t i = 0; i < 20; i++) {
		//this check makes it so only grades that have been entered are added to the total
		if (examGrades[i] != -1) {
			total += examGrades[i];
		}
	}
	return total;
}
//this method sorts through the quiz array and finds the index of the two lowest quiz grades
//these two grades are dropped
//and then the rest of the grades are summed and returned as a double
double MAC2312::bestOfQuizzes(double quizzes[]) {
	double bestSum = 0;
	int lowestIndex = 0;
	//finding lowest index
	for (int i = 1; i < 8; i++) {
		if (quizzes[i] < quizzes[lowestIndex]) {
			lowestIndex = i;
		}
	}
	int nextLowest;
	if (lowestIndex == 0) {
		nextLowest = 1;
	}
	else {
		nextLowest = 0;
	}
	//finds 2nd lowest by redoing the check and ignoring the lowest one
	for (int i = 1; i < 8; i++) {
		if (quizzes[i] < quizzes[nextLowest] && i != lowestIndex) {
			nextLowest = i;
		}
	}
	bestSum = pointSummer(quizzes, 8) - quizzes[lowestIndex] - quizzes[nextLowest];
	return bestSum;
}
//This method condenses all the points and then sets the gpa value accordingly
void MAC2312::calcGpa() {
	double totalPoints = 0; //this tracks number of points earned
	double pointDivision = 0; //this will track number of available points based on what has been graded
	if (hittPoints != -1) {
		totalPoints += (hittPoints * 0.35);
		pointDivision += 35;
	}
	if (participation != -1) {
		totalPoints += (participation * 0.04);
		pointDivision += 4;
	}
	//webAssign points max out at 50
	if (webAssign != -1) {
		if ((webAssign * 0.5) > 50) {
			totalPoints += 50;
		}
		else {
			totalPoints += (webAssign * 0.5);
		}
		pointDivision += 50;
	}
	//now figure out how many quiz grades have been entered
	int quizCount = 0;
	for (int i = 0; i < 8; i++) {
		if (quizzes[i] != -1) {
			quizCount++;
		}
	}
	//the if determinse how the quizzes affect the grade
	//because there were a few different cases
	if (quizCount > 6) {
		pointDivision += 36;
		totalPoints += (bestOfQuizzes(quizzes) / 6 * 0.36);
	}
	else if (quizCount > 0 && quizCount < 6) {
		pointDivision += (6 * quizCount);
		totalPoints += (pointSummer(quizzes, 8) / quizCount * 0.36);
	}
	//count entered written homework grades
	int writtenHomeworkCount = 0;
	for (int i = 0; i < 3; i++) {
		if (writtenHomework[i] != -1) {
			writtenHomeworkCount++;
		}
	}
	if (writtenHomeworkCount > 0) {
		pointDivision += (5 * writtenHomeworkCount);
		totalPoints += (pointSummer(writtenHomework, 3) * 0.05);
	}
	//count entered exam grades
	int examCount = 0;
	for (int i = 0; i < 3; i++) {
		if (exams[i] != -1) {
			examCount++;
		}
	}
	if (examCount > 0) {
		pointDivision += (60 * examCount);
		totalPoints += (examPointSummer(exams) * 0.6);
	}
	//final exam
	if (finals != -1) {
		pointDivision += 80;
		totalPoints += (finals * 0.8);
	}
	//makes sure no division by zer0 when finding percentage
	double percentage;
	if (pointDivision != 0) {
		percentage = (totalPoints / pointDivision);
	}
	else {
		//if no grades are in, gpa returns -1, which is what a percentage of -1 will lead to
		percentage = -1;
	}
	//these ifs serve to set the gpa according to the total point value
	if (percentage >= (360.0 / 400.0)) {
		setGpa(4);
	}
	else if (percentage >= (348.0 / 400.0) && totalPoints < (360.0 / 400.0)) {
		setGpa(3.67);
	}
	else if (percentage >= (334.0 / 400.0) && percentage < (348.0 / 400.0)) {
		setGpa(3.33);
	}
	else if (percentage >= (320.0 / 400.0) && percentage < (334.0 / 400.0)) {
		setGpa(3);
	}
	else if (percentage >= (308.0 / 400.0) && percentage < (320.0 / 400.0)) {
		setGpa(2.67);
	}
	else if (percentage >= (294.0 / 400.0) && percentage < (308.0 / 400.0)) {
		setGpa(2.33);
	}
	else if (percentage >= (280.0 / 400.0) && percentage < (294.0 / 400.0)) {
		setGpa(2);
	}
	else if (percentage >= (268.0 / 400.0) && percentage < (280.0 / 400.0)) {
		setGpa(1.67);
	}
	else if (percentage >= (254.0 / 400.0) && percentage < (268.0 / 400.0)) {
		setGpa(1.33);
	}
	else if (percentage >= (240.0 / 400.0) && percentage < (254.0 / 400.0)) {
		setGpa(1);
	}
	else if (percentage >= (228.0 / 400.0) && percentage < (240.0 / 400.0)) {
		setGpa(0.67);
	}
	else if (percentage >= 0 && percentage < (228.0 / 400.0)) {
		setGpa(0);
	}
	else {
		gpa = -1;
	}
}
//prints all of the grades for the course
void MAC2312::printAll()
{
	cout << courseName << endl;
	cout << "Written Homework: " << endl;
	for (size_t i = 0; i < 3; i++) {

		if (tempWrittenHomework[i] >= 0)
		{
			cout << i + 1 << ". " << tempWrittenHomework[i] << endl;
		}

	}
	cout << endl;


	cout << "Participation Points: " << participation << endl;
	cout << endl;

	cout << "Hittpoints: " << hittPoints << endl;
	cout << endl;

	cout << "WebAssign: " << webAssign << endl;
	cout << endl;


	cout << "Quizzes: " << endl;
	for (size_t i = 0; i < 8; i++) {
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