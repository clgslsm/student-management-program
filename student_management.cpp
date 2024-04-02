#include "student_management.h"
#include <iostream>

using namespace std;
// Constructor
Student::Student(std::string n, std::string dob, std::string school, std::string courses)
    : name(n), dateOfBirth(dob), schoolName(school), courseNames(courses) {};

// Constructor
University::University() {
    size = 0;
    studentsList = nullptr;
    name = "";
}
University::University(std::string n) : name(n) {
    size = 0;
    studentsList = nullptr;
}

// Function to add a new student
void University::addStudent(string name, string dob, string school, string courses, typeOfStudent type) {
    Student* newStudent; // Declare a pointer to Student

    if (type == COLLEGE) {
        newStudent = new CollegeStudent(name, dob, school, courses); // Create CollegeStudent object
    }
    else {
        newStudent = new UniStudent(name, dob, school, courses); // Create UniStudent object
    }

    // Add newStudent to the dynamic array
    Student** newStudentsList = new Student*[size + 1];
    for (int i = 0; i < size; i++) {
        newStudentsList[i] = studentsList[i];
    }
    newStudentsList[size] = newStudent;
    delete [] studentsList;
    studentsList = newStudentsList;
    size++;
}

// Corrected displayStudents() function
void University::displayStudents() {
    for (int i = 0; i < size; i++) {
        studentsList[i]->displayInfo();
    }
}


// Function to display the best students
void University::displayBestStudents() {
    int max = studentsList[0]->getScore();
    for (int i = 1; i < size; i++) {
        if (studentsList[i]->getScore() > max) {
            max = studentsList[i]->getScore();
        }
    }
    cout << "The best students are: " << endl;
    for (int i = 0; i < size; i++) {
        if (studentsList[i]->getScore() == max) {
            cout << "Name: " << studentsList[i]->getName() << ", Score: " << studentsList[i]->getScore() << endl;
        }
    }
}


// Function to remove a student by name-> If the name is not found, inform the message to the user->
void University::removeStudent(string name) {
    int i = 0;
    bool find = false;
    while (i < size) {
        if (studentsList[i]->getName() == name) {
            for (int j = i; j < size - 1; j++) {
                studentsList[j] = studentsList[j + 1];
            }
            size--;
            i = 0;
            find = true;
        }
        else
            i++;
    }
    if (!find)
        cout << "Student " << name << " not found" << endl;
}

// Funnction menu
void University::menu() {
    string name; // Declare name outside the switch statement
    int choice;
    int score;
    string dob;
    string school;
    string courses;
    int type;
    Student newStudent;

    do {
        cout << "1. Add new student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Display best students" << endl;
        cout << "4. Remove a student" << endl;
        cout << "5. Exit" << endl;
        cout << "Your choice: ";

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the newline character left by cin >>

        switch (choice) {
            case 1:
                cout << "Enter student name: ";
                getline(cin, name); 
                cout << "Enter student score: ";
                cin >> score;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter student date of birth: ";
                getline(cin, dob);
                cout << "Enter student school name: ";
                getline(cin, school);
                cout << "Enter student course names: ";
                getline(cin, courses);
                cout << "Enter student type (0 for College, 1 for University): ";
                cin >> type;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                addStudent(name, dob, school, courses, typeOfStudent(type));
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                displayBestStudents();
                break;
            case 4:
                cout << "Enter student name: ";
                getline(cin, name); // Read the full line, including spaces
                removeStudent(name);
                break;
            case 5:
                cout << "Exit the program" << endl;
                // Exit the program
                return;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 5);
}
