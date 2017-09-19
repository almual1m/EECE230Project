#include "Student.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
int main();

Student::Student() {
    StudentID = 0;
    FirstName = "";
    LastName = "";
    password = "";
    CourseGrade = NULL;
}

Student::Student (int Student, string First, string Last, string Pass, double *Grade) {
    StudentID = Student;
    FirstName = First;
    LastName = Last;
    password = Pass;
    CourseGrade = Grade;

    // TEMPORARY
    CourseName = new string[2];
    CourseName[0] = "math102";
    CourseName[1] = "engl102";
    Number_courses = 2;
}

void Student:: EnterPassword() {
    cout << "Enter your password: " << endl;
    string Passwordentered;
    cin >> Passwordentered;
    password = Passwordentered;
}

void Student:: CheckPassword() {
    string Pass;
    cout << "Enter your password to check it:" << endl;
    cin >> Pass;
    if (password.compare(Pass) != 0 )
        cout << "Password is incorrect" << endl;
}

void Student:: PrintOut() {
    cout << "do you want to display all courses? Y/N" << endl;
    string in1;
    cin >> in1;
    if (in1.compare("Y") == 0) {
        for (int i = 0; i < Number_courses; i++) {
            cout << "your grade for the course " << CourseName[i] << " is " << CourseGrade[i] << endl;
        }
    }
    else {
        cout << "enter the number course name" << endl;
        string coursename;
        cin >> coursename;
        bool correct = false;
        for (int i = 0; i < Number_courses; i++) {
            if (CourseName[i].compare(coursename) == 0) {
                cout << "your grade for the course " << coursename << " is " << CourseGrade[i] << endl;
                correct = true;
            }
        }
        if(!correct)
            cout << "You are not registered for this course." << endl;
    }
}
void Student::printOutToTxt() {
    string Result;//string which will contain the result
    stringstream convert; // stringstream used for the conversion
    convert << StudentID;//add the value of Number to the characters in the stream
    Result = convert.str();//set Result to the content of the stream
    string s = LastName + "_" + Result + ".txt";
    ofstream outfile;
    outfile.open(s);
    outfile << FirstName << " " << LastName << " , ID: " << StudentID << endl;
    for (int i = 0; i < 20; i++) {
        outfile << CourseName[i] << " " << CourseGrade[i] << endl;
    }
}

void Student::checkGPA() {
    double sum = 0;
    for (int i = 0; i < 5; i++) {
        if (CourseGrade[i] != -1) {
            sum = sum + CourseGrade[i];
        }
    }
    int j=0;
    for (int i = 0; i < 5; i++) {
        if (CourseGrade[i] != -1) {
            j++;
        }
    }
    double avg = sum / (5-j);
    cout << "Your current GPA is " << avg << "." << endl;
}
void Student::studentMenu() {
    int n;
    cout << "Welcome " << FirstName << ", what do you want to do today?" << endl;
    cout << "1) Check your grades \n2) Export your grades to a txt file \n3)Check your GPA\n0)Logout";
    cin >> n;
    while (n != 0) {
        switch (n)
        {
        case 1:
            PrintOut();
            break;
        case 2:
            printOutToTxt();
            break;
        case 3:
            checkGPA();
            break;
        case 0:
            cout << "Thank you for your service.\n\n" << endl;
            break;
        default:
            cout << "You entered a wrong number, please try again." << endl;
            break;
        }
    }
    main();
}