#include "Student.hpp"
#include <iostream>
int main();

Professor::Professor() {
    professorID = 0;
    firstName = "";
    lastName = "";
    password = "";
    courseTitle = "";
}

Professor::Professor(int professor, string first, string last, string title, string pass) {
    professorID = professor;
    firstName = first;
    lastName = last;
    courseTitle = title;
    password = pass;
}

void Professor:: EnterPassword() {
    cout << "Enter your password: " << endl;
    string Passwordentered;
    cin >> Passwordentered;
    password = Passwordentered;
}

void Professor:: CheckPassword() {
    string Pass;
    cout << "Enter your password to check it:" << endl;
    cin >> Pass;
    if (password.compare(Pass) != 0 )
        cout << "Password is incorrect" << endl;
}

void Professor::setGrades(Student *stu) {
    cout << "Please set the grades of the following students (if the student was absent, enter -1):";
    for (int i = 0; i < 20; i++) {
        cout << stu[i].FirstName << " " << stu[i].LastName << ": ";
        cin >> stu[i].CourseGrade[profNum];
    }

}
void Professor::checkAvg(Student *stu) {
    double sum = 0;
    for (int i = 0; i < 20; i++) {
        sum = sum + stu[i].CourseGrade[profNum];
    }
    double avg = sum / 20;
    cout << "The class average is: " << avg << "." << endl;
}
void Professor::printOut(Student *stu) {

}
void Professor::profMenu(Student *stu) {
    cout << "\nHello Professor"<< lastName <<", what would you like to do today?" << endl;
    cout << "1) Set Student's Grades.\n2) Check Course Average.\n3) Print Out." << endl;
    int n;
    cin >> n;
    while (n != 0) {
        switch (n)
        {
        case 1:
            setGrades(stu);
            break;
        case 2:
            checkAvg(stu);
            break;
        case 3:
            printOut(stu);
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