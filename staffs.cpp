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