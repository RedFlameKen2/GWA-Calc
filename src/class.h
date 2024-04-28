#ifndef CLASS.H
#define CLASS.H
#include <iostream>
#include <vector>

using namespace std;

class Subject {
    private:
        string name;
        vector<int> activities;
        int midterms, finals;
        vector<double> gradingSystem;

    public:
        Subject();  
    // Getters
    string getSubject();
    int getActivities();
    int getMidterms();
    int getFinals();

    // Setters
    void setSubject();
    void setActivities();
    void setMidterms();
    void setFinals();
    void setGradingSystem();
    // Other Functions
    static void gradeToRemarks(float grade);
    void setGradeToUnits();



};



#endif