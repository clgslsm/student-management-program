#include "student_management.h"

int main() {
    string MyUniversityName = "HCMUT";
    University MyUniversity(MyUniversityName);
    MyUniversity.addStudent("John Doe", 90);
    MyUniversity.addStudent("Jane Doe", 80);
    MyUniversity.addStudent("Alice Smith", 85);
    MyUniversity.addStudent("Taylor Swift", 100);
    MyUniversity.addStudent("Tom Hanks", 100); // Trigger the displayBestStudents() function
    MyUniversity.addStudent("Elon Musk", 100);
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
