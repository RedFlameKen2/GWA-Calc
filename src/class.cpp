#include "class.h"
#include <iostream>

using namespace std;

Subject::Subject(){
    this->name = "";
    this->activities;
    this->midterms = 0;
    this->finals = 0;
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

void Subject::setGradingSystem(){
    double grade;
    cout << "\nHow many categories are there in the grading system?: "; 
    int categories; cin >> categories;
    for (int i = 0; i < categories; i++)
    {
        cout <<"\nEnter weighting " << i+1 << ": "; cin >> grade;
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
void Subject::gradeToRemarks (double grade) {
    if(grade >= 97.5 && grade <= 100)
        cout << "Excellent";
    if(grade >= 94.5 && grade <= 97.4)
        cout << "Very Good";
    if(grade >= 91.5 && grade <= 94.4)
        cout << "Good";
    if(grade >= 88.5 && grade <= 91.4)
        cout << "Good";
    if(grade >= 85.5 && grade <= 88.4)
        cout << "Good";
    if(grade >= 82.5 && grade <= 85.4)
        cout << "Good";
    if(grade >= 79.5 && grade <= 82.4)
        cout << "Satisfactory";
    if(grade >= 76.5 && grade <= 79.4)
        cout << "Fair";
    if(grade >= 74.5 && grade <= 76.4)
        cout << "Fair";
    if(grade < 74.5)
        cout << "Failed";
}

