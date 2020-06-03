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
		getline(fin, course[i].course);
		getline(fin, course[i].courseName);
		getline(fin, course[i].Class);
		getline(fin, course[i].lecturerUser);
		getline(fin, course[i].lecturerName);
		getline(fin, course[i].education);
		fin.ignore(100, '\n');
		fin >> course[i].gender;
		fin.ignore(100, '\n');
		fin >> course[i].startDate.year >> course[i].startDate.month >> course[i].startDate.day;
		fin.ignore(100, '\n');
		fin >> course[i].endDate.year >> course[i].endDate.month >> course[i].endDate.day;
		fin.ignore(100, '\n');
		fin >> course[i].day;
		fin.ignore(100, '\n');
		fin >> course[i].startTime.hour >> course[i].startTime.minute;
		fin.ignore(100, '\n');
		fin >> course[i].endTime.hour >> course[i].endTime.minute;
		fin.ignore(1000, '\n');
		getline(fin, course[i].room);
		fin.ignore(100, '\n');
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
	fout << course[i].startDate.year << setw(2) << setfill('0') << course[i].startDate.month << setw(2) << setfill('0') << course[i].startDate.day << endl;
	fout << course[i].endDate.year << setw(2) << setfill('0') << course[i].endDate.month << setw(2) << setfill('0') << course[i].endDate.day << endl;
	fout << course[i].startTime.hour << setw(2) << setfill('0') << course[i].startTime.minute << endl;
	fout << course[i].endTime.hour << setw(2) << setfill('0') << course[i].endTime.minute << endl;
	fout << course[i].room << endl;
	fout << course[i].isActive;
}
void importStudentCSV(ifstream& fin, Student* student, int n) {
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
void importScoreboardCSV(ifstream& fin, Scoreboard* board) {
	string tmp;
	string line;
	int i = 0;
	while (getline(fin, line)) {
		stringstream ss(line);
		getline(ss, board[i].ID, ',');
		getline(ss, board[i].name, ',');
		getline(ss, tmp, ',');
		board[i].Midterm = stoi(tmp);
		getline(ss, tmp, ',');
		board[i].Final = stoi(tmp);
		getline(ss, tmp, ',');
		board[i].Bonus = stoi(tmp);
		getline(ss, tmp, '\n');
		board[i].Total = stoi(tmp);
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