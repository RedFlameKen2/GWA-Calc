
#include <vector>
#include <iostream>
#include "functions.h"
#include "class.h"

using namespace std;

void progLogic(){
    vector<Subject> subjects;
    subjects.push_back(Subject()); // Creates a new subject
    for (Subject &x : subjects) {
         if(x.getSubject() == ""){
            x.setSubject();
            x.setTotalActivity();
            x.setTotalMidterms();
            x.setTotalFinals();
            x.setActivities();
            x.setMidterms();
            x.setFinals();
            x.setGradingSystem(); 
        }
    }
};

void initTable () {
    cout << "Subject\t\tUnits\t\tFinal Grade\t\tRemarks" << endl;


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



int getOption(){
    int option;
    cout << "1. Enter Subject\n";
    cout << "2. Display Subjects\n";
    cout << "3. Calculate GWA\n";
    cout << "4. Help\n";
    cout << "5. Exit\n";
    cin >> option;
    return option;
};

void printHelp(){
    cout << "help help help help me help help ahhhhhhh" << endl;
};
