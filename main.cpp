#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Subject {
public:
    string name;
    int marks;

    Subject(string name, int marks) : name(name), marks(marks) {}
};

class Student {
public:
    string name;
    int rollNumber;
    vector<Subject> subjects;

    Student(string name, int rollNumber) : name(name), rollNumber(rollNumber) {}

    void addSubject(string subjectName, int marks) {
        subjects.push_back(Subject(subjectName, marks));
    }

    int getTotalMarks() {
        int total = 0;
        for (Subject& subject : subjects) {
            total += subject.marks;
        }
        return total;
    }

    double getAverageMarks() {
        if (subjects.empty()) return 0.0;
        return getTotalMarks() / static_cast<double>(subjects.size());
    }

    void displayResult() {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Subjects and Marks: " << endl;
        for (Subject& subject : subjects) {
            cout << "  " << subject.name << ": " << subject.marks << endl;
        }
        cout << "Total Marks: " << getTotalMarks() << endl;
        cout << "Average Marks: " << getAverageMarks() << endl;
    }
};

int main() {
    // Create student
    Student student1("John Doe", 1);

    // Add subjects and marks
    student1.addSubject("Math", 85);
    student1.addSubject("Science", 90);
    student1.addSubject("History", 78);

    // Display result
    student1.displayResult();

    return 0;
}
