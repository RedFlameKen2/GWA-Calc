#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include <iostream>

using namespace std;

class Subject {
    private:
        string name, remarks;
        int midterms, finals, activities, totalActivity, totalMidterms, totalFinals;
        vector<double> gradingSystem;
        double finalGrade = 0.0, finalGWA = 0.0, units = 0.0; 
        // Final Grade is Average of this->grade. Final GWA is the Final Grade converted to units

    public:
    Subject();  
    // Getters
    string getSubject();
    int getActivities();
    int getMidterms();
    int getFinals();
    double getUnits();
    // Getters for total
    int getTotalActivity();
    int getTotalMidterms();
    int getTotalFinals();
    double getFinalGrade();
    double getFinalGWA();
    string getRemarks();
    int getGradingSystem(int index);
    // Setters
    void setSubject();
    void setActivities();
    void setMidterms();
    void setFinals();
    void setGradingSystem();
    void setUnits();

    // Setters for Total
    void setTotalActivity();
    void setTotalMidterms();
    void setTotalFinals();

    // Other Functions
    string gradeToRemarks(float grade);
    void setGradeToUnits();
    void calculateFinalGrade();
};
#endif