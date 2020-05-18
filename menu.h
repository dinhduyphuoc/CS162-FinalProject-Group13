#include "functions.h"

//Login section
void LoadStaff(ifstream& fin, Staff*& staff, int n); // Load Staffs info
void LoadLecturer(ifstream& fin, Lecturer*& lecturer, int n); // Load Lecturers info
void LoadStudent(ifstream& fin, Student*& student, int n); // // Load Students info
int Login(Staff*& staff, Staff& staffTmp, Lecturer*& lecturer, Lecturer& lecturerTmp, Student*& student, Student& studentTmp, int nStaff, int nLecturer, int nStudent);

//Change password section
void ChangePasswdStaff(Staff*& staff, Staff& staffTmp);
void ChangePasswdLecturer(Lecturer*& lecturer, Lecturer& lecturerTmp);
void ChangePasswdStudent(Student*& student, Student& studentTmp);


//View info section
void ViewInfo(Staff& staffTmp);
void ViewInfo(Lecturer& lecturerTmp);
void ViewInfo(Student& studentTmp);

//Log out section
void Logout();

//Main menu section
void mainMenu(Lecturer*& lecturer, Lecturer& lecturerTmp);
void mainMenu(Student*& student, Student& studentTmp);
void mainMenu(Staff*& staff, Staff& staffTmp);

//Staffs section
void StaffMenu(Staff*& staff, Staff& staffTmp);
void StaffMenuClass(Staff*& staff, Staff& staffTmp);
void StaffMenuCourse(Staff*& staff, Staff& staffTmp);
void StaffMenuScoreboard(Staff*& staff, Staff& staffTmp);
void StaffMenuAttendance(Staff*& staff, Staff& staffTmp);

void LoadCourse(ifstream& fin, Course*& course, int n);

//Lecturers Section
void LecturerMenu(Lecturer*& lecturer, Lecturer& lecturerTmp);

//Students section
void StudentMenu(Student*& student, Student& studentTmp);
