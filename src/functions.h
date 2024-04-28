#ifndef FUNCTIONS.H
#define FUNCTIONS.H

#include <vector>

void progLogic();
void menu();
void printHelp();
void initTable (string subs[], float grades[], float units[], int size);
void initSetters (string subs[], float grades[], float units[], int size);
static void gradeToRemarks(float grade);
void setGradeToUnits(float grade[], float gToUnits[], int size);
float calculateGWA(float gradeUnits[], float units[], int size);
int getOption();



void initTable (string subs[], float grades[], float units[], int size) {
    float gToUnits[12];
    setGradeToUnits(grades, gToUnits, size);
    cout << "Subject\t\tUnits\t\tFinal Grade\t\tRemarks" << endl;
    for (int i = 0; i < size; i++) {
        cout << subs[i] << "\t\t" << units[i] << "\t\t" << gToUnits[i] << "\t\t";
        gradeToRemarks(grades[i]);
        cout << endl;
    }
    cout << "GWA: " << calculateGWA(gToUnits, units, size) << endl;

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

void menu(){

    cout << "Welcome to the GWA Calculator!\n\n";

    while(true){
	int option = getOption();
	switch(option){
	    case 1:
		progLogic();
		break;
	    case 2:
		break;
	    case 3:
		break;
        case 4:
        printHelp();
        break;
        case 5:
        cout << "Exiting program..." << endl;
        return;
	    default:
		cout << "Breh, not a valid option! doofus" << endl;
		break;
	}
    }
};

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


#endif
