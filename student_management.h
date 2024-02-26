#ifndef STUDENT_MANAGEMENT_H
#define STUDENT_MANAGEMENT_H

using namespace std;
#include <vector>
#include <string>
class Student {
private:
    string name;
public:
    // Constructor
    Student(string n);
    // Getter for name
    string getName() const;
    //Setter for name
    void setName(string n);
};

class StudentManagement {
private:
    vector<Student> students;

public:
    // Function to add a new student
    void addStudent(string name);

    // Function to display the list of all students
    void displayStudents() const; // Read-Only Operation

    // Funnction to remove a student by name. If the name is not found, inform the message to the user.
    void removeStudent(string name);

    // Function to create a text-based menu that allow choose the the above functions or exit the program.
    void menu();
};

#endif // STUDENT_MANAGEMENT_H
