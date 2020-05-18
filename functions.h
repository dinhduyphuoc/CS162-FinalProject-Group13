#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct DOB {
	int year, month, day;
};

struct Time {
	int hour;
	int minute;
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
	bool isActive;
};

struct Course {
	string course;
	string courseName;
	string Class;
	string lecturerUser;
	string lecturerName;
	string education;
	bool gender;
	DOB startDate;
	DOB endDate;
	int day;
	Time startTime;
	Time endTime;
	string room;
};

struct AYear {
	int startYear;
	int endYear;
	string semester;
};


//Staff section
void ImportStudents();
void AddStudentManually();
void ChangeClass();
void EditStudent();
void RemoveStudent();
void viewclass();
void viewStudent();

void EditAcademicYears();
void ImportCourses();
void EditCourse();
//Lecturer section

//Student section


