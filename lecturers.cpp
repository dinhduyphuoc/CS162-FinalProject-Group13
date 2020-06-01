#include "functions.h"
#include "menu.h"

void viewCourseofSemester() {
	ifstream fin;
	ofstream fout;
	Course* course;
	string Class;
	int n;
	cout << "Enter class that attend to this course: ";
	cin >> Class;
	fin.open("Data/Courses/2019-2020-HK2-Schedule-" + Class + ".txt");
	if (!fin.is_open()) {
		cout << "Can not open this file! " << endl;
		return;
	}
	fin >> n;
	course = new Course[n];
	LoadCourse(fin, course, n);
	fin.close();
	for (int i = 0; i < n; ++i) {
		cout << course[i].course << endl;
		cout << course[i].courseName << endl;
		cout << course[i].Class << endl;
		cout << course[i].lecturerUser << endl;
		cout << course[i].lecturerName << endl;
		cout << course[i].education << endl;
		cout << course[i].gender << endl;
		cout << course[i].startDate.year << " " << setw(2) << setfill('0') << course[i].startDate.month << " " << setw(2) << setfill('0') << course[i].startDate.day << endl;
		cout << course[i].endDate.year << " " << setw(2) << setfill('0') << course[i].endDate.month << " " << setw(2) << setfill('0') << course[i].endDate.day << endl;
		cout << course[i].day;
		cout << course[i].startTime.hour << " " << setw(2) << setfill('0') << course[i].startTime.minute << endl;
		cout << course[i].endTime.hour << " " << setw(2) << setfill('0') << course[i].endTime.minute << endl;
		cout << course[i].room;
	}
	fout.close();
}
void viewStudentofCourse() {
	ifstream fin;
	ofstream fout;
	string temp, Class;
	int n;
	cout << "Enter name of the course : ";
	cin >> temp;
	cout << "Enter class that attend to this course: ";
	cin >> Class;
	fin.open("Data/Courses/2019-2020-HK2-" + Class + "-" + temp + "-Student.txt");
	if (!fin.is_open()) {
		cout << "Can not open this file! " << endl;
		return;
	}
	fin >> n;
	Student* student = new Student[n];
	for (int i = 0; i < n; i++) {
		fin.ignore(1000, '\n');
		fin.get();
		getline(fin, student[i].id, '\n');
		getline(fin, student[i].password, '\n');
		getline(fin, student[i].fullName, '\n');
		fin >> student[i].birthday.year >> student[i].birthday.month >> student[i].birthday.day;
		fin.ignore(1000, '\n');
		getline(fin, student[i].Class, '\n');
		fin >> student[i].isActive;
	}
	fin.close();
	for (int i = 0; i < n; i++) {
		cout << student[i].id << endl;
		cout << student[i].password << endl;
		cout << student[i].fullName << endl;
		cout << student[i].birthday.year << " " << setw(2) << setfill('0') << student[i].birthday.month << " " << setw(2) << setfill('0') << student[i].birthday.day << endl;
		cout << student[i].Class << endl;
		cout << student[i].isActive << endl;
		cout << endl;
	}
	fout.close();
}

