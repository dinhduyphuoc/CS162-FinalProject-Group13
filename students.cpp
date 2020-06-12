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
void ViewScoreOfCourse()
{
	ifstream fin;
	string Class, course, StuID;
	int n;
	cin.ignore();
	cout << "Enter class: ";
	getline(cin, Class, '\n');
	cout << "Enter course: ";
	getline(cin, course, '\n');
	string filename = "Data/Courses/2019-2020-HK2-" + Class + "-" + course + "-Student-Attendance.txt";
	fin.open(filename);
	if (!fin.is_open()) {
		cout << "Cannot open the file!";
		return;
	}
	fin >> n;
	Course* courses = new Course[n];
	Attendance** atd = new Attendance * [n];
	for (int i = 0; i < n; i++) {
		atd[i] = new Attendance[11];
	}
	for (int i = 0; i < n; i++) {
		readAttendance(fin, courses, atd, i);
	}
	fin.close();
	cin.ignore();
	cout << "Enter your student ID: ";
	getline(cin, StuID, '\n');
	cout << "ID\t\tStudent name\t" << "     " << "Midterm\tFinal\tBonus\tTotal" << endl;
	for (int i = 0; i < n; i++)
	{
		if (courses[i].student.id == StuID)
		{
			cout << courses[i].student.id << '\t' << courses[i].student.fullName << " " << courses[i].midterm << '\t' << courses[i].final << '\t' << courses[i].bonus << '\t' << courses[i].total << endl;
		}
	}
	cout << endl;
	system("pause");
	system("CLS");
	delete[] courses;
	delete[] atd;
}
void ViewSchedule()
{
	ifstream fin;
	string Class;
	int n;
	cin.ignore();
	cout << "Enter class: ";
	getline(cin, Class, '\n');
	fin.open("Data/Courses/" + Class + "-Schedule.txt");
	if (!fin.is_open())
	{
		cout << "Can not open this file!" << endl;
		return;
	}
	else {
		fin >> n;
		Course* courses = new Course[n];
		Attendance** atd = new Attendance * [n];
		for (int i = 0; i < n; i++) {
			atd[i] = new Attendance[11];
		}
		for (int i = 0; i < n; i++) {
			fin.ignore(1000, '\n');
			fin.get();
			getline(fin, courses[i].courseName,'\n');
			for (int j = 0; j < 10; ++j)
			{
				fin >> atd[i][j].Date.year >> atd[i][j].Date.month >> atd[i][j].Date.day >> atd[i][j].startTime.hour >> atd[i][j].startTime.minute >> atd[i][j].endTime.hour >> atd[i][j].endTime.minute;
			}
			/*fin.ignore(1000, '\n');*/
		}
		fin.close();
		system("CLS");
		cout << "The " << Class << "-Schedule: " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << courses[i].courseName << endl;
			cout << "Year" << " " << "Month" << " " << "Day" << " " << "StartHour" << " " << "StartMinute" << " " << "EndHour" << " " << "EndMinute" << endl;
			for (int j = 0; j < 10; ++j)
			{
				cout << atd[i][j].Date.year << "   " << atd[i][j].Date.month << "    " << atd[i][j].Date.day << "     " << atd[i][j].startTime.hour << "        " << atd[i][j].startTime.minute << "        " << atd[i][j].endTime.hour << "        " << atd[i][j].endTime.minute << endl;
			}
			cout << endl;
		}
		cout << endl;
		system("pause");
		system("CLS");
	}
}