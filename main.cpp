#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <cctype>

using namespace std;

// -------------------- DATA STRUCTURES --------------------

struct Student {
    int id = 0;
    string name, department, email, phone;
};

struct Faculty {
    int id = 0;
    string name, department, email;
};

struct Course {
    int id = 0;
    string title, department;
    int credits = 0;
};

struct Attendance {
    int studentId = 0;
    string date, status;
};

struct Fee {
    int studentId = 0;
    double amount = 0.0;
    string status;
};

// -------------------- FILE NAMES --------------------

const string STUDENTS_FILE = "students.txt";
const string FACULTY_FILE = "faculty.txt";
const string COURSES_FILE = "courses.txt";
const string ATTENDANCE_FILE = "attendance.txt";
const string FEES_FILE = "fees.txt";

// -------------------- COMMON FUNCTIONS --------------------

string cleanField(string value) {
    replace(value.begin(), value.end(), '|', '/');
    return value;
}

vector<string> split(const string& line, char delimiter = '|') {
    vector<string> parts;
    string item;
    stringstream ss(line);

    while (getline(ss, item, delimiter)) {
        parts.push_back(item);
    }
    return parts;
}

int readInt(const string& prompt) {
    int value;

    while (true) {
        cout << prompt;

        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Please enter a valid whole number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double readDouble(const string& prompt) {
    double value;

    while (true) {
        cout << prompt;

        if (cin >> value && value >= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Please enter a valid non-negative amount.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string readText(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return cleanField(value);
}

string toLowerText(string value) {
    transform(value.begin(), value.end(), value.begin(),
        [](unsigned char ch) { return static_cast<char>(tolower(ch)); });
    return value;
}

template <typename T>
int findIndexById(const vector<T>& records, int id) {
    for (int i = 0; i < static_cast<int>(records.size()); ++i) {
        if (records[i].id == id) {
            return i;
        }
    }
    return -1;
}

// -------------------- LOAD DATA FROM FILES --------------------

vector<Student> loadStudents() {
    vector<Student> records;
    ifstream file(STUDENTS_FILE);
    string line;

    while (getline(file, line)) {
        vector<string> p = split(line);

        if (p.size() != 5) continue;

        try {
            Student s;
            s.id = stoi(p[0]);
            s.name = p[1];
            s.department = p[2];
            s.email = p[3];
            s.phone = p[4];
            records.push_back(s);
        } catch (...) {
            // Ignore damaged or invalid lines.
        }
    }
    return records;
}

vector<Faculty> loadFaculty() {
    vector<Faculty> records;
    ifstream file(FACULTY_FILE);
    string line;

    while (getline(file, line)) {
        vector<string> p = split(line);

        if (p.size() != 4) continue;

        try {
            Faculty f;
            f.id = stoi(p[0]);
            f.name = p[1];
            f.department = p[2];
            f.email = p[3];
            records.push_back(f);
        } catch (...) {
            // Ignore damaged or invalid lines.
        }
    }
    return records;
}

vector<Course> loadCourses() {
    vector<Course> records;
    ifstream file(COURSES_FILE);
    string line;

    while (getline(file, line)) {
        vector<string> p = split(line);

        if (p.size() != 4) continue;

        try {
            Course c;
            c.id = stoi(p[0]);
            c.title = p[1];
            c.department = p[2];
            c.credits = stoi(p[3]);
            records.push_back(c);
        } catch (...) {
            // Ignore damaged or invalid lines.
        }
    }
    return records;
}

vector<Attendance> loadAttendance() {
    vector<Attendance> records;
    ifstream file(ATTENDANCE_FILE);
    string line;

    while (getline(file, line)) {
        vector<string> p = split(line);

        if (p.size() != 3) continue;

        try {
            Attendance a;
            a.studentId = stoi(p[0]);
            a.date = p[1];
            a.status = p[2];
            records.push_back(a);
        } catch (...) {
            // Ignore damaged or invalid lines.
        }
    }
    return records;
}

vector<Fee> loadFees() {
    vector<Fee> records;
    ifstream file(FEES_FILE);
    string line;

    while (getline(file, line)) {
        vector<string> p = split(line);

        if (p.size() != 3) continue;

        try {
            Fee f;
            f.studentId = stoi(p[0]);
            f.amount = stod(p[1]);
            f.status = p[2];
            records.push_back(f);
        } catch (...) {
            // Ignore damaged or invalid lines.
        }
    }
    return records;
}

// -------------------- SAVE DATA TO FILES --------------------

void saveStudents(const vector<Student>& records) {
    ofstream file(STUDENTS_FILE);
    if (!file) {
        cout << "Error: could not save student data.\n";
        return;
    }

    for (const Student& s : records) {
        file << s.id << '|' << s.name << '|' << s.department << '|'
             << s.email << '|' << s.phone << '\n';
    }
}

void saveFaculty(const vector<Faculty>& records) {
    ofstream file(FACULTY_FILE);
    if (!file) {
        cout << "Error: could not save faculty data.\n";
        return;
    }

    for (const Faculty& f : records) {
        file << f.id << '|' << f.name << '|' << f.department
             << '|' << f.email << '\n';
    }
}

void saveCourses(const vector<Course>& records) {
    ofstream file(COURSES_FILE);
    if (!file) {
        cout << "Error: could not save course data.\n";
        return;
    }

    for (const Course& c : records) {
        file << c.id << '|' << c.title << '|' << c.department
             << '|' << c.credits << '\n';
    }
}

void saveAttendance(const vector<Attendance>& records) {
    ofstream file(ATTENDANCE_FILE);
    if (!file) {
        cout << "Error: could not save attendance data.\n";
        return;
    }

    for (const Attendance& a : records) {
        file << a.studentId << '|' << a.date << '|' << a.status << '\n';
    }
}

void saveFees(const vector<Fee>& records) {
    ofstream file(FEES_FILE);
    if (!file) {
        cout << "Error: could not save fee data.\n";
        return;
    }

    file << fixed << setprecision(2);
    for (const Fee& f : records) {
        file << f.studentId << '|' << f.amount << '|' << f.status << '\n';
    }
}

// -------------------- STUDENT MANAGEMENT --------------------

void printStudent(const Student& s) {
    cout << left << setw(8) << s.id
         << setw(22) << s.name
         << setw(18) << s.department
         << setw(28) << s.email
         << s.phone << '\n';
}

void listStudents() {
    vector<Student> records = loadStudents();

    if (records.empty()) {
        cout << "No student records found.\n";
        return;
    }

    cout << left << setw(8) << "ID"
         << setw(22) << "Name"
         << setw(18) << "Department"
         << setw(28) << "Email" << "Phone\n";
    cout << string(90, '-') << '\n';

    for (const Student& s : records) {
        printStudent(s);
    }
}

void addStudent() {
    vector<Student> records = loadStudents();
    Student s;

    s.id = readInt("Student ID: ");

    if (s.id <= 0) {
        cout << "Student ID must be positive.\n";
        return;
    }

    if (findIndexById(records, s.id) != -1) {
        cout << "That student ID already exists.\n";
        return;
    }

    s.name = readText("Full name: ");
    s.department = readText("Department: ");
    s.email = readText("Email: ");
    s.phone = readText("Phone: ");

    if (s.name.empty()) {
        cout << "Name cannot be empty.\n";
        return;
    }

    records.push_back(s);
    saveStudents(records);
    cout << "Student added successfully.\n";
}

void searchStudent() {
    vector<Student> records = loadStudents();
    int id = readInt("Enter student ID: ");
    int index = findIndexById(records, id);

    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    cout << left << setw(8) << "ID"
         << setw(22) << "Name"
         << setw(18) << "Department"
         << setw(28) << "Email" << "Phone\n";
    printStudent(records[index]);
}

void updateStudent() {
    vector<Student> records = loadStudents();
    int id = readInt("Student ID to update: ");
    int index = findIndexById(records, id);

    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    cout << "Enter updated details:\n";
    records[index].name = readText("Full name: ");
    records[index].department = readText("Department: ");
    records[index].email = readText("Email: ");
    records[index].phone = readText("Phone: ");

    saveStudents(records);
    cout << "Student updated successfully.\n";
}

void deleteStudent() {
    vector<Student> records = loadStudents();
    int id = readInt("Student ID to delete: ");
    int index = findIndexById(records, id);

    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    char confirm;
    cout << "Delete this student? (y/n): ";
    cin >> confirm;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (confirm != 'y' && confirm != 'Y') {
        cout << "Delete cancelled.\n";
        return;
    }

    records.erase(records.begin() + index);
    saveStudents(records);
    cout << "Student deleted successfully.\n";
}

// -------------------- FACULTY MANAGEMENT --------------------

void addFaculty() {
    vector<Faculty> records = loadFaculty();
    Faculty f;

    f.id = readInt("Faculty ID: ");

    if (f.id <= 0) {
        cout << "Faculty ID must be positive.\n";
        return;
    }

    if (findIndexById(records, f.id) != -1) {
        cout << "That faculty ID already exists.\n";
        return;
    }

    f.name = readText("Faculty name: ");
    f.department = readText("Department: ");
    f.email = readText("Email: ");

    records.push_back(f);
    saveFaculty(records);
    cout << "Faculty record added successfully.\n";
}

void listFaculty() {
    vector<Faculty> records = loadFaculty();

    if (records.empty()) {
        cout << "No faculty records found.\n";
        return;
    }

    cout << left << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(20) << "Department" << "Email\n";
    cout << string(75, '-') << '\n';

    for (const Faculty& f : records) {
        cout << left << setw(10) << f.id
             << setw(25) << f.name
             << setw(20) << f.department
             << f.email << '\n';
    }
}

// -------------------- COURSE MANAGEMENT --------------------

void addCourse() {
    vector<Course> records = loadCourses();
    Course c;

    c.id = readInt("Course ID: ");

    if (c.id <= 0) {
        cout << "Course ID must be positive.\n";
        return;
    }

    if (findIndexById(records, c.id) != -1) {
        cout << "That course ID already exists.\n";
        return;
    }

    c.title = readText("Course title: ");
    c.department = readText("Department: ");
    c.credits = readInt("Credits: ");

    if (c.credits < 0) {
        cout << "Credits cannot be negative.\n";
        return;
    }

    records.push_back(c);
    saveCourses(records);
    cout << "Course added successfully.\n";
}

void listCourses() {
    vector<Course> records = loadCourses();

    if (records.empty()) {
        cout << "No course records found.\n";
        return;
    }

    cout << left << setw(10) << "ID"
         << setw(30) << "Course"
         << setw(22) << "Department" << "Credits\n";
    cout << string(75, '-') << '\n';

    for (const Course& c : records) {
        cout << left << setw(10) << c.id
             << setw(30) << c.title
             << setw(22) << c.department
             << c.credits << '\n';
    }
}

// -------------------- ATTENDANCE MANAGEMENT --------------------

void markAttendance() {
    vector<Student> students = loadStudents();
    int id = readInt("Student ID: ");

    if (findIndexById(students, id) == -1) {
        cout << "Student not found. Add the student first.\n";
        return;
    }

    string date = readText("Date (YYYY-MM-DD): ");
    string status = toLowerText(readText("Status (Present/Absent): "));

    if (status != "present" && status != "absent") {
        cout << "Status must be Present or Absent.\n";
        return;
    }

    vector<Attendance> records = loadAttendance();
    Attendance a;
    a.studentId = id;
    a.date = date;
    a.status = status;

    records.push_back(a);
    saveAttendance(records);
    cout << "Attendance saved successfully.\n";
}

void viewAttendance() {
    vector<Attendance> records = loadAttendance();
    int id = readInt("Student ID: ");
    bool found = false;

    cout << left << setw(18) << "Date" << "Status\n";
    cout << string(35, '-') << '\n';

    for (const Attendance& a : records) {
        if (a.studentId == id) {
            cout << left << setw(18) << a.date << a.status << '\n';
            found = true;
        }
    }

    if (!found) {
        cout << "No attendance records for this student.\n";
    }
}

// -------------------- FEES MANAGEMENT --------------------

void recordFee() {
    vector<Student> students = loadStudents();
    int id = readInt("Student ID: ");

    if (findIndexById(students, id) == -1) {
        cout << "Student not found. Add the student first.\n";
        return;
    }

    double amount = readDouble("Fee amount: ");
    string status = toLowerText(readText("Payment status (Paid/Pending): "));

    if (status != "paid" && status != "pending") {
        cout << "Status must be Paid or Pending.\n";
        return;
    }

    vector<Fee> records = loadFees();
    Fee f;
    f.studentId = id;
    f.amount = amount;
    f.status = status;

    records.push_back(f);
    saveFees(records);
    cout << "Fee record saved successfully.\n";
}

void viewFees() {
    vector<Fee> records = loadFees();
    int id = readInt("Student ID: ");
    bool found = false;
    double total = 0.0;
    double paid = 0.0;
    double pending = 0.0;

    cout << fixed << setprecision(2);
    cout << left << setw(16) << "Amount" << "Status\n";
    cout << string(30, '-') << '\n';

    for (const Fee& f : records) {
        if (f.studentId == id) {
            cout << left << setw(16) << f.amount << f.status << '\n';
            total += f.amount;

            if (f.status == "paid") paid += f.amount;
            if (f.status == "pending") pending += f.amount;

            found = true;
        }
    }

    if (found) {
        cout << "Total recorded : " << total << '\n';
        cout << "Paid amount    : " << paid << '\n';
        cout << "Pending amount : " << pending << '\n';
    } else {
        cout << "No fee records for this student.\n";
    }
}

// -------------------- CAMPUS SUMMARY REPORT --------------------

void report() {
    vector<Student> students = loadStudents();
    vector<Faculty> faculty = loadFaculty();
    vector<Course> courses = loadCourses();
    vector<Attendance> attendance = loadAttendance();
    vector<Fee> fees = loadFees();

    int present = 0;
    int absent = 0;
    int pendingEntries = 0;
    double paidAmount = 0.0;
    double pendingAmount = 0.0;

    for (const Attendance& a : attendance) {
        if (a.status == "present") {
            ++present;
        } else if (a.status == "absent") {
            ++absent;
        }
    }

    for (const Fee& f : fees) {
        if (f.status == "pending") {
            ++pendingEntries;
            pendingAmount += f.amount;
        } else if (f.status == "paid") {
            paidAmount += f.amount;
        }
    }

    cout << "\n========== CAMPUS SUMMARY ==========\n";
    cout << "Total students       : " << students.size() << '\n';
    cout << "Total faculty        : " << faculty.size() << '\n';
    cout << "Total courses        : " << courses.size() << '\n';
    cout << "Attendance entries   : " << attendance.size() << '\n';
    cout << "Present entries      : " << present << '\n';
    cout << "Absent entries       : " << absent << '\n';
    cout << "Pending fee entries  : " << pendingEntries << '\n';
    cout << fixed << setprecision(2);
    cout << "Total paid fees      : " << paidAmount << '\n';
    cout << "Total pending fees   : " << pendingAmount << '\n';
    cout << "====================================\n";
}

// -------------------- MENUS --------------------

void studentMenu() {
    while (true) {
        cout << "\n--- STUDENT MANAGEMENT ---\n"
             << "1. Add student\n"
             << "2. View all students\n"
             << "3. Search student\n"
             << "4. Update student\n"
             << "5. Delete student\n"
             << "0. Back to main menu\n";

        int choice = readInt("Enter choice: ");

        switch (choice) {
            case 1: addStudent(); break;
            case 2: listStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 0: return;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}

void facultyMenu() {
    while (true) {
        cout << "\n--- FACULTY MANAGEMENT ---\n"
             << "1. Add faculty\n"
             << "2. View faculty\n"
             << "0. Back to main menu\n";

        int choice = readInt("Enter choice: ");

        if (choice == 1) addFaculty();
        else if (choice == 2) listFaculty();
        else if (choice == 0) return;
        else cout << "Invalid choice. Try again.\n";
    }
}

void courseMenu() {
    while (true) {
        cout << "\n--- COURSE MANAGEMENT ---\n"
             << "1. Add course\n"
             << "2. View courses\n"
             << "0. Back to main menu\n";

        int choice = readInt("Enter choice: ");

        if (choice == 1) addCourse();
        else if (choice == 2) listCourses();
        else if (choice == 0) return;
        else cout << "Invalid choice. Try again.\n";
    }
}

// -------------------- MAIN FUNCTION --------------------

int main() {
    cout << "============================================\n"
         << "          CAMPUS MANAGEMENT SYSTEM\n"
         << "============================================\n";

    while (true) {
        cout << "\n========== MAIN MENU ==========\n"
             << "1. Student Management\n"
             << "2. Faculty Management\n"
             << "3. Course Management\n"
             << "4. Mark Attendance\n"
             << "5. View Attendance\n"
             << "6. Record Fees\n"
             << "7. View Fees\n"
             << "8. Campus Summary Report\n"
             << "0. Exit\n"
             << "===============================\n";

        int choice = readInt("Enter choice: ");

        switch (choice) {
            case 1: studentMenu(); break;
            case 2: facultyMenu(); break;
            case 3: courseMenu(); break;
            case 4: markAttendance(); break;
            case 5: viewAttendance(); break;
            case 6: recordFee(); break;
            case 7: viewFees(); break;
            case 8: report(); break;
            case 0:
                cout << "Thank you for using Campus Management System.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
