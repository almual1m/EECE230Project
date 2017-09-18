#include<iostream>
#include<string>
#include<fstream>
#include"sysAdmin.h"
#include<windows.h>
#include<conio.h>
using namespace std;

int main();

sysAdmin::sysAdmin() {
	username = 0000;
	password = "exceptionalID1234";
}

sysAdmin::sysAdmin(int user, string pass) {
	username = user;
	password = pass;
}

bool sysAdmin::checkPassword(string pass) {
	if (pass == password) {
		return true;
	}
	else return false;
}

void sysAdmin::adminMenu(int &user, string &pass) {
	int n;
	cout << "\n\nWelcome sysAdmin, what would you like to do today?" << endl;
	cout << "1) Create Professors' List.\n2) Create Students' List.\n3) View Professors' List.\n4) View Students' List.\n0) Nothing." << endl;
	cin >> n;
	while(n != 0) {
		switch (n)
		{
		case 1: enterProfNames(n, user, pass);
			break;
		case 2: enterStudentNames(n, user, pass);
			break;
		case 3: profList(n, user, pass);
			break;
		case 4: studentList(n, user, pass);
			break;
		case 0: cout << "Thank you for your service.\n\n" << endl;
			break;
		default: cout << "You entered a wrong number, please try again." << endl;
			break;
		}
	}
	main();
}

void sysAdmin::enterStudentNames(int &n, int &user, string &pass) {
	cout << "Please enter the names of the 20 Studets you wish to register." << endl;
	std::ofstream outfile("StudentNames.txt");
	string s4 = "1";
	for (int j = 0; j < 20; j++) {
		string s1, s2, s3;
		cout << "Please enter the first name of the Student no." << j + 1 <<": "<< endl;
		cin >> s1;
		cout << "Please enter his last name: ";
		cin >> s2;
		cout << "Please enter his ID: ";
		cin >> s3;
		s4 = s1 + " " + s2 + " " + s3;
		outfile << s4 << endl;
	}
	adminMenu( user, pass);
}

void sysAdmin::enterProfNames(int &n, int &user, string &pass) {
	cout << "Please enter the names of the 5 Professors you wish to register." << endl;
	std::ofstream outfile("ProfsNames.txt");
	string s3 = "1";
	for (int j = 0; j < 5; j++) {
		string s1, s2, s3, s4, s5;
		cout << "Please enter the first name of the Professor no." << j + 1 <<":";
		cin >> s1;
		cout << "Please enter his last name:";
		cin >> s2;
		cout << "Please enter his course title:";
		cin >> s3;
		cout << "Please enter his ID:";
		cin >> s5;
		s4 = s1 + " " + s2 + " " + s3 + " " + s5;
		outfile << s4 << endl;
	}
	adminMenu( user, pass);
}

void sysAdmin::studentList(int &n, int &user, string &pass) {
	cout << "Here is the Students' list." << endl;
	int i = 0;
	std::ifstream file("StudentsNames.txt");
	string str;

	while (getline(file, str))
	{
		cout << i + 1 << ") " << str << endl;
		i++;
	}
	adminMenu( user, pass);
}

void sysAdmin::profList(int &n, int &user, string &pass) {
	cout << "Here is the Professors' list." << endl;
	int y = 0;
	std::ifstream file("ProfsNames.txt");
	string str;
	while (getline(file, str)) {
		cout << y + 1 << ") " << str << endl;
		y++;
	}
	adminMenu( user, pass);
}