#pragma once
#include <string>
using namespace std;
class sysAdmin {
private:
	int username;
	string password;
public:	sysAdmin();
		sysAdmin(int user, string pass);
		void adminMenu(int &user, string &pass);
		void enterStudentNames(int &n, int &user, string &pass);
		void enterProfNames(int &n, int &user, string &pass);
		void studentList(int &n, int &user, string &pass);
		void profList(int &n, int &user, string &pass);
		bool checkPassword(string pass);

};
