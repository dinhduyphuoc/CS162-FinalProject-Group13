#include "functions.h"


//STUDENT MANAGEMENT - STAFF
void writeStudent(ofstream& fout, Student*& student, int i) {
	fout << endl;
	fout << endl;
	fout << student[i].id << endl;
	fout << student[i].birthday.year << setw(2) << setfill('0') << student[i].birthday.month << setw(2) << setfill('0') << student[i].birthday.day << endl;
	fout << student[i].fullName << endl;
	fout << student[i].birthday.year << " " << setw(2) << setfill('0') << student[i].birthday.month << " " << setw(2) << setfill('0') << student[i].birthday.day << endl;
	fout << student[i].Class << endl;
	fout << student[i].isActive;
}
void readAttendance(ifstream& fin, Course*& course, Attendance**& atd, int i) {
	fin.ignore(1000, '\n');
	fin.get();
	getline(fin, course[i].student.id, '\n');
	getline(fin, course[i].student.password, '\n');
	getline(fin, course[i].student.fullName, '\n');
	fin >> course[i].student.birthday.year >> course[i].student.birthday.month >> course[i].student.birthday.day;
	fin.ignore(1000, '\n');
	getline(fin, course[i].Class, '\n');
	fin >> course[i].isActive;
	fin.ignore(1000, '\n');
	fin >> course[i].midterm;
	fin.ignore(1000, '\n');
	fin >> course[i].final;
	fin.ignore(1000, '\n');
	fin >> course[i].bonus;
	fin.ignore(1000, '\n');
	fin >> course[i].total;
	fin.ignore(1000, '\n');
	for (int j = 0; j < 10; ++j)
	{
		fin >> atd[i][j].Date.year >> atd[i][j].Date.month >> atd[i][j].Date.day >> atd[i][j].startTime.hour >> atd[i][j].startTime.minute >> atd[i][j].endTime.hour >> atd[i][j].endTime.minute >> atd[i][j].attendance;
	}
	fin.ignore(1000, '\n');
	fin >> course[i].isActive;
}
void LoadCourse(ifstream& fin, Course*& course, int n) {
	for (int i = 0; i < n; ++i) {
		fin.ignore(1000, '\n');
		fin.get();
		getline(fin, course[i].course, '\n');
		getline(fin, course[i].courseName, '\n');
		getline(fin, course[i].Class, '\n');
		getline(fin, course[i].lecturerUser, '\n');
		getline(fin, course[i].lecturerName, '\n');
		getline(fin, course[i].education, '\n');
		fin >> course[i].gender;
		fin.ignore(1000, '\n');
		fin >> course[i].startDate.year >> course[i].startDate.month >> course[i].startDate.day;
		fin >> course[i].endDate.year >> course[i].endDate.month >> course[i].endDate.day;
		fin >> course[i].day;
		fin >> course[i].startTime.hour >> course[i].startTime.minute;
		fin >> course[i].endTime.hour >> course[i].endTime.minute;
		fin.ignore(10000, '\n');
		getline(fin, course[i].room, '\n');
		fin >> course[i].isActive;
	}
}
void writeCourse(ofstream& fout, Course*& course, int i) {
	fout << course[i].course << endl;
	fout << course[i].courseName << endl;
	fout << course[i].Class << endl;
	fout << course[i].lecturerUser << endl;
	fout << course[i].lecturerName << endl;
	fout << course[i].education << endl;
	fout << course[i].gender << endl;
	fout << course[i].startDate.year << " " << course[i].startDate.month << " " << course[i].startDate.day << endl;
	fout << course[i].endDate.year << " " << course[i].endDate.month << " " << course[i].endDate.day << endl;
	fout << course[i].day << endl;
	fout << course[i].startTime.hour << " " << course[i].startTime.minute << endl;
	fout << course[i].endTime.hour << " " << course[i].endTime.minute << endl;
	fout << course[i].room << endl;
	fout << course[i].isActive;
}
void importCourseCSV(ifstream& fin, Course* course) {
	string tmp;
	string line;
	int i = 0;
	while (getline(fin, line)) {
		stringstream ss(line);
		getline(ss, course[i].course, ',');
		getline(ss, course[i].courseName, ',');
		getline(ss, course[i].Class, ',');
		getline(ss, course[i].lecturerUser, ',');
		getline(ss, course[i].lecturerName, ',');
		getline(ss, course[i].education, ',');
		getline(ss, tmp, ',');
		course[i].gender = stoi(tmp);
		getline(ss, tmp, '/');
		course[i].startDate.day = stoi(tmp);
		getline(ss, tmp, '/');
		course[i].startDate.month = stoi(tmp);
		getline(ss, tmp, ',');
		course[i].startDate.year = stoi(tmp);
		getline(ss, tmp, '/');
		course[i].endDate.day = stoi(tmp);
		getline(ss, tmp, '/');
		course[i].endDate.month = stoi(tmp);
		getline(ss, tmp, ',');
		course[i].endDate.year = stoi(tmp);
		getline(ss, tmp, ',');
		course[i].day = stoi(tmp);
		getline(ss, tmp, ',');
		course[i].startTime.hour = stoi(tmp);
		getline(ss, tmp, ',');
		course[i].startTime.minute = stoi(tmp);
		getline(ss, tmp, ',');
		course[i].endTime.hour = stoi(tmp);
		getline(ss, tmp, ',');
		course[i].endTime.minute = stoi(tmp);
		getline(ss, course[i].room, ',');
		getline(ss, tmp, '\n');
		course[i].isActive = stoi(tmp);
		i++;
	}
}
void importStudentCSV(ifstream& fin, Student* student) {
	string tmp;
	string line;
	int i = 0;
	while (getline(fin, line)) {
		stringstream ss(line);
		getline(ss, student[i].id, ',');
		getline(ss, student[i].fullName, ',');
		getline(ss, tmp, '/');
		student[i].birthday.day = stoi(tmp);
		getline(ss, tmp, '/');
		student[i].birthday.month = stoi(tmp);
		getline(ss, tmp, ',');
		student[i].birthday.year = stoi(tmp);
		getline(ss, student[i].Class, ',');
		getline(ss, tmp, '\n');
		student[i].isActive = stoi(tmp);
		i++;
	}
}
void importAttendanceCSV(ifstream& fin, Attendance* atd) {
	string tmp;
	string line;
	int i = 0;
	while (getline(fin, line)) {
		stringstream ss(line);
		getline(ss, tmp, ',');
		atd[i].Date.year = stoi(tmp);
		getline(ss, tmp, ',');
		atd[i].Date.month = stoi(tmp);
		getline(ss, tmp, ',');
		atd[i].Date.day = stoi(tmp);
		getline(ss, tmp, ',');
		atd[i].startTime.hour = stoi(tmp);
		getline(ss, tmp, ',');
		atd[i].startTime.minute = stoi(tmp);
		getline(ss, tmp, ',');
		atd[i].endTime.hour = stoi(tmp);
		getline(ss, tmp, ',');
		atd[i].endTime.minute = stoi(tmp);
		getline(ss, tmp, '\n');
		atd[i].attendance = stoi(tmp);
		i++;
	}
}
void importScoreboardCSV(ifstream& fin, Scoreboard* board) {
	string tmp;
	string line;
	int i = 0;
	while (getline(fin, line)) {
		stringstream ss(line);
		getline(ss, board[i].ID, ',');
		getline(ss, board[i].name, ',');
		getline(ss, tmp, ',');
		board[i].Midterm = stof(tmp);
		getline(ss, tmp, ',');
		board[i].Final = stof(tmp);
		getline(ss, tmp, ',');
		board[i].Bonus = stof(tmp);
		getline(ss, tmp, '\n');
		board[i].Total = stof(tmp);
		i++;
	}
}
void readScoreboard(ifstream& fin, Scoreboard* board, int n) {
	for (int i = 0; i < n; i++) {
		fin.ignore(1000, '\n');
		fin.get();
		getline(fin, board[i].ID, '\n');
		getline(fin, board[i].name, '\n');
		//fin.ignore(1000, '\n');
		fin >> board[i].Midterm >> board[i].Final >> board[i].Bonus >> board[i].Total;
	}
}
int noOfRows(string address) {
	ifstream file(address);
	string data;
	int count = 0;
	while (getline(file, data)) {
		count++;
	}
	return count;
} //COUNT NUMBERS OF ROW IN CSV FILE