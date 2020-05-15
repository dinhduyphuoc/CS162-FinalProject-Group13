#include "functions.h"

void ImportStudents() {
	cout << "Enter new class name: ";

}
void AddStudentManually() {
	Student tmp;
	cout << "ADD STUDENT MANUALLY" << endl;
	cout << endl;
	cin.ignore(); //Comment it if you want to check the function separately
	cout << "Enter student's id: ";
	getline(cin, tmp.id, '\n');
	cout << "Enter student's full name: ";
	getline(cin, tmp.fullName);
	cout << "Enter student's date of birth (yyyy/mm/dd): ";
	cin >> tmp.birthday.year >> tmp.birthday.month >> tmp.birthday.day;
	cin.ignore();
	cout << "Enter student's class: ";
	getline(cin, tmp.Class);
	cout << "Enter student's gender (0 - female / 1 - male): ";
	cin >> tmp.gender;
	ofstream write;
	write.open("Data/Student.txt", ios :: app);
	if (!write.is_open()) {
		cout << "Cannot open the file!" << endl;
	}
	else {
		write << endl;
		write << endl;
		write << tmp.id << endl;
		write << tmp.birthday.year << setw(2) << setfill('0') << tmp.birthday.month << setw(2) << setfill('0') << tmp.birthday.day << endl;
		write << tmp.fullName << endl;
		write << tmp.birthday.year << " " << setw(2) << setfill('0') << tmp.birthday.month << " " << setw(2) << setfill('0') << tmp.birthday.day << endl;
		write << tmp.Class << endl;
		write << tmp.gender;
		write.close();
		cout << endl;
		cout << "Student added successfully!" << endl;
		cout << "Press any key to return to menu..." << endl;
		cout << endl;
		system("pause");
		system("CLS");
	}
}
void changeClass(Student *& student) {
	string ID, Class;
	Student temp;
	cout << "Enter student's ID: ";
	cin.ignore();
	getline(cin, ID, '\n');
	cout << "Enter new class: ";
	cin.ignore();
	getline(cin, Class, '\n');
	ifstream fin;
	ofstream fout;
	int n;
	fin.open("Data/Student.txt");
	if (!fin.is_open()) {
		cout << "Cannot open the file!" << endl;
		return;
	}
	fin >> n;
	fin.close();
	for (int i = 0; i < n; i++) {
		if (student[i].Class == Class && student[i].id == ID) {
			student[i].Class = Class;
			temp = student[i];
		}
	}
	fout.open("Data/Studenttmp.txt");
	if (!fout.is_open()) {
		cout << "Cannot open the file!" << endl;
	}
	fout << n << endl;
	fout << endl;
	for (int i = 0; i < n; i++) {
		fout << student[i].id << endl;
		fout << student[i].Class << endl;
		fout << student[i].fullName << endl;
		fout << student[i].birthday.year << " " << setw(2) << setfill('0') << student[i].birthday.month << " " << setw(2) << setfill('0') << student[i].birthday.day << endl;
		fout << student[i].Class << endl;
		fout << student[i].gender;
		fout << endl;
	}
	fout.close();

	cout << endl;
	cout << "Class changed successfully!" << endl;
	system("pause");
	system("CLS");
}
void deletearr(Student arr[], int& n,int pos){
	if (n <= 0) {
		return;
	}
	if (pos < 0) {
		pos = 0;
	}
	else if (pos >= n) {
		pos = n - 1;
	}
	for (int i = pos; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	--n;
}
void appendarr(Student arr[], int& n, Student val, int pos) {
	if (pos < 0) {
		pos = 0;
	}
	else if (pos > n) {
		pos = n;
	}
	for (int i = n; i > pos; i--) {
		arr[i] = arr[i - 1];
	}
	arr[pos] = val;
	++n;
}