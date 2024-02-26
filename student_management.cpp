#include "student_management.h"
#include <iostream>

using namespace std;
// Constructor
Student::Student(string n) : name(n) {}

// Getter for name
string Student::getName() const {
    return name;
}

// Setter for name
void Student::setName(string n) {
    name = n;
}

// Function to add a new student
void StudentManagement::addStudent(string name) {
    students.push_back(Student(name));
}

// Function to display the list of all students
void StudentManagement::displayStudents() const {
    for (const auto& student : students) {
        cout << student.getName() << endl;
    }
}

// Function to remove a student by name. If the name is not found, inform the message to the user.
void StudentManagement::removeStudent(string name) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getName() == name) {
            students.erase(it);
            return;
        }
    }
    cout << "Student " << name << " not found." << endl;
}

// Funnction menu
void StudentManagement::menu() {
    int choice;
    string name;
    do {
        cout << "1. Add new student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Remove a student" << endl;
        cout << "4. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter student name: ";
            cin >> name;
            addStudent(name);
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            cout << "Enter student name: ";
            cin >> name;
            removeStudent(name);
            break;
        case 4:
            cout << "Exit the program" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 4);
}