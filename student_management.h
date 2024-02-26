#ifndef STUDENT_MANAGEMENT_H
#define STUDENT_MANAGEMENT_H

using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <limits> // For cin.ignore() and cin.clear() solving the string with space issue
class Student {
private:
    string name;
    int score;
public:
    // Constructor
    Student(string n, int s);
    // Getter for name
    string getName() const;
    //Setter for name
    void setName(string n);
    // Getter for score
    int getScore() const;
    // Setter for score
    void setScore(int s);
};

class StudentManagement {
private:
    vector<Student> students;
    // 1 list for students' names & 1 list for student' scores.
    int* scoreList;
    string* nameList;
    int size;

public:
    // Constructor
    StudentManagement();
    // Destructor
    ~StudentManagement();
    // Function to add a new student
    void addStudent(string name, int score);

    // Function to display the list of all students
    void displayStudents() const; // Read-Only Operation

    // Funnction to remove a student by name. If the name is not found, inform the message to the user.
    void removeStudent(string name);

    void displayBestStudents() const;

    // Function to create a text-based menu that allow choose the the above functions or exit the program.
    void menu();
};

#endif // STUDENT_MANAGEMENT_H
