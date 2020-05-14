#include "functions.h"


//Login section
void LoadStaff(ifstream& fin, Staff*& staff, int n); // Load Staffs info
void LoadLecturer(ifstream& fin, Lecturer*& lecturer, int n); // Load Lecturers info
void LoadStudent(ifstream& fin, Student*& student, int n); // // Load Students info
int Login(Staff*& staff, Staff& staffTmp, Lecturer*& lecturer, Lecturer& lecturerTmp, Student*& student, Student& studentTmp, int nStaff, int nLecturer, int nStudent);

//Change password section
void ChangePasswdStaff(Staff& staff);

//View info section
void ViewInfo(Staff& staff);
void ViewInfo(Lecturer& lecturer);
void ViewInfo(Student& student);

//Log out section
void Logout();

//Main menu section
void mainMenu(Lecturer& lecturer);
void mainMenu(Student& student);
void mainMenu(Staff& staff);

//Staffs section
void StaffMenu(Staff& staff);
void StaffMenuClass(Staff& staff);
void StaffMenuCourse(Staff& staff);
void StaffMenuScoreboard(Staff& staff);
void StaffMenuAttendance(Staff& staff);

//Lecturers Section
void LecturerMenu(Lecturer& lecturer);

//Students section
void StudentMenu(Student& student);
