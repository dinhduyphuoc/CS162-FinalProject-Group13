#pragma once

#include <iostream>
#include <fstream>
#include <string>

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
};

//Staff section
void AddStudentManually(Student & student1, Student & student2);

//Lecturer section

//Student section


