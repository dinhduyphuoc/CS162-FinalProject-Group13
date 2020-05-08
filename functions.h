#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct DOB {
	int year, month, day;
};

struct staff {
	string username;
	string passwrd;
	string fullName;
	bool gender;
};

struct lecturer {
	string username;
	string passwrd;
	string fullName;
	string education;
	bool gender;
};

struct student {
	string id; 
	string passwrd;
	string fullName;
	DOB birthday;
	string Class;
	bool gender;
};



//Staffs section

//Lecturers Section

//Students section
