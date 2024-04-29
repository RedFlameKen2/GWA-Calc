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
        // finalGrade is the calculation of activities, midterms and finals. Final GWA is the finalGrade converted to units

    public:
    Subject(){
	initVars();
    };  
    void initVars(){
	this -> name = inputString("Enter Subject name: ");
	this -> activities = inputInt("Enter the sum of all of your Activities: ");
	this -> midterms = inputInt("Enter Midterms: ");
	this -> finals = inputInt("Enter Finals: ");
	this -> units = inputDouble("Enter Units: ");
    }

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
    double getFinalGWA();
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
