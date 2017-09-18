

#include <stdio.h>
#include <string>

using namespace std;

class Student
{

    
public:
    Student();
    Student (int Student, string First, string Last, string Pass, double *Grade);
    // do desttructor
	void studentMenu();
    void EnterPassword ();
    void CheckPassword ();
    void PrintOut ();
	void printOutToTxt();
    void checkGPA ();
	int StudentID;
	int Number_courses;
	int logNumber;
	string FirstName;
	string LastName;
	string password;
	double *CourseGrade = new double [5];
	string *CourseName;
};


class Professor : public Student
{
public:
	Professor();
	Professor(int professorID, string firstName, string LastName, string courseTitle, string password);
	// do desttructor
	void EnterPassword();
	void CheckPassword();
	void profMenu(Student *);
	void printOut(Student *);
	void checkAvg(Student *);
	void setGrades(Student *);
	int professorID;
	int profNum;
	string firstName;
	string lastName;
	string courseTitle;
	string password;
};