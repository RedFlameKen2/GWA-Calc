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
        double finalGrade = 0.0, finalGradeUnit = 0.0, units = 0.0; 
        // finalGrade is the calculation of activities, midterms and finals. Final GWA is the finalGrade converted to units

    public:
    Subject(){
	initVars();
    calculateFinalGrade();
    }; 

    void initVars() {
	this -> name = inputString("Enter Subject name: ");
    this -> units = inputDouble("Enter Units: ");
    this -> totalActivity = inputInt("Enter the Maximum Score for Activities: ");
    this -> totalMidterms = inputInt("Enter the Maximum Score for Midterms: ");
    this -> totalFinals = inputInt("Enter the Maximum Score for Finals: ");
	this -> activities = inputInt("Enter the total score of all of your Activities: ");
	this -> midterms = inputInt("Enter Midterms: ");
	this -> finals = inputInt("Enter Finals: ");
    }


    // Input Functions 

    string inputString(string prompt){
	string out;
	cout << prompt;
	cin >> out;
	return out;
    }

    int inputInt(string prompt){
	int out;
	cout << prompt;
	cin >> out;
	return out;
    }

    double inputDouble(string prompt){
	double out;
	cout << prompt;
	cin >> out;
	return out;
    }
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
    double getFinalGradeUnit();
    string getRemarks();
    int getGradingSystem(int index);
    // Setters
    void setGradingSystem();

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
