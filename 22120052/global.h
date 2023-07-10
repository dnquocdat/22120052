#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <thread>
#include <cctype>
#define ESC 27
using namespace std;
struct Date {
    int d;
    int m;
    int y;
    string wDay;
};
struct sinhvien {
    string no;
    string studentid;
    string firstname;
    string lastname;
    string gender;
    Date birth;
    string socialid;
    int academicYear;
};
struct staff {
    string staffid;
    string firstname;
    string lastname;
    string gender;
    Date birth;
};
struct NodeUser {
    sinhvien sv;
    NodeUser* next;
};
typedef struct NodeUser* nodeuser;
struct NodeStaff {
    staff sf;
    NodeStaff* next;
};
typedef struct NodeStaff* nodestaff;
struct Course {
    string id;
    string courseName;
    string teacherName;
    int credits;
    int maxStudents = 50;
    int numberRegistered = 0;
    int academicYear;
    string wDay;
    string session;
    Course* next;
};
struct NodeCourse {
    Course cour;
    NodeCourse* next;
    Date startDate, endDate;
};
typedef struct NodeCourse* nodecourse;
struct ListClass {
    string program;
    string className;
    string year;
    int academicYear;
    int size;
};
struct CourseMark {
    float otherMark = 0;
    float midtermMark = 0;
    float finalMark = 0;
    float totalMark = 0;
};
struct SemesterMark {
    float GPA = 0;
    float overallGPA = 0;
};
struct Semester {
    int semester;
    Date startDate, endDate;
};

