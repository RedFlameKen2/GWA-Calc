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
        vector<double> gradingSystem;
        vector<int> totalAssessments; // Total Scores of each assessments
        vector<int> assessments; // Scores of each assessments
        vector<string> gradingSystemName;
        double finalGrade = 0.0, finalGradeUnit = 0.0, units = 0.0; 
        // finalGrade is the calculation of all Assessments. FinalGradeUnit is the finalGrade converted to units

    public:
    Subject(){
	initVars();
	calculateFinalGrade();
    }; 

    void initVars() {
    string subName;
	this -> name = inputString("Enter Subject name: ");
	this -> units = inputDouble("Enter Units: ");
    setGradingSystem();
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


    double getUnits(){
        return this->units;
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

    void initGradingSystemName(int size) {
        string name;
        cout << "\nPlease enter the names of the different aspects or categories that make up your grading system (e.g Midterms, Finals, Prelims, Activities, etc.).\n";
        // This loop will ask for the name of each grading system
        for (int i = 0; i < size; i++){
            cout << "Enter: ";
            if (cin.peek() == '\n')
                cin.ignore();
            getline(cin, name);
            this->gradingSystemName.push_back(name);
        }
    }

    bool isValidPercentage(int percentage) {
        if (percentage < 0 || percentage > 100)
            return false;
        else
            return true;
    }

    void initPercentageGradingSystem(int size) {
       int grade;
        for (int i = 0; i < size; i++){
            int sumPercentage = 0;
            cout << "Enter the percentage of " << gradingSystemName[i] << ": ";
            cin >> grade;
            // Checks if the percentage is greater than 100
            if (grade <= 100 || grade >= 0) {
                sumPercentage += grade;
                this->gradingSystem.push_back(grade);
                if (!isValidPercentage(sumPercentage)) {
                    cout << "The sum of the percentages is greater than 100. Please Try Again.\n";
                    this->gradingSystem.clear();
                    i = 0;
                }
            }
        }
    }

    void initAssessments() {
        int score;
        for (int i = 0; i < this->gradingSystemName.size(); i++){
            cout << "Enter the Maximum score of " << this->gradingSystemName[i] << ": ";
            cin >> score;
            this->totalAssessments.push_back(score);
        }

        for (int i = 0; i < gradingSystemName.size(); i++){
            cout << "Enter the score of your " << this->gradingSystemName[i] << ": ";
            cin >> score;
            loopCheck(score, totalAssessments[i], gradingSystemName[i]);
            this->assessments.push_back(score); 
        }

        
    }
    
    // Setters
        void setGradingSystem() {
        int size;
        cout << "How many Grading System do you have?: ";
        cin >> size;
        // This function will ask for the name of each grading system
        initGradingSystemName(size);
        // This function will ask for the percentage of each grading system
        initPercentageGradingSystem(size);
        // This function will ask for the score of each assessments
        initAssessments();
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
                // I had to multiply it by 100 before dividing. or Else it will just set it to 0.0
                vector<double> aveAssessments;
                for (int i = 0; i < gradingSystemName.size(); i++){
                    cout << gradingSystemName[i] << ": " << assessments[i] << "/" << totalAssessments[i] << endl;
                    aveAssessments.push_back((assessments[i] * 100) / totalAssessments[i]);
                }

                double result = 0.0;
                for (int i = 0; i < aveAssessments.size(); i++){
                    result += (aveAssessments[i] * (gradingSystem.at(i) / 100));
                }
                cout << "\n\nYour Final Grade for " << name << " is: " << result << "\n\n\n";
                this->finalGrade = result;
                setGradeToUnits();
        }
   
};
#endif
