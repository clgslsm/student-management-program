#include "student_management.h"

int main() {
    StudentManagement studentManager;
    // Adding new students
    studentManager.addStudent("John Doe", 90);
    studentManager.addStudent("Jane Doe", 80);
    studentManager.addStudent("Alice Smith", 85);
    studentManager.addStudent("Taylor Swift", 100);
    studentManager.addStudent("Tom Hanks", 100); // Trigger the displayBestStudents() function
    studentManager.addStudent("Elon Musk", 100);
    // Displaying the list of all students
    cout << "Test displayStudents() function\n";
    studentManager.displayStudents();

    // Displaying the best students
    cout << "Test displayBestStudents() function\n";
    studentManager.displayBestStudents();
    // Removing a student
    cout << "Test removeStudent() function\n";
    cout << "Remove Jane Doe\n";
    studentManager.removeStudent("Jane Doe");
    studentManager.displayStudents();
    // Menu to add, display, remove students
    cout << "Test menu() function\n";
    studentManager.menu();
    return 0;
}
