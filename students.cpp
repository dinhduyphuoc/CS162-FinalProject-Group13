#include "functions.h"

void checkin(Student& student) {
	time_t now = time(0);
	tm* t = localtime(&now);
	int day = t->tm_mday;
	int month = t->tm_mon + 1;
	int year = t->tm_year + 1900;
	int hour = t->tm_hour;
	int min = t->tm_min;
	string CourseClass, course;
	int n;
	ifstream fin;
	ofstream fout;
	cin.ignore(1000, '\n');
	cout << "Enter the class: ";
	getline(cin, CourseClass, '\n');
	cout << "Enter the course: ";
	getline(cin, course, '\n');
	fin.open("Data/Courses/2019-2020-HK2-" + CourseClass + "-" + course + "-Student-Attendance.txt");
	if (!fin.is_open())
	{
		cout << "Cannot open the file!" << endl;
		return;
	}
	fin >> n;
	Course* courseTmp = new Course[n];
	Attendance** atd = new Attendance * [n];
	for (int i = 0; i < n; i++) {
		atd[i] = new Attendance[11];
	}
	for (int i = 0; i < n; ++i)
	{
		readAttendance(fin, courseTmp, atd, i);
	}
	fin.close();
	int check;
	string ID;
	ID = student.id;
	cout << "Enter 1 to check in" << endl;
	cin >> check;
	for (int i = 0; i < n; i++) {
		if (courseTmp[i].student.id == ID) {
			for (int j = 0; j < 10; j++) {
				if (atd[i][j].Date.year == year && atd[i][j].Date.month == month && atd[i][j].Date.day == day) {
					if ((atd[i][j].startTime.hour * 3600 + atd[i][j].startTime.minute * 60 < hour * 3600 + min * 60) && (atd[i][j].endTime.hour * 3600 + atd[i][j].endTime.minute * 60 > hour * 3600 + min * 60)) {
						atd[i][j].attendance = 1;
						cout << "Check in successfully!" << endl;
						fout.open("Data/Courses/2019-2020-HK2-" + CourseClass + "-" + course + "-Student-Attendance.txt");
						if (!fout.is_open())
						{
							cout << "Cannot open the file!" << endl;
							return;
						}
						fout << n;
						for (int i = 0; i < n; ++i)
						{
							fout << endl;
							fout << endl;
							fout << courseTmp[i].student.id << endl;
							fout << courseTmp[i].student.password << endl;
							fout << courseTmp[i].student.fullName << endl;
							fout << courseTmp[i].student.birthday.year << " " << courseTmp[i].student.birthday.month << " " << courseTmp[i].student.birthday.day << endl;
							fout << courseTmp[i].Class << endl;
							fout << courseTmp[i].isActive << endl;
							fout << courseTmp[i].midterm << endl;
							fout << courseTmp[i].final << endl;
							fout << courseTmp[i].bonus << endl;
							fout << courseTmp[i].total << endl;
							for (int j = 0; j < 10; ++j)
							{
								fout << atd[i][j].Date.year << " " << atd[i][j].Date.month << " " << atd[i][j].Date.day << " " << atd[i][j].startTime.hour << " " << atd[i][j].startTime.minute << " " << atd[i][j].endTime.hour << " " << atd[i][j].endTime.minute << " " << atd[i][j].attendance << endl;
							}
							fout << courseTmp[i].isActive;
						}
						break;
					}
					else {
						cout << "Check in failed!" << endl;
						break;
					}
				}
				else {
					cout << "Check in failed!" << endl;
					break;
				}
			}
		}
	}
	system("pause");
	system("CLS");

	delete[] courseTmp;
	delete[] atd;
}
void viewCheckin(Student& student) {
	string CourseClass, course;
	int n;
	ifstream fin;
	ofstream fout;

	//LET USER ENTER CLASS AND COURSE NAME
	cin.ignore(1000, '\n');
	cout << "Enter the class: ";
	getline(cin, CourseClass, '\n');
	cout << "Enter the course: ";
	getline(cin, course, '\n');

	//OPEN COURSE FILE
	fin.open("Data/Courses/2019-2020-HK2-" + CourseClass + "-" + course + "-Student-Attendance.txt");
	if (!fin.is_open())
	{
		cout << "Cannot open the file!" << endl;
		return;
	}
	fin >> n;
	Course* courseTmp = new Course[n];
	Attendance** atd = new Attendance * [n];
	for (int i = 0; i < n; i++) {
		atd[i] = new Attendance[11];
	}
	for (int i = 0; i < n; ++i)
	{
		readAttendance(fin, courseTmp, atd, i);
	}
	fin.close();

	string ID;
	ID = student.id;

	cout << endl;
	for (int i = 0; i < n; i++) {
		if (courseTmp[i].student.id == ID) {
			for (int j = 0; j < 10; ++j)
			{
				if (atd[i][j].attendance == 1) {
					cout << "Week " << j + 1 << ": Checked" << endl;
				}
				else {
					cout << "Week " << j + 1 << ": Not Checked" << endl;
				}
			}
			cout << endl;
			break;
		}
	}
	delete[] courseTmp;
	delete[] atd;
}