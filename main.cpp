#include "Student.hpp"
#include <iostream>
#include <fstream>
#include "sysAdmin.h"
Professor *prof = new Professor[5];
Student *stu = new Student[20];
using namespace std;
int mainMenu();
void doBackspace();
void programMenu1();
void programMenu(Student *stu, Professor *prof);
int logNumber = 0;

int main() {
    // int Student, string First, string Last, string Pass, double *Grade
    /* double *grade = new double[2];
     grade[0] = 60;
     grade[1] = 61;
     Student joelle = Student(2018, "joelle", "Ghaghios", "jeanmarc", grade);
     joelle.PrintOut();
     return 0;*/
    // Test Admin
    //string username;
    //string password;
    //sysAdmin Julien;
    ifstream infile, file;
    infile.open("ProfsNames.txt");
    file.open("StudentsNames.txt");
    if (infile&&file&&logNumber==0) {
        logNumber++;

        for (int i = 0; i < 5; i++) {
            infile >> prof[i].firstName >> prof[i].lastName >> prof[i].courseTitle >>prof[i].professorID;
            prof[i].profNum = i;
        }
        infile.close();

        for (int i = 0; i < 20; i++) {
            file >> stu[i].FirstName >> stu[i].LastName >> stu[i].StudentID;
        }
        infile.close();

        cout << "We will now put the passwords of the professors:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << prof[i].firstName << " " << prof[i].lastName << ", your ID is: "
                 << prof[i].professorID << ", the course you will be teaching is: "
                 << prof[i].courseTitle << ", please enter the password you want to use: ";
            cin >> prof[i].password;
        }

        cout << "\n\nWe will now put the passwords of the students:" << endl;
        for (int j = 0; j < 20; j++) {
            cout << stu[j].FirstName << " " << stu[j].LastName << ", your ID is: "
                 << stu[j].StudentID << ", please enter the pasword you want to use: ";
            cin >> stu[j].password;
        }
        cout << "The Program will now restart." << endl;
        main();
    }
    if (infile&&file&&logNumber > 0) {
        int l = mainMenu();
        if (l == 1) {
            programMenu(stu, prof);
        }
        else if (l == 2) {
            return 0;
        }
    }
    if (logNumber > 0) {

    }
    if ((!infile || !file) && logNumber == 0) {
        int l = mainMenu();
        if (l == 1) {
            programMenu1();
        }
    }

}
