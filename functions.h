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

//ALTERNATIVE FUNCTIONS
int noOfRows(string address) {
	ifstream file(address);
	string data;
	int count = 0;
	while (getline(file, data)) {
		count++;
	}
	return count;
} //COUNT NUMBERS OF ROW IN CSV FILE
void LoadCourse(ifstream& fin, Course*& course, int n) {
	for (int i = 0; i < n; ++i) {
		fin.ignore(1000, '\n');
		fin.get();
		getline(fin, course[i].course);
		getline(fin, course[i].courseName);
		getline(fin, course[i].Class);
		getline(fin, course[i].lecturerUser);
		getline(fin, course[i].lecturerName);
		getline(fin, course[i].education);
		fin >> course[i].gender;
		fin >> course[i].startDate.year >> course[i].startDate.month >> course[i].startDate.day;
		fin >> course[i].endDate.year >> course[i].endDate.month >> course[i].endDate.day;
		fin >> course[i].day;
		fin >> course[i].startTime.hour >> course[i].startTime.minute;
		fin >> course[i].endTime.hour >> course[i].endTime.minute;
		fin.ignore(1000, '\n');
		getline(fin, course[i].room);
	}
}

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
void viewAllLecturer();
void viewAttendanceList();

//Lecturer section

//Student section


