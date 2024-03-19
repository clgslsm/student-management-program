#include "student_management.h"
#include <iostream>

using namespace std;
// Constructor
Student::Student() : name(""), score(0) {}
Student::Student(string n, int s) : name(n), score(s) {}

// Getter for name
string Student::getName() const {
    return name;
}

// Setter for name
void Student::setName(string n) {
    name = n;
}

// Setter for score
void Student::setScore(int s) {
    score = s;
}
// Getter for score
int Student::getScore() const {
    return score;
}

// Constructor
StudentManagement::StudentManagement() {
    size = 0;
    studentsList = nullptr;
}
// Destructor
StudentManagement::~StudentManagement() {
    delete [] studentsList;
}
// Function to add a new student
void StudentManagement::addStudent(string name, int score) {
    Student newStudent(name, score);
    // Add mewStudent to the dynamic array
    Student* newStudentsList = new Student[size + 1];
    for (int i = 0; i < size; i++) {
        newStudentsList[i] = studentsList[i];
    }
    newStudentsList[size] = newStudent;
    delete [] studentsList;
    studentsList = newStudentsList;
    size++;
}

// Function to display the list of all students
void StudentManagement::displayStudents() const {
    for (int i = 0; i < size; i++) {
        cout << "Name: " << studentsList[i].getName() << ", Score: " << studentsList[i].getScore() << endl;
    }
}
// Function to display the best students
void StudentManagement::displayBestStudents() const {
    int max = studentsList[0].getScore();
    for (int i = 1; i < size; i++) {
        if (studentsList[i].getScore() > max) {
            max = studentsList[i].getScore();
        }
    }
    cout << "The best students are: " << endl;
    for (int i = 0; i < size; i++) {
        if (studentsList[i].getScore() == max) {
            cout << "Name: " << studentsList[i].getName() << ", Score: " << studentsList[i].getScore() << endl;
        }
    }
}

// Function to remove a student by name. If the name is not found, inform the message to the user.
void StudentManagement::removeStudent(string name) {
    int i = 0;
    bool find = false;
    while (i < size) {
        if (studentsList[i].getName() == name) {
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
        cout << "Student " << name << " not found." << endl;
}

// Funnction menu
void StudentManagement::menu() {
    string name; // Declare name outside the switch statement
    int choice;

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
                getline(cin, name); // Read the full line, including spaces
                cout << "Enter student score: ";
                int score;
                cin >> score;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                addStudent(name, score);
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

// Constructor
University::University() {
    size = 0;
    studentsList = nullptr;
    name = "";
}
University::University(string n) : name(n) {
    size = 0;
    studentsList = nullptr;
}

// Function to add a new student
void University::addStudent(string name, int score) {
    Student newStudent(name, score);
    // Add mewStudent to the dynamic array
    Student* newStudentsList = new Student[size + 1];
    for (int i = 0; i < size; i++) {
        newStudentsList[i] = studentsList[i];
    }
    newStudentsList[size] = newStudent;
    delete [] studentsList;
    studentsList = newStudentsList;
    size++;
}

// Function to display the list of all students
void University::displayStudents() const {
    for (int i = 0; i < size; i++) {
        cout << "Name: " << studentsList[i].getName() << ", Score: " << studentsList[i].getScore() << endl;
    }
}

// Function to display the best students
void University::displayBestStudents() const {
    int max = studentsList[0].getScore();
    for (int i = 1; i < size; i++) {
        if (studentsList[i].getScore() > max) {
            max = studentsList[i].getScore();
        }
    }
    cout << "The best students are: " << endl;
    for (int i = 0; i < size; i++) {
        if (studentsList[i].getScore() == max) {
            cout << "Name: " << studentsList[i].getName() << ", Score: " << studentsList[i].getScore() << endl;
        }
    }
}


// Function to remove a student by name. If the name is not found, inform the message to the user.
void University::removeStudent(string name) {
    int i = 0;
    bool find = false;
    while (i < size) {
        if (studentsList[i].getName() == name) {
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
        cout << "Student " << name << " not found." << endl;
}

// Funnction menu
void University::menu() {
    string name; // Declare name outside the switch statement
    int choice;

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
                getline(cin, name); // Read the full line, including spaces
                cout << "Enter student score: ";
                int score;
                cin >> score;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                addStudent(name, score);
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
