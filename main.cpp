//
// Created by Eux on 04/03/2024.
//

#include <iostream>
using namespace std;

void initTable (string subs[], float grades[], float units[], int size);
void initSetters (string subs[], float grades[], float units[], int size);
//    void displayInfo();
    static void gradeToRemarks(float grade);
    void setGradeToUnits(float grade[], float gToUnits[], int size);
    float calculateGWA(float gradeUnits[], float units[], int size);

    class Subjects {
    private:
        string name;
        int activities, midterms, finals , *arrActs, *gradingSystem;
        float results;
    public:
        Subjects(string name, int acts, int midterms, int finals, int *gradingSystem) {
            this->name = name;
            this->activities = acts;
            this->midterms = midterms;
            this->finals = finals;
            this->gradingSystem = gradingSystem;
        }
        // Gets the result of the activities
        void computeActivities (int numberOfActs) {
            float total = 0;
            for (int i = 0; i < numberOfActs; i++) {
                cout << "Enter score for activity " << i + 1 << ": ";
                cin >> arrActs[i];
                total += arrActs[i];
                cout << "Total: " << total << "\n";
            }
            results = total / numberOfActs;
        }
    };

int main() {
    int totalNumberOfSubs; // Amount of Subjects

    cout << "Enter number of subjects: "; cin >> totalNumberOfSubs;
    cin.ignore();
    string subjects[totalNumberOfSubs];
    int scoreFinals[totalNumberOfSubs], scoreMidterms[totalNumberOfSubs]; // Scores for each midterms/finals for each subject

    for (int i = 0; i < totalNumberOfSubs; i++) {
        cout << "Enter name of subject " << i + 1 << ": ";
        getline(cin, subjects[i]);
    }

    int activities[totalNumberOfSubs]; // An array of amount of activities for each subject
    int totalActs[totalNumberOfSubs]; // Total score of activities for each subject


    // Initialize the activities, exams, and grading system for each subjects
    for (int i = 0; i< totalNumberOfSubs; i++) {
        cout << "Enter the number of activities for " << subjects[i] << ": ";
        cin >> activities[i];
        cout << "Enter your score in midterms for " << subjects[i] << ": ";
        cin >> scoreMidterms[i];
        cout << "Enter your score in finals for " << subjects[i] << ": ";
        cin >> scoreFinals[i];
    }

    // Function that sums the total amount of Activities for each subject
    int score[totalNumberOfSubs];
    for (int i = 0; i < totalNumberOfSubs; i++) {
        int amountOfActivities = activities[i];
            for (int j = 0; j < amountOfActivities; j++) {
                totalActs[i] = 0;
                cout << "Enter your score in your activities for " << subjects[i] << ": ";
                cin >> totalActs[i];
                score[i] += totalActs[i];
            }
    }


    return 0;

}

void initSetters(string subs[], float grades[], float units[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter subject: ";
        cin >> subs[i];
        cout << "\nEnter number of units for " << subs[i] <<  ": "; cin >> units[i];
        cout << "\nEnter grade for " << subs[i] << ": "; cin >> grades[i];
    }
}

void initTable (string subs[], float grades[], float units[], int size) {

    float gToUnits[size];
    setGradeToUnits(grades, gToUnits, size);
    cout << "Subject\t\tUnits\t\tFinal Grade\t\tRemarks" << endl;
    for (int i = 0; i < size; i++) {
        cout << subs[i] << "\t\t" << units[i] << "\t\t" << gToUnits[i] << "\t\t";
        gradeToRemarks(grades[i]);
        cout << endl;
    }
    cout << "GWA: " << calculateGWA(gToUnits, units, size) << endl;

}

//void displayInfo() {
//    cout << "Name: " << name << endl;
//    cout << "Course: " << course << endl;
//    cout << "Year: " << year << endl;
//}

static void gradeToRemarks(float grade)
{
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


void setGradeToUnits(float grade[], float gToUnits[], int size) {
    for (int i = 0; i < size; i++) {
        if(grade[i] >= 97.5 && grade[i] <= 100)
            gToUnits[i] = 1.00;
        if(grade[i] >= 94.5 && grade[i] <= 97.4)
            gToUnits[i] = 1.25;
        if(grade[i] >= 91.5 && grade[i] <= 94.4)
            gToUnits[i] = 1.50;
        if(grade[i] >= 88.5 && grade[i] <= 91.4)
            gToUnits[i] = 1.75;
        if(grade[i] >= 85.5 && grade[i] <= 88.4)
            gToUnits[i] = 2.00;
        if(grade[i] >= 82.5 && grade[i] <= 85.4)
            gToUnits[i] = 2.25;
        if(grade[i] >= 79.5 && grade[i] <= 82.4)
            gToUnits[i] = 2.50;
        if(grade[i] >= 76.5 && grade[i] <= 79.4)
            gToUnits[i] = 2.75;
        if(grade[i] >= 74.5 && grade[i] <= 76.4)
            gToUnits[i] = 3.00;
        if(grade[i] < 74.5)
            gToUnits[i] = 5.00;
    }
}

float calculateGWA(float gradeUnits[], float units[], int size) {
    int totalUnits = 0;
    float totalGrade = 0;

    for (int i = 0; i < size; i++) {
        totalUnits += units[i];
        totalGrade += gradeUnits[i] * units[i];
    }
    return totalGrade / totalUnits;
}
