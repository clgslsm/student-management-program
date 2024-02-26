#include "student_management.h"
#include <iostream>

using namespace std;
// Constructor
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
    scoreList = nullptr;
    nameList = nullptr;
}
// Destructor
StudentManagement::~StudentManagement() {
    delete[] scoreList;
    delete[] nameList;
}
// Function to add a new student
void StudentManagement::addStudent(string name, int score) {
    students.push_back(Student(name, score));
    size++;
    int* newScoreList = new int[size];
    string* newNameList = new string[size];
    for (int i = 0; i < size - 1; i++) {
        newScoreList[i] = scoreList[i];
        newNameList[i] = nameList[i];
    }
    newScoreList[size - 1] = score;
    newNameList[size - 1] = name;
    delete[] scoreList;
    delete[] nameList;
    scoreList = newScoreList;
    nameList = newNameList;
}

// Function to display the list of all students
void StudentManagement::displayStudents() const {
    for (int i = 0; i < size; i++) {
        cout << "Name: " << nameList[i] << ", Score: " << scoreList[i] << endl;
    }
}
// Function to display the best students
void StudentManagement::displayBestStudents() const {
    int max = scoreList[0];
    for (int i = 1; i < size; i++) {
        if (scoreList[i] > max) {
            max = scoreList[i];
        }
    }
    cout << "The best students are: " << endl;
    for (int i = 0; i < size; i++) {
        if (scoreList[i] == max) {
            cout << "Name: " << nameList[i] << ", Score: " << scoreList[i] << endl;
        }
    }
}

// Function to remove a student by name. If the name is not found, inform the message to the user.
void StudentManagement::removeStudent(string name) {
    for (auto it = students.begin(); it != students.end(); ) {
        if (it->getName() == name) {
            it = students.erase(it);
        } else {
            ++it;
        }
    }
    for (int i = 0; i < size; i++) {
        if (nameList[i] == name) {
            for (int j = i; j < size - 1; j++) {
                scoreList[j] = scoreList[j + 1];
                nameList[j] = nameList[j + 1];
            }
            size--;
            int* newScoreList = new int[size];
            string* newNameList = new string[size];
            for (int i = 0; i < size; i++) {
                newScoreList[i] = scoreList[i];
                newNameList[i] = nameList[i];
            }
            delete[] scoreList;
            delete[] nameList;
            scoreList = newScoreList;
            nameList = newNameList;
            return;
        }
    }
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
