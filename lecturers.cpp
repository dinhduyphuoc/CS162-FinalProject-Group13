#include "functions.h"

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
	fout.open("Data/Courses/2019-2020-HK2-Schedule-" + Class + ".txt");
	if (!fout.is_open()) {
		cout << "Can not open this file!" << endl;
		return;
	}
	fout << n - 1;
	for (int i = 0; i < n; ++i) {
		fout << endl;
		fout << endl;
		fout << course[i].course << endl;
		fout << course[i].courseName << endl;
		fout << course[i].Class << endl;
		fout << course[i].lecturerUser << endl;
		fout << course[i].lecturerName << endl;
		fout << course[i].education << endl;
		fout << course[i].gender << endl;
		fout << course[i].startDate.year << " " << setw(2) << setfill('0') << course[i].startDate.month << " " << setw(2) << setfill('0') << course[i].startDate.day << endl;
		fout << course[i].endDate.year << " " << setw(2) << setfill('0') << course[i].endDate.month << " " << setw(2) << setfill('0') << course[i].endDate.day << endl;
		fout << course[i].day;
		fout << course[i].startTime.hour << " " << setw(2) << setfill('0') << course[i].startTime.minute << endl;
		fout << course[i].endTime.hour << " " << setw(2) << setfill('0') << course[i].endTime.minute << endl;
		fout << course[i].room;
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
	fout.open("Data/Courses/2019-2020-HK2-" + Class + "-" + temp + "-Student.txt");
	if (!fout.is_open()) {
		cout << "Can not open this file! " << endl;
		return;
	}
	fout << n;
	for (int i = 0; i < n; i++) {
		fout << endl;
		fout << endl;
		fout << student[i].id << endl;
		fout << student[i].password << endl;
		fout << student[i].fullName << endl;
		fout << student[i].birthday.year << " " << setw(2) << setfill('0') << student[i].birthday.month << " " << setw(2) << setfill('0') << student[i].birthday.day << endl;
		fout << student[i].Class << endl;
		fout << student[i].isActive;
	}
	fout.close();
}

