# Campus Management System (C++)

A console-based Campus Management System developed in C++17 for a C/C++ with DSA training project.

## Features
- Student records: add, list, search, update and delete
- Faculty records: add and list
- Course records: add and list
- Attendance: mark and view student attendance
- Fees: record and view fee payments
- Campus summary report
- File handling: records persist in local text files

## Requirements
- C++ compiler supporting C++17 (GCC, MinGW-w64, or Clang)
- Windows, Linux, or macOS

## Compile and run

### Windows (MinGW)
Open Command Prompt in this folder:
```bash
g++ -std=c++17 -Wall -Wextra -o campus_management main.cpp
campus_management.exe
```

### Linux / macOS
```bash
g++ -std=c++17 -Wall -Wextra -o campus_management main.cpp
./campus_management
```

In VS Code, open this folder, open the terminal, and run the matching commands above.

## Data files
The application creates these files in the current working directory when records are saved:
- `students.txt`
- `faculty.txt`
- `courses.txt`
- `attendance.txt`
- `fees.txt`

Each record is stored as a pipe-separated line. Keep these files with the executable if you want to retain the data.

## Notes
- Use unique IDs for students, faculty and courses.
- Enter dates as `YYYY-MM-DD`.
- Attendance status must be `Present` or `Absent`.
- Fee status must be `Paid` or `Pending`.
- This is an educational console application, not a production-ready campus ERP. It does not include authentication, networking, database encryption, or role-based access.

## Suggested test
1. Add a student with ID `101`.
2. View all students and search for ID `101`.
3. Add a faculty member and a course.
4. Mark attendance for student `101`.
5. Record a fee payment for student `101`.
6. View the campus summary.
7. Exit and run again to verify that records persist.
