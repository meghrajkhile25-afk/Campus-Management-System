# Project Report: Campus Management System

## 1. Introduction
The Campus Management System is a menu-driven C++ application designed to maintain basic academic and administrative records of a campus. It reduces repetitive manual record keeping and demonstrates core programming and data-structure concepts.

## 2. Objectives
- Maintain student, faculty and course records.
- Record and review student attendance.
- Record fee payments and pending payments.
- Search and update student details.
- Generate a simple campus summary.
- Demonstrate file handling and structured programming in C++.

## 3. Technology Used
- Language: C++
- Standard: C++17
- Concepts: structures, vectors, functions, loops, conditional statements, searching, sorting-ready collections, input validation and file handling.
- Storage: local pipe-separated text files.

## 4. Modules
1. Student Management: add, view, search, update and delete.
2. Faculty Management: add and view faculty.
3. Course Management: add and view courses.
4. Attendance Management: mark attendance by student ID and date; view history.
5. Fees Management: record paid/pending fee entries and view them by student.
6. Summary Report: display totals for records, attendance and pending fee entries.

## 5. System Requirements
Hardware: a basic laptop/desktop capable of running a C++ compiler.
Software: Windows/Linux/macOS and GCC/MinGW/Clang with C++17 support.

## 6. How to Execute
Compile `main.cpp`:
`g++ -std=c++17 -Wall -Wextra -o campus_management main.cpp`
Run the generated executable. Follow the numbered menu options.

## 7. Testing
- Add a student and verify it appears in the student list.
- Search, update and delete a student.
- Add faculty and course records and view them.
- Mark attendance and view the student's attendance history.
- Record a fee and verify the fee history.
- Restart the program and verify that saved records remain available.

## 8. Limitations
This is an educational prototype. It does not provide login/authentication, a graphical interface, a relational database, backups, concurrent access, or production security.

## 9. Future Scope
- Add login and separate admin/faculty/student roles.
- Use MySQL or SQLite as a database.
- Add course enrollment and timetable management.
- Add graphical interface or web/mobile front end.
- Export reports to PDF/CSV and add automated backups.

## 10. Conclusion
The project demonstrates how C++ structures, vectors, functions and file handling can be combined to build a practical record-management application. It can be extended into a larger campus information system.
