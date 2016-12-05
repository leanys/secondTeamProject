//
//  COP3502.cpp
//  COPTeamProject
//
//  Created by Esteban Gonzalez on 11/12/16.
//  Copyright 2016 Esteban Gonzalez. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include "COP3502.h"

using namespace std;


//constructor
COP3502::COP3502() {
	for (int i = 0; i<20; i++) {
		exams[i] = -1;
	}
	for (int i = 0; i<10; i++) {
		labs[i] = -1;
		homework[i] = -1;
	}
	for (int i = 0; i<3; i++) {
		progAssignments[i] = -1;
	}
}

//calcs gpa based on syllabus
//does not add in grades that are -1 which means that they have not been set
void COP3502::calcGpa() {
	double tempGPA;
	int numHW = 0;
	double avgHW = 0;
	int numProg = 0;
	double avgProg = 0;

	int numLabs = 0;
	double avgLabs = 0;
	double lablowest = 100;
	double labsecondlowest = 100;

	int numexams = 0;
	double avgexams = 0;

	for (int i = 0; i<10; i++) {
		if (homework[i] != -1) {
			numHW++;
			avgHW += homework[i];
		}
	}
	for (int i = 0; i < 3; i++) {
		if (progAssignments[i] != -1) {
			numProg++;
			avgProg += progAssignments[i];
		}
	}
	for (int i = 0; i<10; i++) {
		if (labs[i] != -1) {
			numLabs++;
			avgLabs += labs[i];
			if (labs[i]<lablowest && labs[i] == 100) {
				labsecondlowest = lablowest;
				lablowest = labs[i];
			}
			else if (labs[i]<lablowest) {
				lablowest = labs[i];
			}
			else if (labs[i]<labsecondlowest) {
				labsecondlowest = labs[i];
			}
		}
	}
	for (int i = 0; i<20; i++) {
		if (exams[i] != -1) {
			numexams++;
			avgexams += exams[i];
		}
	}

	avgHW = avgHW / numHW;
	avgProg = avgProg / numProg;
	avgLabs = avgLabs / numLabs;
	avgexams = avgexams / numexams;

	tempGPA = (avgHW*.20) + (avgProg*.20) + (avgLabs*.1) + (avgexams*.5);

	if (tempGPA >= 95) {
		gpa = 4.0;
	}
	else if (tempGPA >= 90 && tempGPA < 94) {
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
void COP3502::updateExam(int examNum, double score) {
	this->exams[examNum] = score;
}

void COP3502::updateFinal(double score) {
	this->finals = score;
}

void COP3502::updateHomework(int HWNum, double score) {
	this->homework[HWNum] = score;
}

void COP3502::updateLab(int labNum, double score) {
	this->labs[labNum] = score;
}

void COP3502::updateProgAssignments(int progNum, double score) {
	this->progAssignments[progNum] = score;
}
//prints all of the grade values for the class
void COP3502::printAll()
{
	cout << courseName << endl << "Homework: " << endl;
	for (size_t i = 0; i < 10; i++) {
		if (homework[i] >= 0) {
			cout << i + 1 << ". " << homework[i] << endl;
		}
	}
	cout << endl;
	cout << "Programming Assignments: " << endl;
	for (size_t i = 0; i < 3; i++) {
		if (progAssignments[i] >= 0) {
			cout << i + 1 << ". " << progAssignments[i] << endl;
		}
	}
	cout << endl;
	cout << "Labs: " << endl;
	for (size_t i = 0; i < 10; i++) {
		if (labs[i] >= 0) {
			cout << i + 1 << ". " << labs[i] << endl;
		}
	}
	cout << endl;
	cout << "Exams: " << endl;
	for (size_t i = 0; i < 20; i++) {
		if (exams[i] >= 0) {
			cout << i + 1 << ". " << exams[i] << endl;
		}
	}
	cout << endl;
	cout << "Finals: " << finals << endl;
	cout << endl;

}