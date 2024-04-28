#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include <iostream>

using namespace std;

class Subject {
    private:
        string name;
        int midterms, finals, activities, totalActivity, totalMidterms, totalFinals;
        vector<double> gradingSystem;
        double finalGrade;
        float finalGWA = 0.0f;

    public:
    Subject();  
    // Getters
    string getSubject();
    int getActivities();
    int getMidterms();
    int getFinals();
    // Getters for total
    int getTotalActivity();
    int getTotalMidterms();
    int getTotalFinals();
    // Setters
    void setSubject();
    void setActivities();
    void setMidterms();
    void setFinals();
    void setGradingSystem();

    // Setters for Total
    void setTotalActivity();
    void setTotalMidterms();
    void setTotalFinals();

    // Other Functions
    static void gradeToRemarks(double grade);
    void setGradeToUnits();
};
#endif