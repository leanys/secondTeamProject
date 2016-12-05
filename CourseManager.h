#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include <algorithm>
#include "Course.h"

using namespace std;

class CourseManager {
private:
	//private variables to keep track of the courses
	list<Course> courses[20];
	double totalGradePoints;
	double overallGPA;
	int overallCreditHours;

public:
	//constructor that sets private number variables to 0
	CourseManager() : totalGradePoints(0), overallGPA(0), overallCreditHours(0) {}
	//adds a course
	void addCourse(Course course);
	//deletes a course
	void deleteCourse(string courseName);
	//prints the course summaries
	void printCourses();
	//getter for gpa
	double getGpa();
	//calculates the overall gpa
	double calcOverallGPA();
	//returns a course when given the course name
	//if no course found, it returns an empty string
	Course* search(string courseName);
	//returns a course at a specific index
	//if no course found, it returns an empty string
	Course* findAt(int position);
	//returns if there are any courses in courses[]
	bool empty();
};