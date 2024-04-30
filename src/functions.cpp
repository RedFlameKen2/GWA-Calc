
#include <vector>
#include <iostream>
#include "functions.h"
#include "class.h"
#include <iomanip>

using namespace std;

double finalGWA = 0.0;

void progLogic(vector<Subject> &subjects){
    subjects.push_back(Subject()); // Creates a new subject
};

void calculateGWA(vector<Subject> &subjects){
    double totalUnits = 0.0;
    double totalGrade = 0.0;
    for (int i = 0; i < subjects.size(); i++){
        totalUnits += subjects[i].getUnits();
        totalGrade += (subjects[i].getFinalGradeUnit() * subjects[i].getUnits());
    }
    finalGWA = totalGrade / totalUnits;
}

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
    if (subjects.size() > 0 && finalGWA != 0.0)
    cout << left << setw(75) << "GWA: " << finalGWA << endl;
    else 
    cout << left << setw(75) << "GWA Not Yet Calculated!" << endl;
}

void deleteSubject(vector<Subject> &subjects){
    int index;
    cout << "Enter the number of the subject you want to delete: ";
    cin >> index;
    subjects.erase(subjects.begin() + index);
    cout << "Subject Deleted!" << endl;
}

int getOption(){
    int option;
    cout << "1. Enter Subject\n";
    cout << "2. Display Subjects\n";
    cout << "3. Calculate GWA\n";
    cout << "4. Delete Subject\n";
    cout << "5. Help\n";
    cout << "6. Exit\n";
    cout << "Enter: "; 
    cin >> option;
    return option;
};

void printHelp(){
    cout << "help help help help me help help ahhhhhhh" << endl;
};


