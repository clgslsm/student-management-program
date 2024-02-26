#include "student_management.h"

int main() {
    StudentManagement studentManager;
    // Adding new students
    studentManager.addStudent("John Doe");
    studentManager.addStudent("Jane Doe");
    studentManager.addStudent("Alice Smith");
    // Displaying the list of all students
    studentManager.displayStudents();
    // Removing a student
    studentManager.removeStudent("Jane Doe");
    // Menu to add, display, remove students
    studentManager.menu();
    return 0;
}
