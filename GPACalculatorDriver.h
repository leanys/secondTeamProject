#ifndef GPACALCULATORDRIVER
#define GPACALCULATORDRIVERusing namespace std;

#pragma region fields
//These are the fields that the header file uses
//Each special course is stored here
//The course manager stores representations of these courses along with the
//custom courses and previous gpa info
InputValidator iv;
CourseManager cm;
Phy2048 phy2048;
Phy2049 phy2049;
Cot3100 cot3100;
COP3502 cop3502;
Chm2045 chm2045;
MAC2311 mac2311;
MAC2312 mac2312;
MAC2313 mac2313;
MAS3114 mas3114;
COP3503 cop3503;

#pragma endregion

#pragma region helper functions

#pragma region input getters

//This returns an instance of input validator
InputValidator getInputValidator() {
	return iv;
}

//The following getters have checks to make sure that the input is valid
//This gets a gpa value from user
double getGPA() {
	double inputPreviousGPA = -1;

	do {
		cout << "Please enter GPA: " << endl;
		inputPreviousGPA = iv.getDouble();

		if (inputPreviousGPA < 0 || inputPreviousGPA > 4) {
			cout << "GPA must be between 0.0 and 4.0" << endl;
		}
		cout << endl;
	} while (inputPreviousGPA < 0 || inputPreviousGPA > 4);

	return inputPreviousGPA;
}

//gets a credit hours value from user
int getCreditHours() {
	int inputCreditHours = -1;

	do {
		cout << "Please enter the amount of credit hours: " << endl;
		inputCreditHours = iv.getInt();
		if (inputCreditHours < 0) {
			cout << "The number of credit hours must be 0 or greater" << endl;
		}
		cout << endl;
	} while (inputCreditHours <= 0);

	return inputCreditHours;
}

//gets a string for the course name
string getCourseName() {
	string courseName = "";

	do {
		cout << "Please enter the name of the course: " << endl;

		courseName = iv.getString();

		if (courseName.empty()) {
			cout << "Invalid course name: " << courseName.c_str() << endl;
		}
		cout << endl;
	} while (courseName.empty());

	return courseName;
}

//gets a final grade value from user
double getFinalGrade() {
	//we introduce a bug if the grade is 0
	cout << "Please enter the grade for the final:" << endl;
	double finalGrade = -1;

	while (finalGrade < 0) {
		finalGrade = iv.getDouble();
		if (finalGrade < 0) {
			cout << "Grade must be 0 or greater" << endl;
		}
		cout << endl;
	}
	return finalGrade;
}

//gets an exam grade value from user
//the parameter is to output which exam
double getExamGrade(int examNum) {
	cout << "Please enter the grade for exam " << examNum << endl;
	double examGrade = -1;

	while (examGrade < 0) {
		examGrade = iv.getDouble();
		if (examGrade < 0) {
			cout << "Grade must be 0 or greater" << endl;
		}
		cout << endl;
	}

	return examGrade;
}

//gets a quiz grade value from the user
//the parameter is to output which quiz
double getQuizGrade(int quizNum) {
	cout << "Please enter the grade for quiz " << quizNum << endl;
	double quizGrade = -1;

	while (quizGrade < 0) {
		quizGrade = iv.getDouble();
		if (quizGrade < 0) {
			cout << "Grade must be 0 or greater" << endl;
		}
		cout << endl;
	}

	return quizGrade;
}

//gets a single quiz grade value from the user
double getQuizGrade() {
	cout << "Please enter the grade for your quiz:" << endl;
	double quizGrade = -1;

	while (quizGrade < 0) {
		quizGrade = iv.getDouble();
		if (quizGrade < 0) {
			cout << "Grade must be 0 or greater" << endl;
		}
		cout << endl;
	}

	return quizGrade;
}

//gets a homework grade value from the user
//the parameter is to output which homework
double getHomeworkGrade(int homeworkNum) {
	cout << "Please enter the grade for homework " << homeworkNum << endl;
	double homeworkGrade = -1;

	while (homeworkGrade < 0) {
		homeworkGrade = iv.getDouble();
		if (homeworkGrade < 0) {
			cout << "Grade must be 0 or greater" << endl;
		}
		cout << endl;
	}

	return homeworkGrade;
}

//gets a hitt grade from the user
double getHittGrade() {
	//we introduce a bug if the grade is 0
	cout << "Please enter the grade for your hitt clicker points:" << endl;
	double hittGrade = -1;

	while (hittGrade < 0) {
		hittGrade = iv.getDouble();
		if (hittGrade < 0) {
			cout << "Grade must be 0 or greater" << endl;
		}
		cout << endl;
	}
	return hittGrade;
}

//gets a quiz grade value from the user
//the parameter is to output which exam
double getProgrammingAssignmentGrade(int paNum) {
	//we introduce a bug if the grade is 0
	cout << "Please enter the grade for programming assignment " << paNum << ":" << endl;
	double paGrade = -1;

	while (paGrade < 0) {
		paGrade = iv.getDouble();
		if (paGrade < 0) {
			cout << "Grade must be 0 or greater" << endl;
		}
		cout << endl;
	}
	return paGrade;
}

//gets a lab grade value from the user
//the parameter is to output wich lab
double getLabGrade(int labNum) {
	//we introduce a bug if the grade is 0
	cout << "Please enter the grade for your lab number " << labNum << ":" << endl;
	double labGrade = -1;

	while (labGrade < 0) {
		labGrade = iv.getDouble();
		if (labGrade < 0) {
			cout << "Grade must be 0 or greater" << endl;
		}
		cout << endl;
	}
	return labGrade;
}

//gets a web assign grade from the user
//the parameter is to output whcih web assign
double getWebAssignGrade(int waNum) {
	//we introduce a bug if the grade is 0
	cout << "Please enter the grade for your web assign number " << waNum << ":" << endl;
	double waGrade = -1;

	while (waGrade < 0) {
		waGrade = iv.getDouble();
		if (waGrade < 0) {
			cout << "Grade must be 0 or greater" << endl;
		}
		cout << endl;
	}
	return waGrade;
}

//gets a single web assign grade from the user
double getWebAssignGrade() {
	//we introduce a bug if the grade is 0
	cout << "Please enter the grade for your web assign:" << endl;
	double waGrade = -1;

	while (waGrade < 0) {
		waGrade = iv.getDouble();
		if (waGrade < 0) {
			cout << "Grade must be 0 or greater" << endl;
		}
		cout << endl;
	}
	return waGrade;
}

//gets a participation grade from the user
double getParticipationGrade() {
	//we introduce a bug if the grade is 0
	cout << "Please enter the grade for your participation:" << endl;
	double participationGrade = -1;

	while (participationGrade < 0) {
		participationGrade = iv.getDouble();
		if (participationGrade < 0) {
			cout << "Grade must be 0 or greater" << endl;
		}
		cout << endl;
	}
	return participationGrade;
}

//gets a project grade from the user
//the parameter is to output which project
double getProjectGrade(int projectNum) {
	//we introduce a bug if the grade is 0
	cout << "Please enter the grade for your project grade number " << projectNum << ":" << endl;
	double projectGrade = -1;

	while (projectGrade < 0) {
		projectGrade = iv.getDouble();
		if (projectGrade < 0) {
			cout << "Grade must be 0 or greater" << endl;
		}
		cout << endl;
	}
	return projectGrade;
}

//gets a term project grade from the user
double getTermProject() {
	//we introduce a bug if the grade is 0
	cout << "Please enter the grade for your term project:" << endl;
	double termProjectGrade = -1;

	while (termProjectGrade < 0) {
		termProjectGrade = iv.getDouble();
		if (termProjectGrade < 0) {
			cout << "Grade must be 0 or greater" << endl;
		}
		cout << endl;
	}
	return termProjectGrade;
}

//prints the specific grades for all of the
//specific courses whose gpa is not < 0
//if it is < 0, it means that the specific grade
//values have not been entered
void printAllGrades() {
	if (phy2048.getGpa() > -1) {
		phy2048.printAll();
	}
	if (phy2049.getGpa() > -1) {
		phy2049.printAll();
	}
	if (cot3100.getGpa() > -1) {
		cot3100.printAll();
	}
	if (cop3502.getGpa() > -1) {
		cop3502.printAll();
	}
	if (cop3503.getGpa() > -1) {
		cop3503.printAll();
	}
	if (chm2045.getGpa() > -1) {
		chm2045.printAll();
	}
	if (mac2311.getGpa() > -1) {
		mac2311.printAll();
	}
	if (mac2312.getGpa() > -1) {
		mac2312.printAll();
	}
	if (mac2313.getGpa() > -1) {
		mac2313.printAll();
	}
	if (mas3114.getGpa() > -1) {
		mas3114.printAll();
	}
}

#pragma endregion

#pragma region addCourses
//The following functions do the same function for each specific course
//1. Initializes the local variable to a new instance
//2. sets the course name
//3. initializes a course class
//4. sets the course name for that class
//5. gets a credit hours value from user
//6. sets this credit hours value to both the speific course and the general course value
//7. adds the general course to the course manager (cm) to represent it in its list of courses

//does the above for phy2048
void addPHY2048() {
	phy2048 = *new Phy2048();
	phy2048.setCourseName("PHY2048");

	Course course;
	course.setCourseName("PHY2048");

	int creditHours = getCreditHours();
	phy2048.setCredits(creditHours);
	course.setCredits(creditHours);

	cm.addCourse(course);
}

//does the above for phy2049
void addPHY2049() {
	phy2049 = *new Phy2049();
	phy2049.setCourseName("PHY2049");

	Course course;
	course.setCourseName("PHY2049");

	int creditHours = getCreditHours();

	phy2049.setCredits(creditHours);
	course.setCredits(creditHours);

	cm.addCourse(course);
}

//does the above for cot3100
void addCOT3100() {
	cot3100 = *new Cot3100();
	cot3100.setCourseName("COT3100");

	Course course;
	course.setCourseName("COT3100");

	int creditHours = getCreditHours();

	cot3100.setCredits(creditHours);
	course.setCredits(creditHours);

	cm.addCourse(course);
}

//does the above for cop3502
void addCOP3502() {
	cop3502 = *new COP3502();
	cop3502.setCourseName("COP3502");

	Course course;
	course.setCourseName("COP3502");

	int creditHours = getCreditHours();

	cop3502.setCredits(creditHours);
	course.setCredits(creditHours);

	cm.addCourse(course);
}

//does the above for cop3503
void addCOP3503() {
	cop3503 = *new COP3503();
	cop3503.setCourseName("COP3503");

	Course course;
	course.setCourseName("COP3503");

	int creditHours = getCreditHours();

	cop3503.setCredits(creditHours);
	course.setCredits(creditHours);

	cm.addCourse(course);
}

//does the above for chm2045
void addCHM2045() {
	chm2045.setCourseName("CHM2045");

	Course course;
	course.setCourseName("CHM2045");

	int creditHours = getCreditHours();
	chm2045.setCredits(creditHours);
	course.setCredits(creditHours);

	cm.addCourse(course);
}

//does the above for mac2311
void addMAC2311() {
	mac2311 = *new MAC2311();
	mac2311.setCourseName("MAC2311");

	Course course;
	course.setCourseName("MAC2311");

	int creditHours = getCreditHours();

	mac2311.setCredits(creditHours);
	course.setCredits(creditHours);

	cm.addCourse(course);
}

//does the above for mac2312
void addMAC2312() {
	mac2312 = *new MAC2312();
	mac2312.setCourseName("MAC2312");

	Course course;
	course.setCourseName("MAC2312");

	int creditHours = getCreditHours();

	mac2312.setCredits(creditHours);
	course.setCredits(creditHours);

	cm.addCourse(course);
}

//does the above for mac2313
void addMAC2313() {
	mac2313 = *new MAC2313();
	mac2313.setCourseName("MAC2313");

	Course course;
	course.setCourseName("MAC2313");

	int creditHours = getCreditHours();

	mac2313.setCredits(creditHours);
	course.setCredits(creditHours);

	cm.addCourse(course);
}

//does the above for mas3114
void addMAS3114() {
	mas3114 = *new MAS3114();
	mas3114.setCourseName("MAS3114");

	Course course;
	course.setCourseName("MAS3114");

	int creditHours = getCreditHours();

	mas3114.setCredits(creditHours);
	course.setCredits(creditHours);

	cm.addCourse(course);
}

//adds a custom course value to cm
void addCustomCourse() {
	//declares a new course
	Course customCourse;

	//makes sure that the user doesn't enter any of these values for the custom course
	string courseName = getCourseName();
	if (courseName.compare("PHY2048") == 0 || courseName.compare("PHY2049") == 0 || courseName.compare("COT3100") == 0
		|| courseName.compare("COP3502") == 0 || courseName.compare("COP3503") == 0 || courseName.compare("CHM2045") == 0
		|| courseName.compare("MAC2311") == 0 || courseName.compare("MAC2312") == 0 || courseName.compare("MAC2313") == 0
		|| courseName.compare("MAS3114") == 0) {
		cout << "Cannot add a course with that name" << endl << endl;
		return;
	}
	//gets the course name, gpa, and credits from the user 
	customCourse.setCourseName(courseName);
	customCourse.setGpa(getGPA());
	customCourse.setCredits(getCreditHours());

	//adds the course to the course manager
	cm.addCourse(customCourse);
}

#pragma endregion

#pragma region editCourses

//the following functions edit the specific grade values for the specific classes
//it calls the .calcGpa() function on the class to crunch the gpa for that class
//this value is stored privately in the class
//lastly, it updates the course representation in the course manager

//does the above for phy2048
void editPHY2048() {
	//finals
	phy2048.updateFinal(getFinalGrade());
	//exams
	for (int i = 0; i < 2; i++) {
		phy2048.updateExam(i, getExamGrade(i + 1));
	}
	//quizes
	for (int i = 0; i < 10; i++) {
		phy2048.updateQuiz(i, getQuizGrade(i + 1));
	}
	//homework
	for (int i = 0; i < 13; i++) {
		phy2048.updateHomework(i, getHomeworkGrade(i + 1));
	}
	//hitt
	phy2048.updateHittPoints(getHittGrade());

	//calc gpa and updates course manager
	phy2048.calcGpa();
	Course* course = cm.search(phy2048.getCourseName());
	course->setGpa(phy2048.getGpa());
}

//does the above for phy2049
void editPHY2049() {
	//finals
	phy2049.updateFinal(getFinalGrade());
	//exams
	for (int i = 0; i < 2; i++) {
		phy2049.updateExam(i, getExamGrade(i + 1));
	}
	//quizes
	for (int i = 0; i < 10; i++) {
		phy2049.updateQuiz(i, getQuizGrade(i + 1));
	}
	//homework
	for (int i = 0; i < 13; i++) {
		phy2049.updateHomework(i, getHomeworkGrade(i + 1));
	}
	//hitt
	phy2049.updateHittPoints(getHittGrade());

	//calc gpa and updates course manager
	phy2049.calcGpa();
	Course* course = cm.search(phy2049.getCourseName());
	course->setGpa(phy2049.getGpa());
}

//does the above for cot3100
void editCOT3100() {
	//finals
	cot3100.updateFinal(getFinalGrade());
	//exams
	for (int i = 0; i < 4; i++) {
		cot3100.updateExam(i, getExamGrade(i + 1));
	}

	//calc gpa and updates course manager
	cot3100.calcGpa();
	Course* course = cm.search(cot3100.getCourseName());
	course->setGpa(cot3100.getGpa());
}

//does the above for cop3502
void editCOP3502() {
	//finals
	cop3502.updateFinal(getFinalGrade());

	//exams
	for (int i = 0; i < 2; i++) {
		cop3502.updateExam(i, getExamGrade(i + 1));
	}
	//homework
	for (int i = 0; i < 10; i++) {
		cop3502.updateHomework(i, getHomeworkGrade(i + 1));
	}
	//programming assignments
	for (int i = 0; i < 3; i++) {
		cop3502.updateProgAssignments(i, getProgrammingAssignmentGrade(i + 1));
	}
	//labs
	for (int i = 0; i < 10; i++) {
		cop3502.updateLab(i, getLabGrade(i + 1));
	}

	//calc gpa and updates course manager
	cop3502.calcGpa();
	Course* course = cm.search(cop3502.getCourseName());
	course->setGpa(cop3502.getGpa());
}

//does the above for cop3503
void editCOP3503() {
	//exams
	for (int i = 0; i < 2; i++) {
		cop3503.updateExams(i, getExamGrade(i + 1));
	}
	//programming assignments
	for (int i = 0; i < 3; i++) {
		cop3503.updateAssignments(i, getProgrammingAssignmentGrade(i + 1));
	}
	//term project
	cop3503.updateGroupProject(getTermProject());

	//calc gpa and updates course manager
	cop3503.calcGpa();
	Course* course = cm.search(cop3503.getCourseName());
	course->setGpa(cop3503.getGpa());
}

//does the above for chm2045
void editCHM2045() {
	//finals
	chm2045.updateFinal(getFinalGrade());
	//exams
	for (int i = 0; i < 3; i++) {
		chm2045.updateExam(i, getExamGrade(i + 1));
	}
	//homework
	for (int i = 0; i < 10; i++) {
		chm2045.updateHomework(i, getHomeworkGrade(i + 1));
	}
	//hitt
	chm2045.updateHittPoints(getHittGrade());

	//calc gpa and updates course manager
	chm2045.calcGpa();
	Course* course = cm.search(chm2045.getCourseName());
	course->setGpa(chm2045.getGpa());
}

//does the above for mac 2311
void editMAC2311() {
	//finals
	mac2311.updateFinal(getFinalGrade());
	//exams
	for (int i = 0; i < 3; i++) {
		mac2311.updateExam(i, getExamGrade(i + 1));
	}
	//quizes
	for (int i = 0; i < 10; i++) {
		mac2311.updateQuiz(i, getQuizGrade(i + 1));
	}
	//written homework
	for (int i = 0; i < 5; i++) {
		mac2311.updateWrittenHomework(i, getHomeworkGrade(i + 1));
	}
	//hitt
	mac2311.updateHittPoints(getHittGrade());
	//webassign
	for (int i = 0; i < 13; i++) {
		mac2311.updateWebAssign(i, getWebAssignGrade(i + 1));
	}

	//calc gpa and updates course manager
	mac2311.calcGpa();
	Course* course = cm.search(mac2311.getCourseName());
	course->setGpa(mac2311.getGpa());
}

//does the above for mac2312
void editMAC2312() {
	//finals
	mac2312.updateFinal(getFinalGrade());
	//exams
	for (int i = 0; i < 3; i++) {
		mac2312.updateExam(i, getExamGrade(i + 1));
	}
	//quizes
	for (int i = 0; i < 8; i++) {
		mac2312.updateQuiz(i, getQuizGrade(i + 1));
	}
	//written homework
	for (int i = 0; i < 3; i++) {
		mac2312.updateWrittenHomework(i, getHomeworkGrade(i + 1));
	}
	//hitt
	mac2312.updateHittPoints(getHittGrade());
	//webassign
	mac2312.updateWebAssign(getWebAssignGrade());
	//participation
	mac2312.updateParticipation(getParticipationGrade());

	//calc gpa and updates course manager
	mac2312.calcGpa();
	Course* course = cm.search(mac2312.getCourseName());
	course->setGpa(mac2312.getGpa());
}

//does the above for mac2313
void editMAC2313() {
	//finals
	mac2313.updateFinal(getFinalGrade());
	//exams
	for (int i = 0; i < 3; i++) {
		mac2313.updateExam(i, getExamGrade(i + 1));
	}
	//quizzes
	for (int i = 0; i < 13; i++) {
		mac2313.updateQuiz(i, getQuizGrade(i + 1));
	}
	//web assign
	for (int i = 0; i < 27; i++) {
		mac2313.updateWebAssign(i, getWebAssignGrade(i + 1));
	}
	//participation
	mac2313.updateParticipation(getParticipationGrade());

	//calc gpa and updates course manager
	mac2313.calcGpa();
	Course* course = cm.search(mac2313.getCourseName());
	course->setGpa(mac2313.getGpa());
}

//does the above for mas3114
void editMAS3114() {
	//exams
	for (int i = 0; i < 4; i++) {
		mas3114.updateExams(i, getExamGrade(i + 1));
	}
	//quiz
	mas3114.updateQuiz(getQuizGrade());
	//homework
	for (int i = 0; i < 30; i++) {
		mas3114.updateHomework(i, getHomeworkGrade(i + 1));
	}
	//projects
	for (int i = 0; i < 5; i++) {
		mas3114.updateProjects(i, getProjectGrade(i + 1));
	}
	//participation
	mas3114.updateParticipation(getParticipationGrade());

	//calc gpa and updates course manager
	mas3114.calcGpa();
	Course* course = cm.search(mas3114.getCourseName());
	course->setGpa(mas3114.getGpa());
}

//when given a course pointer, it updates the gpa and credits for it
void editCustomCourse(Course* course) {
	course->setGpa(getGPA());
	course->setCredits(getCreditHours());
}

#pragma endregion

#pragma endregion

#pragma region menu functions

//menu function helper for add previous gpa functionality
//because of the way gpa is calculated, we can represent all of the previous credit hours earned and
//the gpa by making a course with these values
//when overall gpa is crunched, cm will take this as a normal course, but overall gpa is unaffected
void addPreviousGPA() {
	//creates a new course value
	Course previousGPA;

	//sets the name to previous gpa
	previousGPA.setCourseName("Previous GPA");
	//sets the gpa value
	previousGPA.setGpa(getGPA());
	//sets the credit value
	previousGPA.setCredits(getCreditHours());

	//deletes any previous gpa course value
	cm.deleteCourse("Previous GPA");

	//adds the new course value
	cm.addCourse(previousGPA);
}

//menu helper function for show gpa
void showGPA() {
	//print no courses entered when there are no courses
	if (cm.empty()) {
		cout << "There are no courses entered" << endl;
	}
	else {
		//prints all of the courses when there are some
		cm.printCourses();
	}
	cout << endl;
}

//menu helper function for printing the individual course values
void printCourses() {
	//prints no course entered if there are no courses in cm
	if (cm.empty()) {
		cout << "There are no courses entered" << endl;
	}
	else {
		//calls the print all grades function which prints the individual grades for each of the special functions
		printAllGrades();
		//calls the print course function of every representative course 
		cm.printCourses();
	}
	cout << endl;
}

//menu helper function for adding a course
void addCourse() {
	int inputCourse = -1;
	//prints the menu
	do {
		cout << "Please choose from the following courses:" << endl;
		cout << "1. PHY2048" << endl << "2. PHY2049" << endl << "3. COT3100" << endl
			<< "4. COP3502" << endl << "5. COP3503" << endl << "6. CHM2045" << endl << "7. MAC2311" << endl << "8. MAC2312" << endl
			<< "9. MAC2313" << endl << "10. MAS3114" << endl << "11. Custom Course" << endl << "12. Return to main menu" << endl << endl;
		//gets int from user
		inputCourse = iv.getInt();
		//does checks to make sure that the number is valid
		if (inputCourse > 12) {
			cout << "Invalid choice: " << inputCourse << endl;
		}
		//if it is 12 we break
		if (inputCourse == 12) {
			break;
		}
		cout << endl;
	} while (inputCourse < 0 || inputCourse > 12);
	//calls the add function for the course selected
	switch (inputCourse) {
	case 1:
		addPHY2048();
		break;
	case 2:
		addPHY2049();
		break;
	case 3:
		addCOT3100();
		break;
	case 4:
		addCOP3502();
		break;
	case 5:
		addCOP3503();
		break;
	case 6:
		addCHM2045();
		break;
	case 7:
		addMAC2311();
		break;
	case 8:
		addMAC2312();
		break;
	case 9:
		addMAC2313();
		break;
	case 10:
		addMAS3114();
		break;
	case 11:
		addCustomCourse();
		break;
	}
}

//menu helper function for editing a course
void editCourse() {
	//prints that there are no courses if cm is empty
	if (cm.empty()) {
		cout << "There are no courses to edit" << endl << endl;
		return;
	}

	//prompts the user
	cout << "Please enter the number of the course to edit:" << endl;
	cm.printCourses();
	cout << endl;
	int choice = -1;
	Course* course;

	//makes sure that the input is valid
	while (choice < 1) {
		choice = iv.getInt();
		//tries to find the course at that index
		course = cm.findAt(choice - 1);

		//if it returns a course with an empty string then, no such course was found
		if (course->getCourseName().compare("") == 0) {
			cout << "Invalid input" << endl;
			choice = -1;
		}
		cout << endl;
	}

	//calls the appropriate edit function based off of the user input
	if (course->getCourseName().compare("PHY2048") == 0) {
		editPHY2048();
	}
	else if (course->getCourseName().compare("PHY2049") == 0) {
		editPHY2049();
	}
	else if (course->getCourseName().compare("COT3100") == 0) {
		editCOT3100();
	}
	else if (course->getCourseName().compare("COP3502") == 0) {
		editCOP3502();
	}
	else if (course->getCourseName().compare("COP3503") == 0) {
		editCOP3503();
	}
	else if (course->getCourseName().compare("CHM2045") == 0) {
		editCHM2045();
	}
	else if (course->getCourseName().compare("MAC2311") == 0) {
		editMAC2311();
	}
	else if (course->getCourseName().compare("MAC2312") == 0) {
		editMAC2312();
	}
	else if (course->getCourseName().compare("MAC2313") == 0) {
		editMAC2313();
	}
	else if (course->getCourseName().compare("MAS3114") == 0) {
		editMAS3114();
	}
	else {
		editCustomCourse(course);
	}
}

//menu helper function for delete course
void deleteCourse() {
	//prints that there are no courses if cm is empty
	if (cm.empty()) {
		cout << "There are no courses to delete" << endl;
		return;
	}

	//prompts the user
	cout << "Please choose from the following courses:" << endl;
	cm.printCourses();
	cout << endl;
	int choice = -1;
	Course* course;

	while (choice < 1) {
		choice = iv.getInt();
		//tries to find the course at the given index
		course = cm.findAt(choice - 1);

		//if cm returns a course with an empty string then there was no course found
		if (course->getCourseName().compare("") == 0) {
			cout << "Invalid input" << endl;
			choice = -1;
		}
	}
	cout << endl;

	//wipes the values of the specific course if it is chosen
	if (course->getCourseName().compare("PHY2048") == 0) {
		phy2048 = *new Phy2048();
	}
	else if (course->getCourseName().compare("PHY2049") == 0) {
		phy2049 = *new Phy2049();
	}
	else if (course->getCourseName().compare("COT3100") == 0) {
		cot3100 = *new Cot3100();
	}
	else if (course->getCourseName().compare("COP3502") == 0) {
		cop3502 = *new COP3502();
	}
	else if (course->getCourseName().compare("COP3503") == 0) {
		cop3503 = *new COP3503();
	}
	else if (course->getCourseName().compare("CHM2045") == 0) {
		chm2045 = *new Chm2045();
	}
	else if (course->getCourseName().compare("MAC2311") == 0) {
		mac2311 = *new MAC2311();
	}
	else if (course->getCourseName().compare("MAC2312") == 0) {
		mac2312 = *new MAC2312();
	}
	else if (course->getCourseName().compare("MAC2313") == 0) {
		mac2313 = *new MAC2313();
	}
	else if (course->getCourseName().compare("MAS3114") == 0) {
		mas3114 = *new MAS3114();
	}

	//deletes the course from course manager
	cm.deleteCourse(course->getCourseName());
}

#pragma endregion
#endif // !GPACALCULATORDRIVER

