//
//  CHM2045.cpp
//  COPTeamProject
//
//  Created by Esteban Gonzalez on 11/12/16.
//  Copyright 2016 Esteban Gonzalez. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include "CHM2045.h"
using namespace std;

//constructor
Chm2045::Chm2045() {
	for (int i = 0; i<20; i++) {
		exams[i] = -1;
	}
	for (int i = 0; i<10; i++) {
		homework[i] = -1;
	}
}
//calcs gpa based on syllabus
//does not add in grades that are -1 which means that they have not been set
void Chm2045::calcGpa() {
	double tempGPA = 0;
	int numexams = 0;
	double avgexams = 0;
	int numhw = 0;
	double avghw = 0;

	for (int i = 0; i<20; i++) {
		if (exams[i] != -1) {
			numexams++;
			avgexams += exams[i];
		}
	}
	for (int i = 0; i<10; i++) {
		if (homework[i] != -1) {
			numhw++;
			avghw += homework[i];
		}
	}

	avgexams = avgexams / numexams;
	avghw = avghw / numhw;


	tempGPA = (avgexams*.6) + (avghw*.1) + (hittPoints*.05) + (finals*.25);

	if (tempGPA >= 90) {
		gpa = 4.0;
	}
	else if (tempGPA >= 86 && tempGPA < 90) {
		gpa = 3.67;
	}
	else if (tempGPA >= 83 && tempGPA < 86) {
		gpa = 3.33;
	}
	else if (tempGPA >= 80 && tempGPA < 83) {
		gpa = 3;
	}
	else if (tempGPA >= 76 && tempGPA < 80) {
		gpa = 2.67;
	}
	else if (tempGPA >= 73 && tempGPA < 76) {
		gpa = 2.33;
	}
	else if (tempGPA >= 70 && tempGPA < 73) {
		gpa = 2;
	}
	else if (tempGPA >= 66 && tempGPA < 70) {
		gpa = 1.33;
	}
	else if (tempGPA >= 63 && tempGPA < 66) {
		gpa = 1;
	}
	else if (tempGPA >= 60 && tempGPA < 63) {
		gpa = 0.67;
	}
	else {
		gpa = 0;
	}
}
//setters for private variables
void Chm2045::updateExam(int examNum, double score) {
	this->exams[examNum] = score;
}

void Chm2045::updateFinal(double score) {
	this->finals = score;
}

void Chm2045::updateHomework(int homeworkNum, double score) {
	this->homework[homeworkNum] = score;
}

void Chm2045::updateHittPoints(double score) {
	this->hittPoints = score;
}
//prints all of the grade values for class
void Chm2045::printAll()
{
	cout << courseName << endl << "Homework: " << endl;
	for (size_t i = 0; i < 10; i++) {
		if (homework[i] >= 0) {
			cout << i + 1 << ". " << homework[i] << endl;
		}
	}
	cout << endl;
	cout << "Hittpoints: " << hittPoints << endl;
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