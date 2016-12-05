#include "MAC2311.h"
#include <iostream>

//constructor initializes everything to -1
MAC2311::MAC2311() {
	hittPoints = -1;
	finals = -1;
	for (int i = 0; i < 20; i++) {
		if (i < 13) {
			webAssign[i] = -1;
			webAssignPrint[i] = -1;
		}
		if (i < 10) {
			quizzes[i] = -1;
			quizzesPrint[i] = -1;
		}
		if (i < 5) {
			writtenHomework[i] = -1;
			writtenHomeworkPrint[i] = -1;
		}
		if (i < 20) {
			examsPrint[i] = -1;
		}
		exams[i] = -1;
	}
}
//these methods take in a new grade value and change or set the existing value
void MAC2311::updateHittPoints(double newScore) {
	hittPoints = newScore;
}
void MAC2311::updateWebAssign(int assignmentNumber, double newScore) {
	webAssign[assignmentNumber] = newScore;
	webAssignPrint[assignmentNumber] = newScore;
}
void MAC2311::updateQuiz(int quizNumber, double newScore) {
	quizzes[quizNumber] = newScore;
	quizzesPrint[quizNumber] = newScore;
}
void MAC2311::updateWrittenHomework(int assignmentNumber, double newScore) {
	writtenHomework[assignmentNumber] = newScore;
	writtenHomeworkPrint[assignmentNumber] = newScore;
}
void MAC2311::updateExam(int examNumber, double newScore) {
	exams[examNumber] = newScore;
	examsPrint[examNumber] = newScore;
}
void MAC2311::updateFinal(double newScore) {
	finals = newScore;
}
//this method replaces the lowest exam grade with final exam grade if final is higher
void MAC2311::examReplace(double examGrades [20], double finals) {
	int lowestIndex = 0;
	//this part finds the index of the lowest exam grade
	for (int i = 1; i < 3; i++) {
		if (examGrades[i] < examGrades[lowestIndex]) {
			lowestIndex = i;
		}
	}
	//this part compares final exam grade to the lowest exam grade
	//if final is higher it replaces the lowest exam grade
	if (finals > examGrades[lowestIndex]) {
		examGrades[lowestIndex] = finals;
	}
}
//this is a generic thing that adds up the contents of an array and returns the value
//it is used in pretty much every course gpa calculation
double MAC2311::pointSummer(double grades[], int arraySize) {
	double total = 0;
	for (int i = 0; i < arraySize; i++) {
		//this check makes it so only grades that have been entered are added to the total
		if (grades[i] != -1) {
			total += grades[i];
		}
	}
	return total;
}
//this is exactly like pointSummer except that it takes in an array<T, V> type
double MAC2311::examPointSummer(double examGrades [20]) {
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
double MAC2311::bestOfQuizzes(double quizzes[]) {
	double bestSum = 0;
	int lowestIndex = 0;
	//finding lowest index
	for (int i = 1; i < 10; i++) {
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
	for (int i = 1; i < 10; i++) {
		if (quizzes[i] < quizzes[nextLowest] && i != lowestIndex) {
			nextLowest = i;
		}
	}
	bestSum = pointSummer(quizzes, 10) - quizzes[lowestIndex] - quizzes[nextLowest];
	return bestSum;
}
//this method acts the same way as the one above, but it only finds the lowest homework grade
//and drops it before returning the sum of the rest of them
double MAC2311::bestOfWrittenHomework(double writtenHomework[]) {
	double bestSum = 0;
	int lowestIndex = 0;
	for (int i = 1; i < 5; i++) {
		if (writtenHomework[i] < writtenHomework[lowestIndex]) {
			lowestIndex = i;
		}
	}
	if (writtenHomework[lowestIndex] == -1) {
		bestSum = pointSummer(writtenHomework, 5);
	}
	else {
		bestSum = pointSummer(writtenHomework, 5) - writtenHomework[lowestIndex];
	}
	return bestSum;
}
//this method was made to deal with webassign because it's weird
//since we don't know the point values for the individual assignments
//so these grades are taken as percentages, averaged, and that average is projected onto the total possible point value later on
double MAC2311::webAssignCalculator(double webAssign[]) {
	//find number of grades that have been entered
	double points;
	int count = 0;
	for (int i = 0; i < 13; i++) {
		if (webAssign[i] != -1) {
			count++;
		}
	}
	//makes sure it never divides by zero
	//if there are no webassign grades it returns -1
	if (count != 0) {
		points = ((pointSummer(webAssign, 13) / count) / 100) * 50;
	}
	else {
		points = -1;
	}
	return points;
}
//This method condenses all the points and then sets the gpa value accordingly
void MAC2311::calcGpa() {
	double totalPoints = 0; //this tracks number of points earned
	double pointDivision = 0; //this will track number of available points based on what has been graded
							  //webAssign points max out at 50
							  //for webassign, take in each grade as percentage, then use average percentage to calculate total points out of 50
							  //the if statements determine how the various grades affect the total, depending on which ones have been graded
	if (webAssignCalculator(webAssign) != -1) {
		totalPoints += webAssignCalculator(webAssign);
		pointDivision += 50;

	}
	if (hittPoints != -1) {
		totalPoints += (hittPoints * 0.4);
		pointDivision += 40;
	}
	//now figure out how many quiz grades have been entered
	int quizCount = 0;
	for (int i = 0; i < 10; i++) {
		if (quizzes[i] != -1) {
			quizCount++;
		}
	}
	//the if determinse how the quizzes affect the grade
	//because there were a few different cases
	if (quizCount > 8) {
		pointDivision += 48;
		totalPoints += (bestOfQuizzes(quizzes) / 8 * 0.48);
	}
	else if (quizCount > 0 && quizCount < 8) {
		pointDivision += (6 * quizCount);
		totalPoints += (pointSummer(quizzes, 10) / quizCount * 0.48);
	}
	//same but for written homework
	int writtenHomeworkCount = 0;
	for (int i = 0; i < 5; i++) {
		if (writtenHomework[i] != -1) {
			writtenHomeworkCount++;
		}
	}
	if (writtenHomeworkCount == 5) {
		pointDivision += 12;
		totalPoints += (bestOfWrittenHomework(writtenHomework) / 4 * 0.12);

	}
	else if (writtenHomeworkCount > 0 && writtenHomeworkCount < 5) {
		pointDivision += (3 * writtenHomeworkCount);
		totalPoints += (pointSummer(writtenHomework, 5) / writtenHomeworkCount * 0.12);
	}
	//count entered exam grades
	int examCount = 0;
	for (int i = 0; i < 3; i++) {
		if (exams[i] != -1) {
			examCount++;
		}
	}
	//if there is a final exam grade and at least one regular exam grade we can do this
	if (finals != -1 && examCount != 0) {
		examReplace(exams, finals);
	}
	if (examCount > 0) {
		pointDivision += (75 * examCount);
		(totalPoints += examPointSummer(exams) * 0.75);

	}
	if (finals != -1) {
		pointDivision += 75;
		totalPoints += (finals * 0.75);

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


	//these ifs serve to set the gpa according to the total point value converted to a percentage
	if (percentage >= (405.0 / 450.0)) {
		//I changed these to use the setGPA function when I was debugging
		//not sure if it is needed but it works like this so it shall remain
		setGpa(4);
	}
	else if (percentage >= (390.0 / 450.0) && percentage < (405.0 / 450.0)) {
		setGpa(3.67);
	}
	else if (percentage >= (375.0 / 450.0) && percentage < (390.0 / 450.0)) {
		setGpa(3.33);
	}
	else if (percentage >= (360.0 / 450.0) && percentage < (375.0 / 450.0)) {
		setGpa(3);
	}
	else if (percentage >= (345.0 / 450.0) && percentage < (360.0 / 450.0)) {
		setGpa(2.67);
	}
	else if (percentage >= (325.0 / 450.0) && percentage < (345.0 / 450.0)) {
		setGpa(2.33);
	}
	else if (percentage >= (305.0 / 450.0) && percentage < (325.0 / 450.0)) {
		setGpa(2);
	}
	else if (percentage >= (290.0 / 450.0) && percentage < (305.0 / 450.0)) {
		setGpa(1.67);
	}
	else if (percentage >= (275.0 / 450.0) && percentage < (290.0 / 450.0)) {
		setGpa(1.33);
	}
	else if (percentage >= (260.0 / 450.0) && percentage < (275.0 / 450.0)) {
		setGpa(1);
	}
	else if (percentage >= (245.0 / 450.0) && percentage < (260.0 / 450.0)) {
		setGpa(0.67);
	}
	else if (percentage >= 0 && percentage < (245.0 / 450.0)) {
		setGpa(0);
	}
	else {
		setGpa(-1);
	}
}
//prints all the grades for the course
void MAC2311::printAll()
{
	cout << courseName << endl;
	cout << "Hittpoints: " << hittPoints << endl;
	cout << endl;

	cout << "WebAssign: " << endl;
	for (size_t i = 0; i < 13; i++) {
		if (webAssignPrint[i] >= 0) {
			cout << i + 1 << ". " << webAssignPrint[i] << endl;
		}
	}
	cout << endl;

	cout << "Quizzes: " << endl;
	for (size_t i = 0; i < 10; i++) {
		if (quizzesPrint[i] >= 0) {
			cout << i + 1 << ". " << quizzesPrint[i] << endl;
		}
	}
	cout << endl;

	cout << "Written Homework: " << endl;
	for (size_t i = 0; i < 5; i++) {
		if (writtenHomeworkPrint[i] >= 0) {
			cout << i + 1 << ". " << writtenHomeworkPrint[i] << endl;
		}
	}

	cout << "Exams: " << endl;
	for (size_t i = 0; i < 20; i++) {
		if (examsPrint[i] >= 0) {
			cout << i + 1 << ". " << examsPrint[i] << endl;
		}
	}


	cout << endl;
	cout << "Finals: " << finals << endl;
	cout << endl;

}