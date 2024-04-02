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
    int numAssignment;
    int numTest;
    int numExam;
    int numOfSemester;
    vector<int> gradeTest;
    vector<int> gradeAssignment;
    vector<int> gradeExam;
    string type;
public:
    // Constructor
    Student(string n = "", string dob = "", string school = "", string courses = "");
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

    void DoAssignment() {
        for (int i = 0; i < numAssignment; i++) {
            // Random grade
            int grade = rand() % 100 + 1;
            gradeAssignment.push_back(grade);
        }
    };
    void TakeTest() {
        for (int i = 0; i < numTest; i++) {
            // Random grade
            int grade = rand() % 100 + 1;
            gradeTest.push_back(grade);
        }
    };
    void TakeExam() {
        for (int i = 0; i < numExam; i++) {
            // Random grade
            int grade = rand() % 100 + 1;
            gradeExam.push_back(grade);
        }
    };
    void displayScore() {
        cout << "Assignment: ";
        for (int i = 0; i < gradeAssignment.size(); i++) {
            cout << gradeAssignment[i] << " ";
        }
        cout << endl;
        cout << "Test: ";
        for (int i = 0; i < gradeTest.size(); i++) {
            cout << gradeTest[i] << " ";
        }
        cout << endl;
        cout << "Exam: ";
        for (int i = 0; i < gradeExam.size(); i++) {
            cout << gradeExam[i] << " ";
        }
        cout << endl;
    };
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Score: " << score << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "School Name: " << schoolName << endl;
        cout << "Course Names: " << courseNames << endl;
        cout << "Type: " << type << endl;
        displayScore();
        cout << "Score: " << score << endl;
    };
    void getAvgScore() {
        float avg = 0;
        for (int i = 0; i < gradeAssignment.size(); i++) {
            avg += gradeAssignment[i];
        }
        for (int i = 0; i < gradeTest.size(); i++) {
            avg += gradeTest[i];
        }
        for (int i = 0; i < gradeExam.size(); i++) {
            avg += gradeExam[i];
        }
        avg = avg / (numAssignment + numTest + numExam);
        score = int(avg);
    }
};

class UniStudent : public Student {
public:
    UniStudent() : Student() {
        numAssignment = 3;
        numTest = 2;
        numExam = 1;
        numOfSemester = 8;
        type = "University";
    }

    UniStudent(string n, string dob, string school, string courses) : Student(n, dob, school, courses) {
        numAssignment = 3;
        numTest = 2;
        numExam = 1;
        numOfSemester = 8;
        type = "University";
    }
};

class CollegeStudent : public Student {
public:
    CollegeStudent() : Student() {
        numAssignment = 1;
        numTest = 1;
        numExam = 1;
        numOfSemester = 4;
        type = "College";
    }

    CollegeStudent(string n, string dob, string school, string courses) : Student(n, dob, school, courses) {
        numAssignment = 1;
        numTest = 1;
        numExam = 1;
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
    void addStudent(string name, string dob, string school, string courses, typeOfStudent type);
    void displayStudents();
    void removeStudent(string name);
    void displayBestStudents();
    void menu();
    void randomScore() {
        for (int i = 0; i < size; i++) {
            studentsList[i]->DoAssignment();
            studentsList[i]->TakeTest();
            studentsList[i]->TakeExam();
            studentsList[i]->getAvgScore();
        }
    }
    ~University() {
        for (int i = 0; i < size; i++) {
            delete studentsList[i];
        }
        delete[] studentsList;
    }
};
#endif // STUDENT_MANAGEMENT_H
