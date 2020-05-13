#include "functions.h"
#include "menu.h"

int main() {
	ifstream fin1, fin2, fin3;
	ofstream fout;
	int nStaff, nLecturer, nStudent;

	Staff* staff;
	Staff* staffTmp;
	Lecturer* lecturer;
	Lecturer* lecturerTmp;
	Student* student;
	Student* studentTmp;

	fin1.open("Data/Staff.txt");
	if (!fin1.is_open()) {
		cout << "Cannot open the file, please check again!" << endl;
	}
	else {
		fin1 >> nStaff;
		staff = new Staff[nStaff];
		LoadStaff(fin1, staff, nStaff);
		fin1.close();
	}
	
	fin2.open("Data/Lecturer.txt");
	if (!fin2.is_open()) {
		cout << "Cannot open the file, please check again!" << endl;
	}
	else {
		fin2 >> nLecturer;
		lecturer = new Lecturer[nLecturer];
		LoadLecturer(fin2, lecturer, nLecturer);
		fin2.close();
	}

	fin3.open("Data/Student.txt");
	if (!fin3.is_open()) {
		cout << "Cannot open the file, please check again!" << endl;
	}
	else {
		fin3 >> nStudent;
		student = new Student[nStudent];
		LoadStudent(fin3, student, nStudent);
		fin3.close();
	}

	Login(staff, staffTmp, lecturer, lecturerTmp, student, studentTmp, nStaff, nLecturer, nStudent);

	return 0;
}