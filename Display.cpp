#include<iostream>
#include<ciso646>
#include<string>
#include<fstream>
//#include<windows.h>
//#include<conio.h>
#include"sysAdmin.h"
#include"Student.hpp"
#include"Professor.hpp"
using namespace std;
int main();
struct user {
	int username;
	string password;
};

bool is_textfile_empty(const char* filename)
{
	string   s;
	ifstream f(filename, ios::binary);

	// Check for UTF-8 BOM
	if (f.peek() == 0xEF)
	{
		f.get();
		if (f.get() != 0xBB) return false;
		if (f.get() != 0xBF) return false;
	}

	// Scan every line of the file for non-whitespace characters
	while (getline(f, s))
	{
		if (s.find_first_not_of(
			" \t\n\v\f\r" // whitespace
			"\0\xFE\xFF"  // non-printing (used in various Unicode encodings)
			) != string::npos)
			return false;
	}

	// If we get this far, then the file only contains whitespace
	// (or its size is zero)
	return true;
}

//void doBackspace()
//{
//	HANDLE hOut;
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
//	if ((hOut = GetStdHandle(STD_OUTPUT_HANDLE)) &&
//		GetConsoleScreenBufferInfo(hOut, &csbi))
//	{
//		COORD pos = csbi.dwCursorPosition; // Get current position
//										   // Get position of last character
//		if (pos.X > 0)
//			--pos.X;
//		else if (pos.Y > 0)
//		{
//			--pos.Y;
//			pos.X = csbi.dwSize.X - 1;
//		}
//		// Overwrite that character with a space and move the cursor back
//		DWORD unused;
//		WriteConsoleOutputCharacter(hOut, " ", 1, pos, &unused);
//		SetConsoleCursorPosition(hOut, pos);
//	}
//}

void loginUP( user &x){
	cout << "\nPlease enter ID:" << endl;
	/*getline(cin, s);
	username = atoi(s.c_str());*/
	cin >> x.username;
	cout << "\nPlease enter Password:" << endl;
	cin >> x.password;
	//getline(cin, pass);
	//ch = _getch();
	//while ((ch = _getch()) != 13)
	//{
	//	if (ch == 8) // delete
	//	{
	//		 cant delete from a empty
	//		 string so check this
	//		if (password.length() > 0) {
	//			password.erase(password.length() - 1);
	//			cout << "\b \b"; // backspace and clear
	//		}
	//	}
	//	else
	//	{
	//		 we are appending
	//		password.push_back(ch);
	//		cout << '*';
	//	}
	//}
}

void programMenu1() {
	string s;
	int n;
	int username;
	string password;
	sysAdmin Julien;
	cout << "Students and/or Professors haven't been registered yet, only admin can login:" << endl;
	cout << "Please select your section:\n1) Student\n2) Proffesor\n3) Admin" << endl;
	cin >> n;
	if (n == 3) {
		user admin;
		loginUP(admin);
		if (admin.username == 0000) {
			if (Julien.checkPassword(admin.password)) {
				Julien.adminMenu(username, admin.password);
			}
			else cout << "Wrong password. The string you entered is: " << admin.password << endl;

		}
		else cout << "Wrong username." << endl;
		main();
	}
	if (n == 2) {// You are a professor
		ifstream infile;
		infile.open("ProfsNames.txt");
		if (!infile || is_textfile_empty("ProfsNames.txt"))
		{
			cout << "No Professors are registered, the program will restart." << endl;// The admin hasn't created yet the professor's file 
			main();
		}
		
	}
	if (n == 1) {//You are a student
		ifstream infile;
		infile.open("StudentNames.txt");
		if (!infile || is_textfile_empty("StudentNames.txt"))
		{
			cout << "No Students are registered, the program will restart." << endl;// The admin hasn't created yet the student's file 
			main();
		}
	}
}

void programMenu(Student *stu, Professor *prof) {
	/*char ch;*/
	
	string s;
	int n;
	int username;
	string password;
	sysAdmin Julien;
	cout << "Please select your section:\n1) Student\n2) Proffesor\n3) Admin" << endl;
	cin >> n;
	if (n == 3) {
		user admin;
		loginUP(admin);
		if (admin.username == 0000) {
			if (Julien.checkPassword(admin.password)) {
				Julien.adminMenu(username, admin.password);
			}
			else cout << "Wrong password. The string you entered is: " << admin.password << endl;

		}
		else cout << "Wrong username." << endl;
		main();
	}
	if (n == 2) {// You are a professor
		ifstream infile;
		infile.open("ProfsNames.txt");
		if (!infile|| is_textfile_empty("ProfsNames.txt"))
		{
			cout << "No Professors are registered, the program will restart." << endl;// The admin hasn't created yet the professor's file 
			main();
		}
		else {
			user professor;
			loginUP(professor);
			
			int j = 0;
			while (professor.username != prof[j].professorID&&j<5) {
				j++;
			}
			if (j >= 0 && j < 5) {
				if (prof[j].logNumber == 0) {
					cout << "Please enter your new password: ";
					cin >> prof[j].password;
					cout << "Thank you the program will now restart.";
					main();
				}
				else if (professor.password == prof[j].password) {
					prof[j].profMenu(stu);
				}
				else cout << "You entered the wrong password." << endl;
				
			}
			else {
				cout << "The username provided does not exist, the program will restart." << endl;
				main();
			}
		}
	}
	if (n == 1) {//You are a student
		ifstream infile;
		infile.open("StudentNames.txt");
		if (!infile || is_textfile_empty("StudentNames.txt"))
		{
			cout << "No Students are registered, the program will restart." << endl;// The admin hasn't created yet the student's file 
			main();
		}
		else {
			user student;
			loginUP(student);
			
			int j = 0;
			while (student.username != stu[j].StudentID&&j<20) {
				j++;
			}
			if (j >= 0 && j < 20) {
				if (stu[j].logNumber == 0) {
					cout << "Please enter your new password: ";
					cin >> stu[j].password;
					cout << "Thank you the program will now restart.";
					main();
				}
				else if (student.password == stu[j].password) {
				
				}
				else cout << "You entered the wrong password." << endl;

			}
			else {
				cout << "The username provided does not exist, the program will restart." << endl;
				main();
			}
			
		}
	}
}

int mainMenu() {

	int l=0;
	cout << "\n\nWelcome to the new Grading System of AUB:\n\n			Coded by Joelle Gharios and Julien Allam." << endl;
	cout << "\nWhat would you like to do today?" << endl;
	cout << "1) Login\n2) Logout" << endl;
	
	while (l != 1 || l != 2) {
		cin >> l;
		if (l == 1) {
			return 1;
		}
		else if (l == 2) {
			return 2;
		}
		else {
			cout << "You entered a wrong number please try again:";

		}
	}
	
}



