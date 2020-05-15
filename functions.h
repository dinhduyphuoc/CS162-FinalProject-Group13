#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct DOB {
	int year, month, day;
};

struct Staff {
	string username;
	string password;
	string fullName;
	bool gender;
};

struct Lecturer {
	string username;
	string password;
	string fullName;
	string education;
	bool gender;
};

struct Student {
	string id; 
	string password;
	string fullName;
	DOB birthday;
	string Class;
	bool gender;
	bool isActive;
};



//Staff section
void ImportStudents();
void AddStudentManually();

//Lecturer section

//Student section


