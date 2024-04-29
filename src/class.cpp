#include "class.h"
#include <iostream>

using namespace std;

Subject::Subject(){
    this->name = "";
    this->activities;
    this->midterms = 0;
    this->finals = 0;
    this->units = 0.0f;
    this->gradingSystem;
}

// Getters

string Subject::getSubject(){
    return this->name;
}

int Subject::getActivities(){
    return this->activities;
}

int Subject::getMidterms(){
    return this->midterms;
}

int Subject::getFinals(){
    return this->finals;
}

double Subject::getUnits(){
    return this->units;
}

// Getters for total
int Subject::getTotalActivity(){
    return this->totalActivity;
}

int Subject::getTotalMidterms(){
    return this->totalMidterms;
}

int Subject::getTotalFinals(){
    return this->totalFinals;
}   

double Subject::getFinalGrade(){
    return this->finalGrade;
}

double Subject::getFinalGWA(){
    return this->finalGWA;
}

string Subject::getRemarks(){
    return this->remarks;
}

// Setters
void Subject::setSubject(){
    cout << "\nEnter Subject Name: ";
    cin >> this->name;
}

void Subject::setActivities(){
    int score;
    cout << "\nEnter the sum of all of your Activities: "; cin >> score;
    this->activities = score;
}

void Subject::setMidterms(){
    cout << "\nEnter Midterms Score: ";
    cin >> this->midterms;
}

void Subject::setFinals(){
    cout << "\nEnter Finals Score: ";
    cin >> this->finals;
}

void Subject::setUnits() {
    cout << "\nEnter Units: ";
    cin >> this->units;
}


void Subject::setGradingSystem(){
    double grade;
    cout << "\nHow many components are there in the grading system?(e.g 30% Activities, 30% Midterms, 40% Finals = '3'): "; 
    int categories; cin >> categories;
    for (int i = 0; i < categories; i++)
    {
        cout <<"\nEnter component " << i+1 << ": "; cin >> grade;
        this->gradingSystem.push_back(grade);
    }
    
}

// Setters for Total

void Subject::setTotalActivity(){
    cout << "\nEnter Total Activity: ";
    cin >> this->totalActivity;
}

void Subject::setTotalMidterms(){
    cout << "\nEnter Max Score for Midterms: ";
    cin >> this->totalMidterms;
}

void Subject::setTotalFinals(){
    cout << "\nEnter Max Score for Finals: ";
    cin >> this->totalFinals;
}


// Other Functions
string Subject::gradeToRemarks (float grade) {
    if(grade >= 97.5f && grade <= 100)
        return "Excellent";
    if(grade >= 94.5f && grade <= 97.4f)
        return "Very Good";
    if(grade >= 91.5f && grade <= 94.4f)
        return "Good";
    if(grade >= 88.5f && grade <= 91.4f)
        return "Good";
    if(grade >= 85.5f && grade <= 88.4f)
        return "Good";
    if(grade >= 82.5f && grade <= 85.4f)
        return "Good";
    if(grade >= 79.5f && grade <= 82.4f)
        return "Satisfactory";
    if(grade >= 76.5f && grade <= 79.4f)
        return "Fair";
    if(grade >= 74.5f && grade <= 76.4f)
        return "Fair";
    if(grade < 74.5f)
        return "Failed";
    
    return "Invalid Grade";
}

 void Subject::setGradeToUnits(vector<Subject> &subjects) {
    for (Subject &sub : subjects) {
        float finalGrade = sub.getFinalGrade();
        sub.finalGWA = 0.0f;

        if(finalGrade >= 97.5 && finalGrade <= 100)
            sub.finalGWA = 1.00f;
        if(finalGrade >= 94.5 && finalGrade <= 97.4)
            sub.finalGWA = 1.25f;
        if(finalGrade >= 91.5 && finalGrade <= 94.4)
            sub.finalGWA = 1.50f;
        if(finalGrade >= 88.5 && finalGrade <= 91.4)
            sub.finalGWA = 1.75f;
        if(finalGrade >= 85.5 && finalGrade <= 88.4)
            sub.finalGWA = 2.00f;
        if(finalGrade >= 82.5 && finalGrade <= 85.4)
            sub.finalGWA = 2.25f;
        if(finalGrade >= 79.5 && finalGrade <= 82.4)
            sub.finalGWA = 2.50f;
        if(finalGrade >= 76.5 && finalGrade <= 79.4)
            sub.finalGWA = 2.75f;
        if(finalGrade >= 74.5 && finalGrade <= 76.4)
            sub.finalGWA = 3.00f;
        if(finalGrade < 74.5)
            sub.finalGWA = 5.00f;
    }
}
