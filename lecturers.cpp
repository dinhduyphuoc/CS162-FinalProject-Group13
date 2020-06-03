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
void editAttendance() {
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
	string ID;
	int check, day, month, year, choose;
	cout << "Enter student's ID: ";
	cin >> ID;
	cout << "Enter the date (ex:8 9 2020): ";
	cin >> day >> month >> year;
	for (int i = 0; i < n; i++) {
		if (courseTmp[i].student.id == ID) {
			for (int j = 0; j < 10; j++) {
				if (atd[i][j].Date.day == day && atd[i][j].Date.month == month && atd[i][j].Date.year == year) {
					cout << "Enter 1 to check in or enter -1 to check absent!" << endl;
					cin >> check;
					atd[i][j].attendance = check;
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
					cout << "Edit successfully!" << endl;
					cout << "Enter 1 to edit more, enter 0 to back to menu:" << endl;
					cin >> choose;
					if (choose == 1) {
						editAttendance();
					}
					else break;
				}
			}

		}
	}
	delete[] courseTmp;
	delete[] atd;
	system("pause");
	system("CLS");
}
void editScore() {
	ifstream fin;
	Scoreboard* board;
	string Class, course, ID;
	int n;
	cin.ignore();
	cout << "Enter class: ";
	getline(cin, Class, '\n');
	cout << "Enter course: ";
	getline(cin, course, '\n');
	float mid, Final, bonus, total;
	cout << "Enter ID of a student which you want to edit score: ";
	cin >> ID;
	cout << "Enter: " << endl;
	cout << "Midterm: ";
	cin >> mid;
	cout << "Final: ";
	cin >> Final;
	cout << "Bonus: ";
	cin >> bonus;
	cout << "Total: ";
	cin >> total;
	string filename = "Data/Scoreboards/" + Class + "-" + course + "-Scoreboard.txt";
	fin.open(filename);
	if (!fin.is_open()) {
		cout << "Cannot open the file!";
		return;
	}
	fin >> n;
	board = new Scoreboard[n];
	readScoreboard(fin, board, n);
	fin.close();
	for (int i = 0; i < n; i++) {
		if (board[i].ID == ID) {
			board[i].Midterm = mid;
			board[i].Final = Final;
			board[i].Bonus = bonus;
			board[i].Total = total;
		}
	}
	cout << "ID\tStudent name\tMidterm\tFinal\tBonus\tTotal" << endl;
	for (int i = 0; i < n; i++) {
		cout << board[i].ID << '\t' << board[i].name << '\t' << board[i].Midterm << '\t' << board[i].Final << '\t' << board[i].Bonus << '\t' << board[i].Total << endl;
	}
	cout << endl;
	system("pause");
	system("CLS");
	delete[] board;
}
void importScoreboardCSV() {
	Scoreboard* board;
	string address, CourseClass, course;
	ifstream fin;
	int n;
	ofstream fout;

	//LET USER ENTER CLASS, COURSE AND ADDRESS
	cin.ignore(1000, '\n');
	cout << "Enter the class: ";
	getline(cin, CourseClass, '\n');
	cout << "Enter the course: ";
	getline(cin, course, '\n');
	cout << "Enter file address you want to import: ";
	getline(cin, address, '\n');

	//OPEN IMPORT FILE
	fin.open(address);
	if (!fin.is_open()) {
		cout << "Cannot open the file!";
		return;
	}
	int nImport = noOfRows(address);
	board = new Scoreboard[nImport];
	importScoreboardCSV(fin, board);
	fin.close();

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

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < nImport; j++) {
			if (courseTmp[i].student.id == board[j].ID) {
				courseTmp[i].midterm = board[j].Midterm;
				courseTmp[i].final = board[j].Final;
				courseTmp[i].bonus = board[j].Bonus;
				courseTmp[i].total = board[j].Total;
			}
		}
	}

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
	fout.close();

	delete[] courseTmp;
	delete[] atd;
	delete[] board;
}