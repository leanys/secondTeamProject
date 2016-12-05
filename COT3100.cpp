//
//  COT3100.cpp
//  COPTeamProject
//
//  Created by Esteban Gonzalez on 11/12/16.
//  Copyright 2016 Esteban Gonzalez. All rights reserved.
//

#include <stdio.h>
#include <string>

#include <iostream>
#include "COT3100.h"

using namespace std;


//constructor
Cot3100::Cot3100() {
	for (int i = 0; i<20; i++) {
		exams[i] = -1;
	}
}

//calcs gpa based on syllabus
//does not add in grades that are -1 which means that they have not been set
void Cot3100::calcGpa() {
	double tempGPA = 0;
	int numexams = 0;
	double avgexam = 0;
	for (int i = 0; i<4; i++) {
		if (exams[i] != -1) {
			numexams++;
			avgexam += exams[i];
		}
	}
	avgexam = avgexam / numexams;
	tempGPA = (avgexam*.72) + (finals*.28);

	if (tempGPA >= 93) {
		gpa = 4.0;
	}
	else if (tempGPA >= 90 && tempGPA < 93) {
		gpa = 3.67;
	}
	else if (tempGPA >= 87 && tempGPA < 90) {
		gpa = 3.33;
	}
	else if (tempGPA >= 83 && tempGPA < 87) {
		gpa = 3;
	}
	else if (tempGPA >= 80 && tempGPA < 83) {
		gpa = 2.67;
	}
	else if (tempGPA >= 77 && tempGPA < 80) {
		gpa = 2.33;
	}
	else if (tempGPA >= 73 && tempGPA < 77) {
		gpa = 2;
	}
	else if (tempGPA >= 70 && tempGPA < 73) {
		gpa = 1.67;
	}
	else if (tempGPA >= 67 && tempGPA < 70) {
		gpa = 1.33;
	}
	else if (tempGPA >= 63 && tempGPA < 67) {
		gpa = 1;
	}
	else if (tempGPA >= 60 && tempGPA < 63) {
		gpa = 0.67;
	}
	else {
		gpa = 0;
	}
}
//setters for the private variables
void Cot3100::updateExam(int examNum, double score) {
	this->exams[examNum] = score;
}

void Cot3100::updateFinal(double score) {
	this->finals = score;
}
//prints all of the grade values for the class
void Cot3100::printAll()
{
	cout << courseName << endl << "Exams: " << endl;
	for (size_t i = 0; i < 20; i++) {
		if (exams[i] >= 0) {
			cout << i + 1 << ". " << exams[i] << endl;
		}
	}
	cout << endl;
	cout << "Finals: " << finals << endl;
	cout << endl;

}