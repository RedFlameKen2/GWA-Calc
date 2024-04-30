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
    string subName;
	this -> name = inputString("Enter Subject name: ");
	this -> units = inputDouble("Enter Units: ");
	this -> totalActivity = inputInt("Enter the Maximum Score for Activities: ");
	this -> totalMidterms = inputInt("Enter the Maximum Score for Midterms: ");
	this -> totalFinals = inputInt("Enter the Maximum Score for Finals: ");
    bool isBigger;
    this -> activities = inputInt("Enter the total score of all of your Activities: ");
    loopCheck(isBigger = true, this->activities, this->totalActivity, subName = "Activitites");
    this -> midterms = inputInt("Enter the total score of your Midterms: ");
    loopCheck(isBigger = true, this->midterms, this->totalMidterms, subName = "Midterms");
    this -> finals = inputInt("Enter the total score of your Finals: ");
    loopCheck(isBigger = true, this->finals, this->totalFinals, subName = "Finals");
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

    // Guard Checks

    bool isValid(int x, int xTotal) {
        if (x < 0)
        return false;

        if (x > xTotal)
         return false;
        else 
        return true;
    }

    void loopCheck (bool &check, int &x, int &xTotal, string &subName) {
        while (!isValid(x, xTotal)) {
            cout << "Invalid score for " << subName << ".\nTry Again.\n";
            cout << "Enter the total score of your " << subName << ": "; 
            cin >> x;
        }
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
