#include "class.h"
#include <iostream>

using namespace std;

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

int Subject::getGradingSystem(int index) {
    return this->gradingSystem[index];
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
    cout << "\nEnter the sum of all of your Activities: ";
    cin >> this->activities;
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
    /* This function might get change soon.
        Might Make it more dynamic and not
        just limited to 3.

        This function adds the % of the Grading System
    */
    for (int i = 0; i < 3; i++)
    {   
        if (i == 0) 
        {
        cout <<"\nSet the % for Activities " << i+1 << ": "; 
        cin >> grade;
        this->gradingSystem.push_back(grade);
        }
        if (i == 1) 
        {
            cout << "Set the % for Midterms " << i+1 << ": ";
            cin >> grade;
            this->gradingSystem.push_back(grade);
        }

        if (i == 2)
        {
            cout << "Set the % for Finals " << i+1 << ": ";
            cin >> grade;
            this->gradingSystem.push_back(grade);
        }
    
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

// This Function converts the grade to remarks
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

// This Function Converts the Final Grade of a Subject to Units
 void Subject::setGradeToUnits() {{
        if(this->finalGrade >= 97.5 && this->finalGrade <= 100)
            this->finalGWA = 1.00;
        if(this->finalGrade >= 94.5 && this->finalGrade <= 97.4)
            this->finalGWA = 1.25;
        if(this->finalGrade >= 91.5 && this->finalGrade <= 94.4)
            this->finalGWA = 1.50;
        if(this->finalGrade >= 88.5 && this->finalGrade <= 91.4)
            this->finalGWA = 1.75;
        if(this->finalGrade >= 85.5 && this->finalGrade <= 88.4)
            this->finalGWA = 2.00;
        if(this->finalGrade >= 82.5 && this->finalGrade <= 85.4)
            this->finalGWA = 2.25;
        if(this->finalGrade >= 79.5 && this->finalGrade <= 82.4)
            this->finalGWA = 2.50;
        if(this->finalGrade >= 76.5 && this->finalGrade <= 79.4)
            this->finalGWA = 2.75;
        if(this->finalGrade >= 74.5 && this->finalGrade <= 76.4)
            this->finalGWA = 3.00;
        if(this->finalGrade < 74.5)
            this->finalGWA = 5.00;
    }
}

// This Funciton Calculates the Final Grade of a Subject
void Subject::calculateFinalGrade() {
        // I had to multiply it by 100 before dividing. or Else it will just set it to 0
        double aveAct = (this->activities * 100) / totalActivity;
        cout << "Activities: " << this->activities << "/" << totalActivity << endl;
        cout << "Average Act: " << aveAct << endl;
        double aveFinals = (this->finals * 100) / totalFinals;
        cout << "Finals: " << this->finals << "/" << this->totalFinals << endl;
        cout << "Average Finals: " << aveFinals << endl;
        double aveMidterms = (this->midterms * 100) / totalMidterms;
        cout << "Midterm Score: " << this->midterms << "/" << this->totalMidterms << endl;
        cout << "Average Midterms: " << aveMidterms << endl;
        double result = ((aveAct * (this->getGradingSystem(0) / 100.0)) + 
                         (aveMidterms * (this->getGradingSystem(1) / 100.0)) + 
                         (aveFinals * (this->getGradingSystem(2) / 100.0)));
        cout << "Final Grade: " << result << "\n\n\n";
        this->finalGrade = result;
}


