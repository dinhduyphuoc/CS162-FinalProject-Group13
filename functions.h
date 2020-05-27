#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

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

struct Scoreboard {
	string ID;
	float Midterm, Final, Bonus, Total;
};

//Staff section
void ImportStudents();
void AddStudentManually();
void EditStudent();
void RemoveStudent();
void ChangeClass();
void viewclass();
void viewStudent();

void EditAcademicYears();
void ImportCourses();
void EditCourse();
void AddCourseManually();
void removeCourse();
void viewCourse();
void viewAllLecturer();
void removeStudentfromCourse();
void viewStudentofCourse();

void ViewScoreboard();

//Lecturer section
void viewCourseofSemester();

//Student section

#endif