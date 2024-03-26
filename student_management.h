#ifndef STUDENT_MANAGEMENT_H
#define STUDENT_MANAGEMENT_H

using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <limits> // For cin.ignore() and cin.clear() solving the string with space issue

enum typeOfStudent {
    COLLEGE,
    UNIVERSITY
};
class Student {
private:
    string name;
    int score;
    string dateOfBirth;
    string schoolName;
    string courseNames;
protected:
    int numOfGrade[3];
    int numOfSemester;
    string type;
public:
    // Constructor
    Student(string n = "", int s = 0, string dob = "", string school = "", string courses = "");
    // Getter for name
    string getName() const { return name; };
    //Setter for name
    void setName(string n) { name = n;}
    // Getter for score
    int getScore() const { return score; };
    // Setter for score
    void setScore(int s) { score = s; };
    // Getter for date of birth
    string getDateOfBirth() const { return dateOfBirth; };
    // Setter for date of birth
    void setDateOfBirth(string dob) { dateOfBirth = dob; };
    // Getter for school name
    string getSchoolName() const { return schoolName; };
    // Setter for school name
    void setSchoolName(string school) { schoolName = school; };
    // Getter for course names
    string getCourseNames() const { return courseNames; };
    // Setter for course names
    void setCourseNames(string courses) { courseNames = courses; };
    // Abstract function to get type of student
    string getType() { return type; };
};

class UniStudent : public Student {
public:
    UniStudent() : Student() {
        numOfGrade[0] = 3;
        numOfGrade[1] = 2;
        numOfGrade[2] = 1;
        numOfSemester = 8;
        type = "University";
    }

    UniStudent(string n, int s, string dob, string school, string courses) : Student(n, s, dob, school, courses) {
        numOfGrade[0] = 3;
        numOfGrade[1] = 2;
        numOfGrade[2] = 1;
        numOfSemester = 8;
        type = "University";
    }
};

class CollegeStudent : public Student {
public:
    CollegeStudent() : Student() {
        numOfGrade[0] = 1;
        numOfGrade[1] = 1;
        numOfGrade[2] = 1;
        numOfSemester = 4;
        type = "College";
    }

    CollegeStudent(string n, int s, string dob, string school, string courses) : Student(n, s, dob, school, courses) {
        numOfGrade[0] = 1;
        numOfGrade[1] = 1;
        numOfGrade[2] = 1;
        numOfSemester = 4;
        type = "College";
    }
};
class University
{
private:
    Student** studentsList;
    string name;
    int size;

public:
    University();
    University(string n);
    void addStudent(string name, int score, string dob, string school, string courses, typeOfStudent type);
    void displayStudents();
    void removeStudent(string name);
    void displayBestStudents();
    void menu();
};
#endif // STUDENT_MANAGEMENT_H
