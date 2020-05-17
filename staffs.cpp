#include "functions.h"
#include "menu.h"

void ImportStudents() {
	cout << "Import students of a class from a text file" << endl;
	cout << endl;

	int nImport, n;
	ifstream fin;
	ofstream fout;
	string address;
	string Class;
	Student* studentImport;
	Student* student;

	cout << "Class: ";
	cin.ignore(1000, '\n');
	getline(cin, Class, '\n');
	cout << "File address: ";
	getline(cin, address, '\n');
	fin.open(address);
	if (!fin.is_open()) {
		cout << "Cannot open the file!";
	}
	fin >> nImport;
	studentImport = new Student[nImport];
	LoadStudent(fin, studentImport, nImport);
	fin.close();

	fin.open("Data/Classes/Student-" + Class + ".txt");
	if (!fin.is_open()) {
		cout << "Cannot open the file!";
	}
	fin >> n;
	student = new Student[n + nImport];
	LoadStudent(fin, student, n);
	fin.close();
	for (int i = n; i < n + nImport; i++) {
		int j = 0;
		student[i].id = studentImport[j].id;
		student[i].password = studentImport[j].password;
		student[i].fullName = studentImport[j].fullName;
		student[i].birthday = studentImport[j].birthday;
		student[i].Class = studentImport[j].Class;
		student[i].isActive = studentImport[j].isActive;
		j++;
	}
	fout.open("Data/Classes/Student-" + Class + ".txt");
	if (!fout.is_open()) {
		cout << "Cannot open the file!";
	}
	fout << n + nImport;
	for (int i = 0; i < n + nImport; i++) {
		fout << endl;
		fout << endl;
		fout << student[i].id << endl;
		fout << student[i].birthday.year << setw(2) << setfill('0') << student[i].birthday.month << setw(2) << setfill('0') << student[i].birthday.day << endl;
		fout << student[i].fullName << endl;
		fout << student[i].birthday.year << " " << setw(2) << setfill('0') << student[i].birthday.month << " " << setw(2) << setfill('0') << student[i].birthday.day << endl;
		fout << student[i].Class << endl;
		fout << student[i].isActive;
	}
	fout.close();
	cout << endl;
	cout << endl;
	cout << "Imported successfully!" << endl;
	system("pause");
	system("CLS");
	delete[] studentImport;
	delete[] student;
}
void AddStudentManually() {

	Student studentTmp;
	Student* student;

	cout << "Manually add a student to a class" << endl;
	cout << endl;

	ifstream fin;
	ofstream fout;
	int n;

	cout << "Classes list: " << endl;

	fin.open("Data/Classes/Class.txt");
	if (!fin.is_open()) {
		cout << "Cannot open the file!" << endl;
	}
	fin >> n;
	string* tmp = new string[n];
	for (int i = 0; i < n; i++) {
		fin >> tmp[i];
		cout << i + 1 << " " << tmp[i] << endl;
	}
	fin.close();

	fin.open("Data/Student.txt");
	if (!fin.is_open()) {
		cout << "Cannot open the file!";
	}
	fin >> n;
	student = new Student[n + 1];
	LoadStudent(fin, student, n);
	fin.close();

	cin.ignore();
	cout << "Enter student's class: ";
	getline(cin, studentTmp.Class, '\n');
	cout << "ID: ";
	getline(cin, studentTmp.id, '\n');
	for (int i = 0; i < n; i++) {
		while (studentTmp.id.compare(student[i].id) == 0) {
			cout << "ID existed, please try again." << endl;
			cout << "ID: ";
			getline(cin, studentTmp.id, '\n');
		}
	}
	cout << "Full name: ";
	getline(cin, studentTmp.fullName, '\n');
	cout << "Date of birth (yyyy/mm/dd): ";
	cin >> studentTmp.birthday.year >> studentTmp.birthday.month >> studentTmp.birthday.day;

	fout.open("Data/Student.txt");
	if (!fout.is_open()) {
		cout << "Cannot open the file!";
	}
	fout << n + 1;
	for (int i = 0; i < n; i++) {
		fout << endl;
		fout << endl;
		fout << student[i].id << endl;
		fout << student[i].birthday.year << setw(2) << setfill('0') << student[i].birthday.month << setw(2) << setfill('0') << student[i].birthday.day << endl;
		fout << student[i].fullName << endl;
		fout << student[i].birthday.year << " " << setw(2) << setfill('0') << student[i].birthday.month << " " << setw(2) << setfill('0') << student[i].birthday.day << endl;
		fout << student[i].Class << endl;
		fout << student[i].isActive;
	}
	fout << endl;
	fout << endl;
	fout << studentTmp.id << endl;
	fout << studentTmp.birthday.year << setw(2) << setfill('0') << studentTmp.birthday.month << setw(2) << setfill('0') << studentTmp.birthday.day << endl;
	fout << studentTmp.fullName << endl;
	fout << studentTmp.birthday.year << " " << setw(2) << setfill('0') << studentTmp.birthday.month << " " << setw(2) << setfill('0') << studentTmp.birthday.day << endl;
	fout << studentTmp.Class << endl;
	fout << 1;

	fout.close();

	fin.open("Data/Classes/Student-" + studentTmp.Class + ".txt");
	if (!fin.is_open()) {
		cout << "Cannot open the file!";
	}

	fin >> n;

	student = new Student[n + 1];

	LoadStudent(fin, student, n);
	fin.close();

	fout.open("Data/Classes/Student-" + studentTmp.Class + ".txt");
	if (!fout.is_open()) {
		cout << "Cannot open the file!";
	}

	fout << n + 1;

	for (int i = 0; i < n; i++) {
		fout << endl;
		fout << endl;
		fout << student[i].id << endl;
		fout << student[i].birthday.year << setw(2) << setfill('0') << student[i].birthday.month << setw(2) << setfill('0') << student[i].birthday.day << endl;
		fout << student[i].fullName << endl;
		fout << student[i].birthday.year << " " << setw(2) << setfill('0') << student[i].birthday.month << " " << setw(2) << setfill('0') << student[i].birthday.day << endl;
		fout << student[i].Class << endl;
		fout << student[i].isActive;
	}
	fout << endl;
	fout << endl;
	fout << studentTmp.id << endl;
	fout << studentTmp.birthday.year << setw(2) << setfill('0') << studentTmp.birthday.month << setw(2) << setfill('0') << studentTmp.birthday.day << endl;
	fout << studentTmp.fullName << endl;
	fout << studentTmp.birthday.year << " " << setw(2) << setfill('0') << studentTmp.birthday.month << " " << setw(2) << setfill('0') << studentTmp.birthday.day << endl;
	fout << studentTmp.Class << endl;
	fout << 1;

	cout << endl;
	cout << "Student added successfully!" << endl;
	system("pause");
	system("CLS");
	delete[] tmp;
	delete[] student;
}
void ChangeClass() {
	string ID, Class, classtemp;
	Student temp;
	cout << "Enter student's ID: ";
	cin.ignore();
	getline(cin, ID, '\n');
	cout << "Enter new class: ";
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
		if (student[i].id == ID) {
			if (student[i].Class == Class) {
				cout << "The class hasn't been changed!" << endl;
				system("pause");
				system("CLS");
				return;
			}
			classtemp = student[i].Class;
			student[i].Class = Class;
			temp = student[i];
		}
	}
	fout.open("Data/Student.txt");
	if (!fout.is_open()) {
		cout << "Cannot open the file!" << endl;
	}
	fout << n;
	for (int i = 0; i < n; i++) {
		fout << endl;
		fout << endl;
		fout << student[i].id << endl;
		fout << student[i].Class << endl;
		fout << student[i].fullName << endl;
		fout << student[i].birthday.year << " " << setw(2) << setfill('0') << student[i].birthday.month << " " << setw(2) << setfill('0') << student[i].birthday.day << endl;
		fout << student[i].Class << endl;
		fout << student[i].isActive;
	}
	fout.close();
	fin.open("Data/Classes/Student-" + temp.Class + ".txt");
	
	if (!fin.is_open()) {
		cout << "Cannot open the file!" << endl;

		return;
	}
	fin >> n;
	Student* studenttemp = new Student[n];
			for (int i = 0; i < n; i++) {
				fin.ignore(1000, '\n');
				fin.get();
				getline(fin, studenttemp[i].id);
				getline(fin, studenttemp[i].password);
				getline(fin, studenttemp[i].fullName);
				fin >> studenttemp[i].birthday.year >> studenttemp[i].birthday.month >> studenttemp[i].birthday.day;
				fin.ignore(1000, '\n');
				getline(fin, studenttemp[i].Class);
				fin >> studenttemp[i].isActive;
			}
			n++;
			fin.close();
			fout.open("Data/Classes/Student-" + temp.Class + ".txt");
			if (!fout.is_open()) {
				cout << "Cannot open the file!" << endl;
			}
			fout << n;
			for (int i = 0; i < n-1; i++) {
				fout << endl;
				fout << endl;
				fout << studenttemp[i].id << endl;
				fout << studenttemp[i].password << endl;
				fout << studenttemp[i].fullName << endl;
				fout << studenttemp[i].birthday.year << " " << setw(2) << setfill('0') << studenttemp[i].birthday.month << " " << setw(2) << setfill('0') << studenttemp[i].birthday.day << endl;
				fout << studenttemp[i].Class << endl;
				fout << studenttemp[i].isActive;
			}
			fout << endl;
			fout << endl;
			fout << temp.id << endl;
			fout << temp.password << endl;
			fout << temp.fullName << endl;
			fout << temp.birthday.year << " " << setw(2) << setfill('0') << temp.birthday.month << " " << setw(2) << setfill('0') << temp.birthday.day << endl;
			fout << temp.Class << endl;
			fout << temp.isActive;
			fout.close();

	fin.open("Data/Classes/Student-" + classtemp + ".txt");
	if (!fin.is_open()) {
		cout << "Cannot open the file!" << endl;
		return;
	}
	fin >> n;
	Student* studenttemp1 = new Student[n];
	for (int i = 0; i < n; i++) {
		fin.ignore(1000, '\n');
		fin.get();
		getline(fin, studenttemp1[i].id, '\n');
		getline(fin, studenttemp1[i].password, '\n');
		getline(fin, studenttemp1[i].fullName, '\n');
		fin >> studenttemp1[i].birthday.year >> studenttemp1[i].birthday.month >> studenttemp1[i].birthday.day;
		fin.ignore(1000, '\n');
		getline(fin, studenttemp1[i].Class, '\n');
		fin >> studenttemp1[i].isActive;
	}
	--n;
	fin.close();
	
	fout.open("Data/Classes/Student-" + classtemp + ".txt");
	if (!fout.is_open()) {
		cout << "Cannot open the file!" << endl;
	}
	fout << n;
	for (int i = 0; i < n+1; i++) {
		if (studenttemp1[i].id != temp.id) {
			fout << endl;
			fout << endl;
			fout << studenttemp1[i].id << endl;
			fout << studenttemp1[i].password << endl;
			fout << studenttemp1[i].fullName << endl;
			fout << studenttemp1[i].birthday.year << " " << setw(2) << setfill('0') << studenttemp[i].birthday.month << " " << setw(2) << setfill('0') << studenttemp[i].birthday.day << endl;
			fout << studenttemp1[i].Class << endl;
			fout << studenttemp1[i].isActive;
		}
	}
	fout.close();
	cout << endl;
	cout << endl;
	cout << "Class changed successfully!" << endl;
	system("pause");
	system("CLS");
	delete[] student;
	//con đĩ
}
