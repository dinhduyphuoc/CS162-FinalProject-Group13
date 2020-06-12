#include "functions.h"
#include "menu.h"

//Login section
void LoadStaff(ifstream& fin, Staff*& staff, int n) {
	for (int i = 0; i < n; i++) {
		fin.ignore(1000, '\n');
		fin.get();
		getline(fin, staff[i].username);
		getline(fin, staff[i].password);
		getline(fin, staff[i].fullName);
		fin >> staff[i].gender;
	}
}
void LoadLecturer(ifstream& fin, Lecturer*& lecturer, int n) {
	for (int i = 0; i < n; i++) {
		fin.ignore(1000, '\n');
		fin.get();
		getline(fin, lecturer[i].username);
		getline(fin, lecturer[i].password);
		getline(fin, lecturer[i].fullName);
		getline(fin, lecturer[i].education);
		fin >> lecturer[i].gender;
	}
}
void LoadStudent(ifstream& fin, Student*& student, int n) {
	for (int i = 0; i < n; i++) {
		fin.ignore(1000, '\n');
		fin.get();
		getline(fin, student[i].id);
		getline(fin, student[i].password);
		getline(fin, student[i].fullName);
		fin >> student[i].birthday.year >> student[i].birthday.month >> student[i].birthday.day;
		fin.ignore(1000, '\n');
		getline(fin, student[i].Class);
		fin >> student[i].isActive;
	}
}
int Login(Staff*& staff, Staff& staffTmp, Lecturer*& lecturer, Lecturer& lecturerTmp, Student*& student, Student& studentTmp, int nStaff, int nLecturer, int nStudent) {
	string username;
	char password[32], a;
	int count = 0;
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	for (count = 0;;)//infinite loop
	{
		a = _getch();//stores char typed in a
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
			//check if a is numeric or alphabet
		{
			password[count] = a;//stores a in pass
			++count;
			cout << "*";
		}
		if (a == '\b' && count >= 1)//if user typed backspace
			//i should be greater than 1.
		{
			cout << "\b \b";//rub the character behind the cursor.
			--count;
		}
		if (a == '\r')//if enter is pressed
		{
			password[count] = '\0';//null means end of string.
			break;//break the loop
		}
	}
	cout << endl;

	for (int i = 0; i < nStudent; i++) {
		if (student[i].id == username && student[i].password == password) {
			studentTmp.id = student[i].id;
			studentTmp.password = student[i].password;
			studentTmp.fullName = student[i].fullName;
			studentTmp.birthday = student[i].birthday;
			studentTmp.Class = student[i].Class;
			studentTmp.isActive = student[i].isActive;
			system("CLS");
			cout << "Logged in successfully" << endl << flush;
			cout << "Welcome back, " << student[i].fullName << "! \n" << endl;
			mainMenu(student, studentTmp);
			return 1;
		}

	}

	for (int i = 0; i < nStaff; i++) {
		if (staff[i].username == username && staff[i].password == password) {
			staffTmp.username = staff[i].username;
			staffTmp.password = staff[i].password;
			staffTmp.fullName = staff[i].fullName;
			staffTmp.gender = staff[i].gender;
			system("CLS");
			cout << "Logged in successfully" << endl << flush;
			cout << "Welcome back, " << staff[i].fullName << "! \n" << endl;
			mainMenu(staff, staffTmp);
			return 2;
		}
	}

	for (int i = 0; i < nLecturer; i++) {
		if (lecturer[i].username == username && lecturer[i].password == password) {
			lecturerTmp.username = lecturer[i].username;
			lecturerTmp.password = lecturer[i].password;
			lecturerTmp.fullName = lecturer[i].fullName;
			lecturerTmp.education = lecturer[i].education;
			lecturerTmp.gender = lecturer[i].gender;
			system("CLS");
			cout << "Logged in successfully" << endl << flush;
			cout << "Welcome back, " << lecturer[i].fullName << "! \n" << endl;
			mainMenu(lecturer, lecturerTmp);
			return 3;
		}

	}

	cout << "Invalid username or password." << endl;
	Login(staff, staffTmp, lecturer, lecturerTmp, student, studentTmp, nStaff, nLecturer, nStudent);
	return 0;
}

//Change password
void ChangePasswdStaff(Staff*& staff, Staff& staffTmp) {
	string password;
	cin.ignore(1000, '\n');
	cout << "Enter old password: ";
	getline(cin, password, '\n');
	while (password.compare(staffTmp.password) != 0) {
		cout << "Your typed password doesn't match your old password, please try again" << endl;
		cout << "Enter old password: ";
		cin >> password;
	}
	cout << "Enter new password: ";
	cin >> password;

	ifstream fin;
	ofstream fout;
	int n;
	fin.open("Data/Staff.txt");
	if (!fin.is_open()) {
		cout << "Cannot open the file!" << endl;
		return;
	}
	fin >> n;
	fin.close();
	for (int i = 0; i < n; i++) {
		if (staffTmp.username == staff[i].username && staffTmp.password == staff[i].password) {
			staff[i].password = password;
		}
	}
	fout.open("Data/Staff.txt");
	if (!fout.is_open()) {
		cout << "Cannot open the file!" << endl;
	}
	fout << n;
	for (int i = 0; i < n; i++) {
		fout << endl;
		fout << endl;
		fout << staff[i].username << endl;
		fout << staff[i].password << endl;
		fout << staff[i].fullName << endl;
		fout << staff[i].gender;
	}
	fout.close();
	cout << endl;
	cout << "Password changed successfully!" << endl;
	system("pause");
	system("CLS");
}
void ChangePasswdLecturer(Lecturer*& lecturer, Lecturer& lecturerTmp) {
	string password;
	cin.ignore(1000, '\n');
	cout << "Enter old password: ";
	getline(cin, password, '\n');
	while (password.compare(lecturerTmp.password) != 0) {
		cout << "Your typed password doesn't match your old password, please try again" << endl;
		cout << "Enter old password: ";
		cin >> password;
	}
	cout << "Enter new password: ";
	cin >> password;

	ifstream fin;
	ofstream fout;
	int n;
	fin.open("Data/Lecturer.txt");
	if (!fin.is_open()) {
		cout << "Cannot open the file!" << endl;
		return;
	}
	fin >> n;
	fin.close();
	for (int i = 0; i < n; i++) {
		if (lecturerTmp.username == lecturer[i].username && lecturerTmp.password == lecturer[i].password) {
			lecturer[i].password = password;
		}
	}
	fout.open("Data/Lecturer.txt");
	if (!fout.is_open()) {
		cout << "Cannot open the file!" << endl;
	}
	fout << n;
	for (int i = 0; i < n; i++) {
		fout << endl;
		fout << endl;
		fout << lecturer[i].username << endl;
		fout << lecturer[i].password << endl;
		fout << lecturer[i].fullName << endl;
		fout << lecturer[i].gender;
	}
	fout.close();
	cout << endl;
	cout << "Password changed successfully!" << endl;
	system("pause");
	system("CLS");
}
void ChangePasswdStudent(Student*& student, Student& studentTmp) {
	string password;
	cin.ignore(1000, '\n');
	cout << "Enter old password: ";
	getline(cin, password, '\n');
	while (password.compare(studentTmp.password) != 0) {
		cout << "Your typed password doesn't match your old password, please try again" << endl;
		cout << "Enter old password: ";
		cin >> password;
	}
	cout << "Enter new password: ";
	cin >> password;

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
		if (studentTmp.id == student[i].id && studentTmp.password == student[i].password) {
			student[i].password = password;
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
		fout << student[i].password << endl;
		fout << student[i].fullName << endl;
		fout << student[i].birthday.year << " " << setw(2) << setfill('0') << student[i].birthday.month << " " << setw(2) << setfill('0') << student[i].birthday.day << endl;
		fout << student[i].Class << endl;
		fout << student[i].isActive;
	}
	fout.close();
	cout << endl;
	cout << "Password changed successfully!" << endl;
	system("pause");
	system("CLS");
}

//View info 
void ViewInfo(Staff& staff) {
	cout << "PROFILE INFORMATION" << endl;
	cout << endl;
	cout << "Username: ";
	cout << staff.username << endl;
	cout << "Fullname: ";
	cout << staff.fullName << endl;
	cout << "Gender: ";
	if (!staff.gender) cout << "Male" << endl;
	else cout << "Female" << endl;
	cout << endl;
	system("pause");
	system("CLS");
}
void ViewInfo(Lecturer& lecturer) {
	cout << "PROFILE INFORMATION" << endl;
	cout << endl;
	cout << "Username: ";
	cout << lecturer.username << endl;
	cout << "Fullname: ";
	cout << lecturer.fullName << endl;
	cout << "Gender: ";
	if (!lecturer.gender) cout << "Male" << endl;
	else cout << "Female" << endl;
	cout << "Education: ";
	cout << lecturer.education << endl;
	cout << endl;
	system("pause");
	system("CLS");
}
void ViewInfo(Student& student) {
	cout << "PROFILE INFORMATION" << endl;
	cout << endl;
	cout << "Student ID: ";
	cout << student.id << endl;
	cout << "Fullname: ";
	cout << student.fullName << endl;
	cout << "Date of birth: " << endl;
	cout << student.birthday.day << "/" << student.birthday.month << "/" << student.birthday.year << endl;
	cout << "Class: ";
	cout << student.Class;
	cout << "Gender: ";
	if (!student.isActive) cout << "Male" << endl;
	else cout << "Female" << endl;
	cout << endl;
	system("pause");
	system("CLS");
}

//Log out section
void Logout() {
	cout << "You have successfully logged out." << endl;
	return;
}

//Main menu
void mainMenu(Lecturer*& lecturer, Lecturer& lecturerTmp) {
	int option;
	cout << "MAIN MENU" << endl;
	cout << endl;
	cout << "0. Show menu" << endl;
	cout << "1. View profile info" << endl;
	cout << "2. Change password" << endl;
	cout << "3. Log out" << endl;
	cout << endl;
	cout << "Please select option (0-3): ";
	cin >> option;
	switch (option) {
	case 0:
		system("CLS");
		LecturerMenu(lecturer, lecturerTmp);
		break;
	case 1:
		system("CLS");
		ViewInfo(lecturerTmp);
		mainMenu(lecturer, lecturerTmp);
		break;
	case 2:
		system("CLS");
		ChangePasswdLecturer(lecturer, lecturerTmp);
		mainMenu(lecturer, lecturerTmp);
		break;
	case 3:
		system("CLS");
		Logout();
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}
void mainMenu(Student*& student, Student& studentTmp) {
	int option;
	cout << "MAIN MENU" << endl;
	cout << endl;
	cout << "0. Show menu" << endl;
	cout << "1. View profile info" << endl;
	cout << "2. Change password" << endl;
	cout << "3. Log out" << endl;
	cout << endl;
	cout << "Please select option (0-3): ";
	cin >> option;
	switch (option) {
	case 0:
		system("CLS");
		StudentMenu(student, studentTmp);
		break;
	case 1:
		system("CLS");
		ViewInfo(studentTmp);
		mainMenu(student, studentTmp);
		break;
	case 2:
		system("CLS");
		ChangePasswdStudent(student, studentTmp);
		mainMenu(student, studentTmp);
		break;
	case 3:
		system("CLS");
		Logout();
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}
void mainMenu(Staff*& staff, Staff& staffTmp) {
	int option;
	cout << "MAIN MENU" << endl;
	cout << endl;
	cout << "0. Show menu" << endl;
	cout << "1. View profile info" << endl;
	cout << "2. Change password" << endl;
	cout << "3. Log out" << endl;
	cout << endl;
	cout << "Please select option (0-3): ";
	cin >> option;
	switch (option) {
	case 0:
		system("CLS");
		StaffMenu(staff, staffTmp);
		break;
	case 1:
		system("CLS");
		ViewInfo(staffTmp);
		mainMenu(staff, staffTmp);
		break;
	case 2:
		system("CLS");
		ChangePasswdStaff(staff, staffTmp);
		mainMenu(staff, staffTmp);
		break;
	case 3:
		system("CLS");
		Logout();
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}

//Lecturers
void LecturerMenu(Lecturer*& lecturer, Lecturer& lecturerTmp) {
	int option;
	cout << "LECTURER MENU: " << endl;
	cout << endl;
	cout << "0. Return to main menu" << endl;
	cout << "1. View list of courses in the current semester" << endl;
	cout << "2. View list of students of a course" << endl;
	cout << "3. View attendance list of a course" << endl;
	cout << "4. Edit an attendance" << endl;
	cout << "5. Import scoreboard of a course (midterm, final, lab, bonus) from a csv file" << endl;
	cout << "6. Edit grade of a student" << endl;
	cout << "7. View a scoreboard";
	cout << endl;
	cout << "Please select option (0-7): ";
	cin >> option;
	switch (option) {
	case 0:
		system("CLS");
		mainMenu(lecturer, lecturerTmp);
		break;
	case 1:
		system("CLS");
		viewCourseofSemester();
		LecturerMenu(lecturer, lecturerTmp);
		break;
	case 2:
		system("CLS");
		viewStudentofCourse();
		LecturerMenu(lecturer, lecturerTmp);
		break;
	case 3:
		system("CLS");
		viewAttendanceList();
		LecturerMenu(lecturer, lecturerTmp);
		break;
	case 4:
		system("CLS");
		editAttendance();
		LecturerMenu(lecturer, lecturerTmp);
		break;
	case 5:
		system("CLS");
		importScoreboardCSV();
		LecturerMenu(lecturer, lecturerTmp);
		break;
	case 6:
		system("CLS");
		editScore();
		LecturerMenu(lecturer, lecturerTmp);
	case 7:
		system("CLS");
		ViewScoreboard();
		LecturerMenu(lecturer, lecturerTmp);
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}

//Students
void StudentMenu(Student*& student, Student& studentTmp) {
	int option;
	cout << "STUDENT MENU: " << endl;
	cout << "0. Return to main menu" << endl;
	cout << "1. Check-in" << endl;
	cout << "2. View check-in result" << endl;
	cout << "3. View schedules" << endl;
	cout << "4. View your scores of a course" << endl;
	cout << endl;
	cout << "Please select option (0-4): ";
	cin >> option;
	switch (option) {
	case 0:
		system("CLS");
		mainMenu(student, studentTmp);
		break;
	case 1:
		system("CLS");
		checkin(studentTmp);
		mainMenu(student, studentTmp);
		break;
	case 2:
		system("CLS");
		viewCheckin(studentTmp);
		StudentMenu(student, studentTmp);
		break;
	case 3:
		system("CLS");
		ViewSchedule();
		StudentMenu(student, studentTmp);
		break;
	case 4:
		system("CLS");
		ViewScoreOfCourse();
		mainMenu(student, studentTmp);
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}

//Staffs
void StaffMenu(Staff*& staff, Staff& staffTmp) {
	int option;
	cout << "STAFF MENU: " << endl;
	cout << endl;
	cout << "0. Return to main menu" << endl;
	cout << "1. Class management" << endl;
	cout << "2. Course management" << endl;
	cout << "3. Scoreboard management" << endl;
	cout << "4. Attendance list management" << endl;
	cout << endl;
	cout << "Please select option (0-4): ";
	cin >> option;
	switch (option) {
	case 0:
		system("CLS");
		mainMenu(staff, staffTmp);
		break;
	case 1:
		system("CLS");
		StaffMenuClass(staff, staffTmp);
		break;
	case 2:
		system("CLS");
		StaffMenuCourse(staff, staffTmp);
		break;
	case 3:
		system("CLS");
		StaffMenuScoreboard(staff, staffTmp);
		break;
	case 4:
		system("CLS");
		StaffMenuAttendance(staff, staffTmp);
		break;
	default:
		cout << "ERROR!";
		break;
	}
}
void StaffMenuClass(Staff*& staff, Staff& staffTmp) {
	int option;
	cout << "STAFF MENU - CLASS MANAGEMENT: " << endl;
	cout << endl;
	cout << "0. Return to main menu" << endl;
	cout << "1. Return to option menu" << endl;
	cout << "2. Import students of a class from file" << endl;
	cout << "3. Add a new student to a class manually" << endl;
	cout << "4. Edit an existing student" << endl;
	cout << "5. Remove a student" << endl;
	cout << "6. Change students' class" << endl;
	cout << "7. View list of classes" << endl;
	cout << "8. View list of students in a class" << endl;
	cout << endl;
	cout << "Please select option (0-8): ";
	cin >> option;
	switch (option) {
	case 0:
		system("CLS");
		mainMenu(staff, staffTmp);
		break;
	case 1:
		system("CLS");
		StaffMenu(staff, staffTmp);
		break;

	case 2:
		system("CLS");
		ImportStudents();
		StaffMenu(staff, staffTmp);
		break;
	case 3:
		system("CLS");
		AddStudentManually();
		StaffMenu(staff, staffTmp);
		break;
	case 4:
		system("CLS");
		EditStudent();
		StaffMenu(staff, staffTmp);
	case 5:
		system("CLS");
		RemoveStudent();
		StaffMenu(staff, staffTmp);
		break;
	case 6:
		system("CLS");
		ChangeClass();
		StaffMenu(staff, staffTmp);
		break;
	case 7:
		system("CLS");
		viewclass();
		system("pause");
		system("CLS");
		StaffMenu(staff, staffTmp);
		break;
	case 8:
		system("CLS");
		viewStudent();
		StaffMenu(staff, staffTmp);
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}
void StaffMenuCourse(Staff*& staff, Staff& staffTmp) {
	int option;
	cout << "STAFF MENU - COURSE MANAGEMENT: " << endl;
	cout << endl;
	cout << "0. Return to main menu" << endl;
	cout << "1. Return to option menu" << endl;
	cout << "2. Create/update/delete/view academic years (2018-2019) & semesters (Fall)" << endl;
	cout << "3. Import courses from a csv file in a semester" << endl;
	cout << "4. Add a new course manually" << endl;
	cout << "5. Edit an existing course" << endl;
	cout << "6. Remove a course" << endl;
	cout << "7. Remove a specific student from a course" << endl;
	cout << "8. Add a specific student to a course" << endl;
	cout << "9. View list of courses in the current semester" << endl;
	cout << "10. View list of students of a course" << endl;
	cout << "11. View attendance list of a course." << endl;
	cout << "12. View all lecturers" << endl;
	cout << endl;
	cout << "Please select option (0-12): ";
	cin >> option;
	switch (option) {
	case 0:
		system("CLS");
		mainMenu(staff, staffTmp);
		break;
	case 1:
		system("CLS");
		StaffMenu(staff, staffTmp);
		break;
	case 2:
		system("CLS");
		EditAcademicYears();
		StaffMenu(staff, staffTmp);
		break;
	case 3:
		system("CLS");
		ImportCourses();
		StaffMenu(staff, staffTmp);
		break;
	case 4:
		system("CLS");
		AddCourseManually();
		StaffMenu(staff, staffTmp);
		break;
	case 5:
		system("CLS");
		EditCourse();
		StaffMenu(staff, staffTmp);
		break;
	case 6:
		system("CLS");
		removeCourse();
		StaffMenu(staff, staffTmp);
		break;
	case 7:
		system("CLS");
		removeStudentfromCourse();
		StaffMenu(staff, staffTmp);
		break;
	case 8:
		system("CLS");
		AddStuToCourse();
		StaffMenu(staff, staffTmp);
		break;
	case 9:
		system("CLS");
		viewCourse();
		StaffMenu(staff, staffTmp);
		break;
	case 10:
		system("CLS");
		viewStudentofCourse();
		StaffMenu(staff, staffTmp);
		break;
	case 11:
		system("CLS");
		viewAttendanceList();
		StaffMenu(staff, staffTmp);
		break;
	case 12:
		system("CLS");
		viewAllLecturer();
		StaffMenu(staff, staffTmp);
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}
void StaffMenuScoreboard(Staff*& staff, Staff& staffTmp) {
	int option;
	cout << "STAFF MENU - COURSE MANAGEMENT: " << endl;
	cout << endl;
	cout << "0. Return to main menu" << endl;
	cout << "1. Return to option menu" << endl;
	cout << "2. Search and view the scoreboard of a course" << endl;
	cout << "3. Export a scoreboard to a csv file" << endl;
	cout << endl;
	cout << "Please select option (0-3): ";
	cin >> option;
	switch (option) {
	case 0:
		system("CLS");
		mainMenu(staff, staffTmp);
		break;
	case 1:
		system("CLS");
		StaffMenu(staff, staffTmp);
		break;
	case 2:
		system("CLS");
		ViewScoreboard();
		StaffMenu(staff, staffTmp);
		break;
	case 3:
		system("CLS");
		exportScoreboardCSV();
		StaffMenu(staff, staffTmp);
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}
void StaffMenuAttendance(Staff*& staff, Staff& staffTmp) {
	int option;
	cout << "STAFF MENU - COURSE MANAGEMENT: " << endl;
	cout << endl;
	cout << "0. Return to main menu" << endl;
	cout << "1. Return to option menu" << endl;
	cout << "2. Search and view the scoreboard of a course" << endl;
	cout << "3. Export a scoreboard to a csv file" << endl;
	cout << endl;
	cout << "Please select option (0-3): ";
	cin >> option;
	switch (option) {
	case 0:
		system("CLS");
		mainMenu(staff, staffTmp);
		break;
	case 1:
		system("CLS");
		StaffMenu(staff, staffTmp);
		break;
	case 2:
		system("CLS");
		viewAttendanceList();
		StaffMenu(staff, staffTmp);
		break;
	case 3:
		system("CLS");
		exportattendanceCSV();
		StaffMenu(staff, staffTmp);
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}
