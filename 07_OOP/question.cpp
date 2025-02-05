// Design a C++ program that manages student information using the concept of Encapsulation. The program should store and manage student details securely, allowing access to sensitive data only through proper methods.

// Requirements:

// Create a Student class with the following private data members:
// string name (Student's Name)
// int rollNumber (Roll Number)
// float marks (Marks out of 100)
// Implement public methods for:
// Setters: To assign values to the private data members.
// Getters: To safely access and display student information.
// A method to grade the student based on marks:
// A for marks ≥ 90
// B for marks ≥ 75 and < 90
// C for marks ≥ 60 and < 75
// D for marks ≥ 40 and < 60
// F for marks < 40
// Ensure that marks cannot be set beyond the valid range (0-100).
// Demonstrate the functionality by creating objects and displaying their details and grades.

#include<iostream>
using namespace std;

class Student
{
private:
    string name;
    int rollNumber;
    float marks;
public:
    void setName(string s){
        name=s;
    }
    void setRollNumber(int r){
        rollNumber=r;
    }
    void setMarks(float m){
        if (m >= 0 && m <= 100) {
            marks = m;
        } else {
            cout << "Invalid range" << endl;
        }
    }

    string getName(){
        return name;
    }
    int getRollNumber(){
        return rollNumber;
    }
    float getMarks(){
        return marks;
    }

    char grade() {
        if (marks >= 90) {
            return 'A';
        } else if (marks >= 75) {
            return 'B';
        } else if (marks >= 60) {
            return 'C';
        } else if (marks >= 40) {
            return 'D';
        } else {
            return 'F';
        }
    }

    void display() {
        cout << "Name : " << name << endl;
        cout << "RollNumber : " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << grade() << endl;
    }
};




int main(){
    Student student1;

    student1.setName("Amay");
    student1.setRollNumber(1);
    student1.setMarks(78.3);

    student1.display();
}