#include "functions.h"
#include "menu.h"

//Login section
void LoadStaff(ifstream& fin, Staff* &staff, int n) {
	for (int i = 0; i < n; i++) {
		fin.ignore(1000, '\n');
		fin.get();
		getline(fin, staff[i].username);
		getline(fin, staff[i].password);
		getline(fin, staff[i].fullName);
		fin >> staff[i].gender;
	}
}
void LoadLecturer(ifstream& fin, Lecturer* &lecturer, int n) {
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
void LoadStudent(ifstream& fin, Student* &student, int n) {
	for (int i = 0; i < n; i++) {
		fin.ignore(1000, '\n');
		fin.get();
		getline(fin, student[i].id);
		getline(fin, student[i].password);
		getline(fin, student[i].fullName);
		fin >> student->birthday.year >> student->birthday.month >> student->birthday.day;
		fin.ignore(1000, '\n');
		getline(fin, student[i].Class);
		fin >> student[i].gender;
	}
}
int Login(Staff* &staff, Staff* &staffTmp, Lecturer* &lecturer, Lecturer*& lecturerTmp, Student* &student, Student*& studentTmp, int nStaff, int nLecturer, int nStudent) {
	string username;
	string password;
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);

	for (int i = 0; i < nStudent; i++) {
		if (student[i].id == username && student[i].password == password) {
			system("CLS");
			cout << "Logged in successfully" << endl << flush;
			cout << "Welcome back, " << student[i].fullName << "! \n" << endl;
			mainMenu(student);
			studentTmp->id = student[i].id;
			studentTmp->password = student[i].password;
			studentTmp->fullName = student[i].fullName;
			studentTmp->birthday = student[i].birthday;
			studentTmp->Class = student[i].Class;
			studentTmp->gender = student[i].gender;
			return 1;
		}

	}

	for (int i = 0; i < nStaff; i++) {
		if (staff[i].username == username && staff[i].password == password) {
			system("CLS");
			cout << "Logged in successfully" << endl << flush;
			cout << "Welcome back, " << staff[i].fullName << "! \n" << endl;
			mainMenu(staff);
			staffTmp->username = staff[i].username;
			staffTmp->password = staff[i].password;
			staffTmp->fullName = staff[i].fullName;
			staffTmp->gender = staff[i].gender;
			return 2;
		}
	}

	for (int i = 0; i < nLecturer; i++) {
		if (lecturer[i].username == username && lecturer[i].password == password) {
			system("CLS");
			cout << "Logged in successfully" << endl << flush;
			cout << "Welcome back, " << staff[i].fullName << "! \n" << endl;
			mainMenu(lecturer);
			lecturerTmp->username = lecturer[i].username;
			lecturerTmp->password = lecturer[i].password;
			lecturerTmp->fullName = lecturer[i].fullName;
			lecturerTmp->education = lecturer[i].education;
			lecturerTmp->gender = lecturer[i].gender;
			return 3;
		}

	}

	cout << "Invalid username or password." << endl;
	Login(staff, staffTmp, lecturer, lecturerTmp, student, studentTmp, nStaff, nLecturer, nStudent);
	return 0;
}

//Log out section
void Logout() {
	cout << "You have successfully logged out." << endl;
	return;
}

//Main menu
void mainMenu(Lecturer* &lecturer) {
	int option;
	cout << "MAIN MENU" << endl;
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
		LecturerMenu(lecturer);
		break;
	case 1:
		system("CLS");
		//function
		break;
	case 2:
		system("CLS");
		//function
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
void mainMenu(Student* &student) {
	int option;
	cout << "MAIN MENU" << endl;
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
		StudentMenu(student);
		break;
	case 1:
		system("CLS");
		//function
		break;
	case 2:
		system("CLS");
		//function
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
void mainMenu(Staff* &staff){
	int option;
	cout << "MAIN MENU" << endl;
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
		StaffMenu(staff);
		break;
	case 1:
		system("CLS");
		//function
		break;
	case 2:
		system("CLS");
		//function
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
void LecturerMenu(Lecturer* &lecturer) {
	int option;
	cout << "LECTURER MENU: " << endl;
	cout << "0. Return to main menu" << endl;
	cout << "1. View list of courses in the current semester" << endl;
	cout << "2. View list of students of a course" << endl;
	cout << "3. View attendance list of a course" << endl;
	cout << "4. Edit an attendance" << endl;
	cout << "5. Import scoreboard of a course (midterm, final, lab, bonus) from a csv file" << endl;
	cout << "6. Edit grade of a student";
	cout << "7. View a scoreboard";
	cout << endl;
	cout << "Please select option (0-7): ";
	cin >> option;
	switch (option) {
	case 0:
		system("CLS");
		mainMenu(lecturer);
		break;
	case 1:
		system("CLS");
		//function
		break;
	case 2:
		system("CLS");
		//function
		break;
	case 3:
		system("CLS");
		//function
		break;
	case 4:
		system("CLS");
		//function
		break;
	case 5:
		system("CLS");
		//function
		break;
	case 6:
		system("CLS");
		//function
	case 7:
		system("CLS");
		//function
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}

//Students
void StudentMenu(Student* &student) {
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
		mainMenu(student);
		break;
	case 1:
		system("CLS");
		//function
		break;
	case 2:
		system("CLS");
		//function
		break;
	case 3:
		system("CLS");
		//function
		break;
	case 4:
		system("CLS");
		//function
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}

//Staffs
void StaffMenu(Staff* &staff) {
	int option;
	cout << "STAFF MENU: " << endl;
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
		mainMenu(staff);
		break;
	case 1:
		system("CLS");
		StaffMenuClass(staff);
		break;
	case 2:
		system("CLS");
		StaffMenuCourse(staff);
		break;
	case 3:
		system("CLS");
		StaffMenuScoreboard(staff);
		break;
	case 4:
		system("CLS");
		StaffMenuAttendance(staff);
		break;
	default:
		cout << "ERROR!";
		break;
	}
}
void StaffMenuClass(Staff* &staff) {
	int option;
	cout << "STAFF MENU - CLASS MANAGEMENT: " << endl;
	cout << "0. Return to main menu" << endl;
	cout << "1. Return to option menu" << endl;
	cout << "2. Import tudents of a class from a csv file" << endl;
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
		mainMenu(staff);
		break;
	case 1:
		system("CLS");
		StaffMenu(staff);
		break;

	case 2:
		system("CLS");
		//function
		break;
	case 3:
		system("CLS");
		//function
		break;
	case 4:
		system("CLS");
		//function
		break;
	case 5:
		system("CLS");
		//function
		break;
	case 6:
		system("CLS");
		//function
		break;
	case 7:
		system("CLS");
		//function
		break;
	case 8:
		system("CLS");
		//function
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}
void StaffMenuCourse(Staff* &staff) {
	int option;
	cout << "STAFF MENU - COURSE MANAGEMENT: " << endl;
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
	cout << "12. Create / update / delete / view all lectures" << endl;
	cout << endl;
	cout << "Please select option (0-12): ";
	cin >> option;
	switch (option) {
	case 0:
		system("CLS");
		mainMenu(staff);
		break;
	case 1:
		system("CLS");
		StaffMenu(staff);
		break;
	case 2:
		system("CLS");
		//function
		break;
	case 3:
		system("CLS");
		//function
		break;
	case 4:
		system("CLS");
		//function
		break;
	case 5:
		system("CLS");
		//function
		break;
	case 6:
		system("CLS");
		//function
		break;
	case 7:
		system("CLS");
		//function
		break;
	case 8:
		system("CLS");
		//function
		break;
	case 9:
		system("CLS");
		//function
		break;
	case 10:
		system("CLS");
		//function
		break;
	case 11:
		system("CLS");
		//function
		break;
	case 12:
		system("CLS");
		//function
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}
void StaffMenuScoreboard(Staff* &staff) {
	int option;
	cout << "STAFF MENU - COURSE MANAGEMENT: " << endl;
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
		mainMenu(staff);
		break;
	case 1:
		system("CLS");
		StaffMenu(staff);
		break;
	case 2:
		system("CLS");
		//function
		break;
	case 3:
		system("CLS");
		//function
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}
void StaffMenuAttendance(Staff* &staff) {
	int option;
	cout << "STAFF MENU - COURSE MANAGEMENT: " << endl;
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
		mainMenu(staff);
		break;
	case 1:
		system("CLS");
		StaffMenu(staff);
		break;
	case 2:
		system("CLS");
		//function
		break;
	case 3:
		system("CLS");
		//function
		break;
	default:
		cout << "Invalid option, please select again: ";
		break;
	}
}
