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
    int sum = 0;
    for (int x : this->activities) {
        sum += x;
    }
    return sum;
}

int Subject::getMidterms(){
    return this->midterms;
}

int Subject::getFinals(){
    return this->finals;
}


// Setters
void Subject::setSubject(){
    cout << "Enter Subject: ";
    cin >> this->name;
}

void Subject::setActivities(){
    int score;
    cout << "Enter Score: "; cin >> score;
    this->activities.push_back(score);
}
// Other Functions
void Subject::gradeToRemarks(float grade) {
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

