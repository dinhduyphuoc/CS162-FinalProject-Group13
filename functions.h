#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

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
	Student student;
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
	bool isActive;
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
void AddCourseManually();
void EditCourse();
void viewCourse();
//Lecturer section

//Student section


