#include "staff.h"
int dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y / 4 - y / 100 +
        y / 400 + t[m - 1] + d) % 7;
}
Date strToDate(string str) {
    Date date;
    date.d = stoi(str.substr(0, str.find('/')));
    str.erase(0, str.find('/') + 1);
    date.m = stoi(str.substr(0, str.find('/')));
    str.erase(0, str.find('/') + 1);
    date.y = stoi(str.substr(0, str.find('/')));
    str.erase(0, str.find('/') + 1);
    string wDay;
    switch (dayofweek(date.d, date.m, date.y)) {
    case 0:
        wDay = "Sun";
        break;
    case 1:
        wDay = "Mon";
        break;
    case 2:
        wDay = "Tue";
        break;
    case 3:
        wDay = "Wed";
        break;
    case 4:
        wDay = "Thu";
        break;
    case 5:
        wDay = "Fri";
        break;
    case 6:
        wDay = "Sat";
        break;
    }
    date.wDay = wDay;
    return date;
}
string dateToStr(Date date) {
    string str = "";
    if (date.d < 10) str += "0";
    str += to_string(date.d) + "/";
    if (date.m < 10) str += "0";
    str += to_string(date.m) + "/";
    str += to_string(date.y);
    return str;
}
nodeuser makelistuser(sinhvien sv) {
    nodeuser temp = new NodeUser();
    temp->sv = sv;
    temp->next = NULL;
    return temp;
}
nodestaff makeliststaff(staff sf) {
    nodestaff temp = new NodeStaff();
    temp->sf = sf;
    temp->next = NULL;
    return temp;
}
nodecourse makelistcourse(Course cour) {
    nodecourse temp = new NodeCourse();
    temp->cour = cour;
    temp->next = NULL;
    return temp;
}
void addUser(nodeuser& dataUser, sinhvien sv) {
    nodeuser temp = makelistuser(sv);
    if (dataUser == NULL) {
        dataUser = temp;
    }
    else {
        nodeuser p = dataUser;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }
}
void addStaff(nodestaff& dataStaff, staff sf) {
    nodestaff temp = makeliststaff(sf);
    if (dataStaff == NULL) {
        dataStaff = temp;
    }
    else {
        nodestaff p = dataStaff;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }
}
sinhvien doc_thongtin_1_sinhvien(ifstream& r) {
    sinhvien sv;
    getline(r, sv.no, ';');
    getline(r, sv.studentid, ';');
    getline(r, sv.lastname, ';');
    getline(r, sv.firstname, ';');
    getline(r, sv.gender, ';');
    char x;
    r >> sv.birth.d;
    r >> x;
    r >> sv.birth.m;
    r >> x;
    r >> sv.birth.y;
    r >> x;
    getline(r, sv.socialid);
    return sv;
}
staff doc_thongtin_1_staff(ifstream& r) {
    staff sf;
    getline(r, sf.staffid, ';');
    getline(r, sf.lastname, ';');
    getline(r, sf.firstname, ';');
    getline(r, sf.gender, ';');
    char x;
    r >> sf.birth.d;
    r >> x;
    r >> sf.birth.m;
    r >> x;
    r >> sf.birth.y;
    r >> x;
    return sf;
}
void doc_danhsach_thongtin_sinhvien(ifstream& r, nodeuser& dataUser, string fileclass) {
    r.open(fileclass, ios::in);
    while (!r.eof()) {
        sinhvien sv = doc_thongtin_1_sinhvien(r);
        addUser(dataUser, sv);
    }
    r.close();
}
//staff
void doc_danhsach_thongtin_staff(ifstream& r, nodestaff& dataStaff, string filedata) {
    r.open(filedata, ios::in);
    while (!r.eof()) {
        staff sf = doc_thongtin_1_staff(r);
        addStaff(dataStaff, sf);
    }
    r.close();
}
void xuat_danhsach_thongtin_sinhvien(nodeuser dataUser) {
    nodeuser p = dataUser;
    cout << setfill(' ') << setw(5) << left << "No" << "| "
        << setfill(' ') << setw(15) << left << "Student ID" << "| "
        << setfill(' ') << setw(20) << left << "Last Name" << "| "
        << setfill(' ') << setw(15) << left << "First Name" << "| "
        << setfill(' ') << setw(10) << left << "Gender" << "| "
        << setfill(' ') << setw(15) << left << "Date of Birth" << "| "
        << setfill(' ') << setw(15) << left << "Social ID" << endl;
    if (p == NULL)
        return;
    else {
        while (p != NULL) {
            cout << setfill(' ') << setw(5) << left << p->sv.no << "| "
                << setfill(' ') << setw(15) << left << p->sv.studentid << "| "
                << setfill(' ') << setw(20) << left << p->sv.lastname << "| "
                << setfill(' ') << setw(15) << left << p->sv.firstname << "| "
                << setfill(' ') << setw(10) << left << p->sv.gender << "| "
                << setfill(' ') << setw(15) << left << dateToStr(p->sv.birth) << "| "
                << setfill(' ') << setw(15) << left << p->sv.socialid << endl;
            p = p->next;
        }
    }
}
void ghi_file_danhsach(ofstream& w, nodeuser dataUser, string path) {
    nodeuser p = dataUser;
    if (p == NULL)
        return;
    else {
        w.open("C:/Users/Administrator/Documents/Data/2022-2023/" + path + ".csv", ios::out);
        while (p != NULL) {
            w << p->sv.no << ';' << p->sv.studentid << ';' << p->sv.lastname << ';' << p->sv.firstname << ';' << p->sv.gender << ';' << p->sv.birth.d << "/" << p->sv.birth.m << "/" << p->sv.birth.y << ';' << p->sv.socialid << endl;
            p = p->next;
        }
        w.close();
    }
}
void showdataUser(nodeuser dataUser) {
    cout << "Last name: " << dataUser->sv.lastname << endl;
    cout << "First name: " << dataUser->sv.firstname << endl;
    cout << "Gender: " << dataUser->sv.gender << endl;
    cout << "Staff ID: " << dataUser->sv.studentid << endl;
    cout << "Date of Birth: " << dataUser->sv.birth.d << "/" << dataUser->sv.birth.m << "/" << dataUser->sv.birth.y << endl;
}
void showdataStaff(nodestaff dataStaff) {
    cout << "Last name: " << dataStaff->sf.lastname << endl;
    cout << "First name: " << dataStaff->sf.firstname << endl;
    cout << "Gender: " << dataStaff->sf.gender << endl;
    cout << "Staff ID: " << dataStaff->sf.staffid << endl;
    cout << "Date of Birth: " << dataStaff->sf.birth.d << "/" << dataStaff->sf.birth.m << "/" << dataStaff->sf.birth.y << endl;
}
void profile(nodeuser dataUser) {
    ifstream r;
    r.open("C:/Users/Administrator/Documents/Data/tkmk.txt", ios::in);
    string tk;
    r >> tk;
    r.close();
    if (dataUser == NULL)
        return;
    else {
        while (dataUser != NULL) {
            if (dataUser->sv.studentid == tk) {
                showdataUser(dataUser);
                break;
            }
            else
                dataUser = dataUser->next;
        }
    }
}
// profile staff
void profilestaff() {
    ifstream r;
    string tk;
    //nodestaff dataStaff = NULL;
   // doc_danhsach_thongtin_staff(r, dataStaff, "C:/Users/Administrator/Documents/Data/Staff.csv");
    r.open("C:/Users/Administrator/Documents/Data/tkmk.txt", ios::in);
    if (r.is_open()) {
        r >> tk;
        r.close();
    }
    if (tk == "110") {
        cout << "Last name: " << "Le Thi Anh" << endl;
        cout << "First name: " << "Thao" << endl;
        cout << "Gender: " << "Female" << endl;
        cout << "Staff ID: " << "110" << endl;
        cout << "Date of Birth: " << "16 / 08 / 1989" << endl;
    }
    else if (tk == "111") {
        cout << "Last name: " << "Nguyen Thi Minh" << endl;
        cout << "First name: " << "Phuc" << endl;
        cout << "Gender: " << "Female" << endl;
        cout << "Staff ID: " << "111" << endl;
        cout << "Date of Birth: " << "02/08/1990" << endl;
    }
    else if (tk == "112") {
        cout << "Last name: " << "Hoang Thanh" << endl;
        cout << "First name: " << "Tu" << endl;
        cout << "Gender: " << "Female" << endl;
        cout << "Staff ID: " << "112" << endl;
        cout << "Date of Birth: " << "04/07/1991" << endl;
    }
    /*if (dataStaff == NULL)
        return;
    else {
        while (dataStaff != NULL) {
            if (dataStaff->sf.staffid == tk) {
                showdataStaff(dataStaff);
                break;
            }
            else
                dataStaff = dataStaff->next;
        }
    }*/
}
void inputClassData() {
    ListClass liststudent;
    int year;
    int quantity;
    cout << "Curriculum program \n";
    cout << "(APCS/CLC/CTT/VP): ";
    getline(cin, liststudent.program);
    cout << "Academic Year: ";
    cin >> liststudent.academicYear;
    cin.ignore();
    cout << "Class: ";
    getline(cin, liststudent.className);
    cout << "Number of students: ";
    cin >> quantity;  
    cin.ignore();
    system("cls");
    int no = 1;
    ofstream w;
    w.open("C:/Users/Administrator/Documents/Data/2022-2023/" + liststudent.className + ".csv", ios::out);
    while (no <= quantity) {
        sinhvien newSinhvien;
        string dateOfBirth;
        cout << "==================================" << endl;
        cout << "No " << no << endl;
        cout << "Student ID: ";
        getline(cin, newSinhvien.studentid);
        cout << "Last Name: ";
        getline(cin, newSinhvien.lastname);
        cout << "First Name: ";
        getline(cin, newSinhvien.firstname);
        cout << "Gender: ";
        getline(cin, newSinhvien.gender);
        cout << "Date of Birth: ";
        if ((newSinhvien.gender[0]) >= 97 && newSinhvien.gender[0] <= 122)
            newSinhvien.gender[0] -= 32;
        getline(cin, dateOfBirth);
        newSinhvien.birth = strToDate(dateOfBirth);
        cout << "Social ID: ";
        getline(cin, newSinhvien.socialid);
        newSinhvien.academicYear = liststudent.academicYear;
        cout << "==================================" << endl;
        w << no << ';' << newSinhvien.studentid << ';' << newSinhvien.lastname << ';' << newSinhvien.firstname << ';' << newSinhvien.gender << ';' << dateOfBirth << ';' << newSinhvien.socialid << endl;
        no++;
    }
    w.close();
}
void importClassData() {
    ListClass liststudent;
    int year;
    system("cls");
    //int year;
    int no = 1;
    string path = "C:/Users/Administrator/Documents/Data/Import File/Classes/";
    string temp;
    cout << "Curriculum program \n";
    cout << "(APCS/CLC/CTT/VP): ";
    getline(cin, liststudent.program);
    cout << "Academic Year: "; 
    cin >> liststudent.academicYear;
    cin.ignore();
    cout << "Class: "; 
    getline(cin, liststudent.className);
    cout << "Path: " + path; 
    getline(cin, temp);
    //year = stoi(currentSchoolYear.substr(0, 4)) - listStudent.academicYear + 1;
    //listStudent.year = studentYear(year);
    // kh co duoi csv thi + them duoi csv
    if (temp.find(".csv") == string::npos) {
        temp += ".csv";
    }
    path += temp;
    ifstream r;
    r.open(path, ios :: in);
    nodeuser newSinhvien = NULL;
    while (!r.eof()) {
        sinhvien sv = doc_thongtin_1_sinhvien(r);
        addUser(newSinhvien, sv);
    }
    r.close();
    ofstream w;
    ghi_file_danhsach(w, newSinhvien, liststudent.className);
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");
    cout << "Succesfull!" << endl;
}
void doc_xuatconsole(string filename) {
    ifstream r;
    nodeuser a = NULL;
    doc_danhsach_thongtin_sinhvien(r, a, filename);
    xuat_danhsach_thongtin_sinhvien(a);
}
void createSemester(Semester &currentSemester) {
    system("cls");
    int semester;
    string startDate, endDate;
    cout << "Semester(1/2/3): "; cin >> semester;
    cout << "Start date: "; cin >> startDate;
    cout << "End date: "; cin >> endDate;
    ofstream w("C:/Users/Administrator/Documents/Data/semester.txt", ios::out | ios::app);
    if (w.is_open()) {
        w << semester << "\n" << startDate << "\n" << endDate;
    }
    w.close();
    currentSemester.semester = semester;
    currentSemester.startDate = strToDate(startDate);
    currentSemester.endDate = strToDate(endDate);
}
void infoSemester(Semester currentSemester) {
    string str;
    ifstream r;
    r.open("C:/Users/Administrator/Documents/Data/semester.txt", ios::out);
    r >> str;
    r.close();
    if (str.length() == 0)
        cout << "Empty!" << endl;
    else {
        cout << "Semester " << currentSemester.semester << endl;
        cout << "Start date: " << dateToStr(currentSemester.startDate) << endl;
        cout << "End date: " << dateToStr(currentSemester.endDate) << endl;
    }
}
void addCourse(nodecourse& cour, Course course) {
    nodecourse temp = makelistcourse(course);
    if (cour == NULL)
        cour = temp;
    else {
        nodecourse temp1 = cour;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
    }
}
void inputCoursesData() {
    int num;
    cout << "Number of courses: ";
    cin >> num;
    cin.ignore();
    int no = 1;
    ofstream w;
    w.open("C:/Users/Administrator/Documents/Data/Courses/course.csv", ios::out);
    cout << "==================================" << endl;
    if (w.is_open()) {
        while (no <= num) {
            Course newCourse;
            //string session;
            cout << "No " << no << endl;
            cout << "Course ID: ";
            getline(cin, newCourse.id);
            cout << "Course name: ";
            getline(cin, newCourse.courseName);
            cout << "Teacher name: ";
            getline(cin, newCourse.teacherName);
            cout << "Credits: ";
            cin >> newCourse.credits;
            cout << "Academic: ";
            cin >> newCourse.academicYear;
            cout << "Number of students: ";
            cin >> newCourse.maxStudents;
            cin.ignore();
            cout << "Weekday: ";
            getline(cin, newCourse.wDay);
            cout << "Session: ";
            getline(cin, newCourse.session);
           // newCourse.session[0] = session.substr(session.find('S'), 2);
            //session.erase(session.find('S'), 2);
            //newCourse.session[1] = session.substr(session.find('S'), 2);
            no++;
            // ID, Course name, Teacher name, Credits, Academic year, Number of students, Number of enroller, Day of the week, Session
            cout << "==================================" << endl;
            w << newCourse.id << ';' << newCourse.courseName << ';' << newCourse.teacherName << ';' << newCourse.credits << ';' << newCourse.academicYear << ';' << newCourse.maxStudents << ";" << newCourse.numberRegistered << ";" << newCourse.wDay << ';' << newCourse.session << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
        system("cls");
        cout << "Succesfull!" << endl;
    }
    else {
        cerr << "Error!" << endl;
    }
    w.close();
}
Course doc_1_course(ifstream& r) {
    Course newCourse;
    getline(r, newCourse.id, ';');
    getline(r, newCourse.courseName, ';');
    getline(r, newCourse.teacherName, ';');
    string str;
    getline(r, str, ';');
    newCourse.credits = stoi(str);
    str = "";
    getline(r, str, ';');
    newCourse.academicYear = stoi(str);
    str = "";
    getline(r, str, ';');
    newCourse.maxStudents = stoi(str);
    str = "";
    getline(r, str, ';');
    newCourse.numberRegistered = stoi(str);
    getline(r, newCourse.wDay, ';');
    getline(r, newCourse.session);
    //char x; r >> x;
   // r >> newCourse.session[1];
    return newCourse;
}
void ouputcourse_console(Course course, int no) {
    cout << setfill(' ') << setw(5) << left << no << "| "
        << setfill(' ') << setw(10) << left << course.id << "| "
        << setfill(' ') << setw(30) << left << course.courseName << "| "
        << setfill(' ') << setw(20) << left << course.teacherName << "| "
        << setfill(' ') << setw(10) << left << course.credits << "| "
        << setfill(' ') << setw(10) << left << course.academicYear << "| "
        << setfill(' ') << setw(20) << left << course.maxStudents << "| "
        << setfill(' ') << setw(10) << left << course.wDay << "| "
        << setfill(' ') << setw(10) << left << course.session << endl;
}
void importCoursesData() {
    system("cls");
    int no = 1;
    string path = "C:/Users/Administrator/Documents/Data/Import File/Courses/";
    string temp;
    cout << "Path: " + path;
    getline(cin, temp);
    //temp = "course1.csv";
    if (temp.find(".csv") == string::npos) {
        temp += ".csv";
    }
    path += temp;
    ifstream r;
    r.open(path, ios::in);
    nodecourse cour = NULL;
    if (r.is_open()) {
        while (no <= 12) {
            Course newCourse = doc_1_course(r);
            //ouputcourse_console(newCourse, no);
            addCourse(cour, newCourse);
            /*cout << setfill(' ') << setw(5) << left << no << "| "
                << setfill(' ') << setw(10) << left << newCourse.id << "| "
                << setfill(' ') << setw(30) << left << newCourse.courseName << "| "
                << setfill(' ') << setw(20) << left << newCourse.teacherName << "| "
                << setfill(' ') << setw(10) << left << newCourse.credits << "| "
                << setfill(' ') << setw(10) << left << newCourse.academicYear << "| "
                << setfill(' ') << setw(20) << left << newCourse.maxStudents << "| "
                << setfill(' ') << setw(10) << left << newCourse.wDay << "| "
                << setfill(' ') << setw(10) << left << newCourse.session << endl;*/
            no++;
        }
    }
    else {
        cerr << "Error!" << endl;
    }
    r.close();
    /*while (cour != NULL) {
        cout << setfill(' ') << setw(5) << left << no << "| "
            << setfill(' ') << setw(10) << left << cour->cour.id << "| "
            << setfill(' ') << setw(30) << left << cour->cour.courseName << "| "
            << setfill(' ') << setw(20) << left << cour->cour.teacherName << "| "
            << setfill(' ') << setw(10) << left << cour->cour.credits << "| "
            << setfill(' ') << setw(10) << left << cour->cour.academicYear << "| "
            << setfill(' ') << setw(20) << left << cour->cour.maxStudents << "| "
            << setfill(' ') << setw(10) << left << cour->cour.wDay << "| "
            << setfill(' ') << setw(10) << left << cour->cour.session << endl;
        cour = cour->next;
    }*/
    //// ghi danh sach course da doc vo file 
    ofstream w;
    w.open("C:/Users/Administrator/Documents/Data/Courses/course.csv", ios :: out| ios :: app);
    while (cour != NULL) {
        // ID, Course name, Teacher name, Credits, Academic year, Number of students, Number of enroller, Day of the week, Session
        w << cour->cour.id << ';' << cour->cour.courseName << ';' << cour->cour.teacherName << ';' << cour->cour.credits << ';' << cour->cour.academicYear << ';' << cour->cour.maxStudents << ";" << cour->cour.numberRegistered << ";" << cour->cour.wDay << ';' << cour->cour.session << endl;
        cour = cour->next;
    }
    w.close();
    this_thread::sleep_for(chrono::seconds(1));
    system("cls");
    cout << "Succesfull!" << endl;
}