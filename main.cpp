#include "student_management.h"

int main() {
    string MyUniversityName = "HCMUT";
    University MyUniversity(MyUniversityName);
    // Adding students
    cout << "Test addStudent() function\n";
    MyUniversity.addStudent("John Doe", "01/01/2000", "High School", "Math, Physics, Chemistry", COLLEGE);
    MyUniversity.addStudent("Alice Smith", "01/01/2000", "High School", "Math, Physics, Chemistry", UNIVERSITY);
    MyUniversity.addStudent("Jane Doe", "01/01/2000", "High School", "Math, Physics, Chemistry", UNIVERSITY);
    MyUniversity.randomScore();
    // Displaying the list of all students
    cout << "Test displayStudents() function\n";
    MyUniversity.displayStudents();
    // Displaying the best students
    cout << "Test displayBestStudents() function\n";
    MyUniversity.displayBestStudents();
    // Removing a student
    cout << "Test removeStudent() function\n";
    cout << "Remove Jane Doe\n";
    MyUniversity.removeStudent("Jane Doe");
    MyUniversity.displayStudents();
    // Menu to add, display, remove students
    cout << "Test menu() function\n";
    MyUniversity.menu();
    return 0;
}
