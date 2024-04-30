
#include <vector>
#include <iostream>
#include "functions.h"
#include "class.h"
#include <iomanip>

using namespace std;

void progLogic(vector<Subject> &subjects){
    subjects.push_back(Subject()); // Creates a new subject
};

// This function Prints a Table and Display the Grades, Remarks, etc.
void initTable (vector<Subject> &subjects) {
    cout << left << setw(25) << "Subject"
         << setw(25) << "Units"
         << setw(25) << "Final Grade"
         << setw(25) << "Remarks" << endl;
    for (int i = 0; i < subjects.size(); i++) {
        double finalGrade = subjects[i].getFinalGrade();
        cout << left << setw(25) << subjects[i].getSubject()
             << setw(25) << subjects[i].getUnits()
             << setw(25) << subjects[i].getFinalGradeUnit()
             << setw(25) << subjects[i].gradeToRemarks(finalGrade) << endl;
    }
}

int getOption(){
    int option;
    cout << "1. Enter Subject\n";
    cout << "2. Display Subjects\n";
    cout << "3. Calculate GWA\n";
    cout << "4. Help\n";
    cout << "5. Exit\n";
    cout << "Enter: "; 
    cin >> option;
    return option;
};

void printHelp(){
    cout << "help help help help me help help ahhhhhhh" << endl;
};


