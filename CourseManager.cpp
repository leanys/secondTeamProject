#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include <algorithm>
#include "CourseManager.h"

using namespace std;

//used for the areEqualCourses to keep track of the course being compared to
//when being passed as a predicate
string currentCourse;

//used to convert all aphanumeric characters to their lower case versions
void toLower(string& str) {
	for (int i = 0, length = str.size(); i < length; i++) {
		if (str[i] > 64 && str[i] < 90) {
			str[i] = tolower(str[i]);
		}
	}
}

//determines if two courses have equal names case insensitive
bool areEqualCourses(Course item) {
	string itemName = item.getCourseName();
	toLower(itemName);

	toLower(currentCourse);

	return itemName.compare(currentCourse) == 0;
}

//adds a course if it is not already there
void CourseManager::addCourse(Course course) {
	Course *retCourse = search(course.getCourseName());
	if (retCourse->getCourseName().compare("") == 0) {
		courses->push_back(course);
	}
	else {
		//informs the user if the course cannot be added
		cout << "Cannot add course." << endl << endl;
	}
}

//deletes the course with the course name passed in
void CourseManager::deleteCourse(string courseName) {
	currentCourse = courseName;
	courses->remove_if(areEqualCourses);
}

//prints summary of all the courses and the overall gpa
void CourseManager::printCourses() {
	double gpa = calcOverallGPA();
	if (gpa < 0) {
		cout << "Your overall GPA: N/A" << endl;
	}
	else {
		cout << "Your overall GPA: " << calcOverallGPA() << endl;
	}
	cout << "Your courses:" << endl;
	list<Course>::iterator itr;
	int count = 1;
	for (itr = courses->begin(); itr != courses->end(); itr++) {
		cout << count++ << ". ";
		Course printCourse = *itr;
		printCourse.printCourse();
	}
}

//getter for the overalGPA
double CourseManager::getGpa() {
	return overallGPA;
}

//calculates the overalGPA for the courses in courses[]
double CourseManager::calcOverallGPA() {
	overallCreditHours = 0;
	overallGPA = 0;
	totalGradePoints = 0;
	list<Course>::iterator itr;
	for (itr = courses->begin(); itr != courses->end(); itr++) {
		Course course = *itr;
		if (course.getGpa() >= 0) {
			overallCreditHours += course.getCredits();
			totalGradePoints += course.getCredits() * course.getGpa();
		}
	}
	if (overallCreditHours == 0) {
		overallGPA = -1;
	}
	else {
		overallGPA = totalGradePoints / overallCreditHours;
	}
	return overallGPA;
}

//searches for a course with the course name given
//if a course with the name is found, it returns a pointer to that course
//if not, it returns a course with an empty string for a name
Course* CourseManager::search(string courseName) {
	currentCourse = courseName;
	if (courses->empty())
	{
		Course* retCourse = new Course();
		retCourse->setCourseName("");

		return retCourse;
	}

	list<Course>::iterator findIter = find_if(courses->begin(), courses->end(), areEqualCourses);

	if (findIter == courses->end()) {
		Course* retCourse = new Course();
		retCourse->setCourseName("");

		return retCourse;
	}
	else {
		return &*findIter;
	}
}

//finds a course at a given index
//if it finds a course, it returns a pointer to that course
//else it returns a course with an empty string for a name
Course* CourseManager::findAt(int position) {
	int count = 0;

	list<Course>::iterator itr;
	for (itr = courses->begin(); itr != courses->end(); itr++) {
		if (count++ == position) {
			return &*itr;
		}
	}

	Course* retCourse = new Course();
	retCourse->setCourseName("");
	return retCourse;
}

//returns if there are no courses in courses[]
bool CourseManager::empty() {
	return courses->empty();
}