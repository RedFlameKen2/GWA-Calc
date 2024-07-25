//
// Created by Eux on 04/03/2024.
//

#include <iostream>
#include <vector>
#include "functions.h"
#include "class.h"

void clearTerm(){
    #ifdef _WIN64
        system("cls");
    #elif _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif 
}

using namespace std;

void menu();

int main() {
    menu();
};

void menu(){
    vector<Subject> subs;

    cout << "Welcome to the GWA Calculator!\n\n";

    while(true){
	int option = getOption();
	switch(option){
	    case 1:
        clearTerm();
		progLogic(subs);
        cout << "Subject Added!\n\nPress any key to continue..." << endl;
        cin.get();
        clearTerm();
		break;
	    case 2:
        clearTerm();
        initTable(subs);
        cout << "\n\nPress Any Key to Continue...\n\n";
        cin.get();
        clearTerm();
		break;
        case 3:
        clearTerm();
        if (subs.size() == 0){
            cout << "No Subjects Added Yet!\n\nPress any key to continue..." << endl;
            cin.get();
            clearTerm();
            break;
        }
        calculateGWA(subs);
        calculateAveGrade(subs);
        cout << "GWA Calculated!\n\nPress any key to continue..." << endl;
        cin.get();
        clearTerm();
        break;
	    case 4:
        clearTerm();
        if (subs.size() == 0){
            cout << "No Subjects Added Yet!\n\nPress any key to continue..." << endl;
            cin.get();
            clearTerm();
            break;
        }
        initTable(subs);
        deleteSubject(subs);
        cout << "Deleted!\n\nPress any key to continue..." << endl;
        cin.get();
        clearTerm();
		break;
        case 5:
        clearTerm();
        printHelp();
        cout << "\n\nPress Any Key to Continue...\n\n";
        cin.get();
        clearTerm();
        break;
        case 6:
        cout << "Exiting program..." << endl;
        return;
	    default:
		cout << "Breh, not a valid option! doofus" << endl;
		break;
	}
    }
};

