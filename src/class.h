#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include <iostream>
#include <string>
#include <limits>

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
    this -> activities = inputInt("Enter the total score of all of your Activities: ");
    loopCheck(this->activities, this->totalActivity, subName = "Activitites");
    this -> midterms = inputInt("Enter the total score of your Midterms: ");
    loopCheck(this->midterms, this->totalMidterms, subName = "Midterms");
    this -> finals = inputInt("Enter the total score of your Finals: ");
    loopCheck(this->finals, this->totalFinals, subName = "Finals");
    }


    // Input Functions 

    string inputString(string prompt){
	string out;
	cout << prompt;
    cin.ignore();
    getline(cin, out);
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

    void loopCheck (int &x, int &xTotal, string &subName) {
        while (!isValid(x, xTotal)) {
            cout << "Invalid score for " << subName << ".\nTry Again.\n";
            cout << "Enter the total score of your " << subName << ": "; 
            cin >> x;
        }
    }

    // Getters
    string getSubject(){
    return this->name;
}

    int getActivities(){
        return this->activities;
    }

    int getMidterms(){
        return this->midterms;
    }

    int getFinals(){
        return this->finals;
    }

    double getUnits(){
        return this->units;
    }
    // Getters for total
    int getTotalActivity(){
        return this->totalActivity;
    }

    int getTotalMidterms(){
        return this->totalMidterms;
    }

    int getTotalFinals(){
        return this->totalFinals;
    }   

    double getFinalGrade(){
        return this->finalGrade;
    }

    double getFinalGradeUnit(){
        return this->finalGradeUnit;
    }

    string getRemarks(){
        return this->remarks;
    }

    int getGradingSystem(int index) {
    return this->gradingSystem[index];
}

    // Setters
    void setGradingSystem(){
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

        void setTotalActivity(){
            cout << "\nEnter Total Activity: ";
            cin >> this->totalActivity;
        }

        void setTotalMidterms(){
            cout << "\nEnter Max Score for Midterms: ";
            cin >> this->totalMidterms;
        }

        void setTotalFinals(){
            cout << "\nEnter Max Score for Finals: ";
            cin >> this->totalFinals;
        }

   
        // Other Functions

        // This Function converts the grade to remarks
        string gradeToRemarks (float grade) {
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
        void setGradeToUnits() {{
                if(this->finalGrade >= 97.5 && this->finalGrade <= 100)
                    this->finalGradeUnit = 1.00;
                if(this->finalGrade >= 94.5 && this->finalGrade <= 97.4)
                    this->finalGradeUnit = 1.25;
                if(this->finalGrade >= 91.5 && this->finalGrade <= 94.4)
                    this->finalGradeUnit = 1.50;
                if(this->finalGrade >= 88.5 && this->finalGrade <= 91.4)
                    this->finalGradeUnit = 1.75;
                if(this->finalGrade >= 85.5 && this->finalGrade <= 88.4)
                    this->finalGradeUnit = 2.00;
                if(this->finalGrade >= 82.5 && this->finalGrade <= 85.4)
                    this->finalGradeUnit = 2.25;
                if(this->finalGrade >= 79.5 && this->finalGrade <= 82.4)
                    this->finalGradeUnit = 2.50;
                if(this->finalGrade >= 76.5 && this->finalGrade <= 79.4)
                    this->finalGradeUnit = 2.75;
                if(this->finalGrade >= 74.5 && this->finalGrade <= 76.4)
                    this->finalGradeUnit = 3.00;
                if(this->finalGrade < 74.5)
                    this->finalGradeUnit = 5.00;
            }
        }

        // This Funciton Calculates the Final Grade of a Subject
        void calculateFinalGrade() {
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

                setGradingSystem();

                double result = ((aveAct * (this->getGradingSystem(0) / 100.0)) + 
                                (aveMidterms * (this->getGradingSystem(1) / 100.0)) + 
                                (aveFinals * (this->getGradingSystem(2) / 100.0)));
                cout << "Final Grade: " << result << "\n\n\n";
                this->finalGrade = result;
                setGradeToUnits();
        }
   
};
#endif
