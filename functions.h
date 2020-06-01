#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
	float midterm, bonus, final, total;
};

struct AYear {
	int startYear;
	int endYear;
	string semester;
};

struct Scoreboard {
	string ID, name;
	float Midterm, Final, Bonus, Total;
};

struct Attendance {
	int attendance;
	DOB Date;
	Time startTime, endTime;

};

//ALTERNATIVE FUNCTIONS
void writeStudent(ofstream& fout, Student*& student, int i);
void LoadCourse(ifstream& fin, Course*& course, int n);
int noOfRows(string address);
void importStudentCSV(ifstream& fin, Student* student, int n);
void readScoreboard(ifstream& fin, Scoreboard* board, int n);
void readAttendance(ifstream& fin, Course*& course, Attendance**& atd, int i);
void writeCourse(ofstream& fout, Course*& course, int i);

//Staff section
void ImportStudents();
void AddStudentManually();
void ChangeClass();
void EditStudent();
void RemoveStudent();
void ChangeClass();
void viewclass();
void viewStudent();

void EditAcademicYears();
void ImportCourses();
void AddCourseManually();
void EditCourse();
void AddCourseManually();
void removeCourse();
void viewCourse();
void viewAllLecturer();
void viewAttendanceList();
void removeStudentfromCourse();
void viewStudentofCourse();

void ViewScoreboard();

//Lecturer section
void viewCourseofSemester();
void exportScoreboardCSV();
void editAttendance();
//Student section
void checkin();
