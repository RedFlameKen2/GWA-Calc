//
// Created by Eux on 04/03/2024.
//

#include <iostream>
#include <vector>
#include "functions.h"
#include "class.h"
#include <conio.h>


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
        system("cls");
		progLogic(subs);
        cout << "Subject Added!\n\nPress any key to continue..." << endl;
        getch();
        system("cls");
		break;
	    case 2:
        system("cls");
        initTable(subs);
        cout << "\n\nPress Any Key to Continue...\n\n";
        getch();
        system("cls");
		break;
        case 3:
        system("cls");
        if (subs.size() == 0){
            cout << "No Subjects Added Yet!\n\nPress any key to continue..." << endl;
            getch();
            system("cls");
            break;
        }
        calculateGWA(subs);
        calculateAveGrade(subs);
        cout << "GWA Calculated!\n\nPress any key to continue..." << endl;
        getch();
        system("cls");
        break;
	    case 4:
        system("cls");
        if (subs.size() == 0){
            cout << "No Subjects Added Yet!\n\nPress any key to continue..." << endl;
            getch();
            system("cls");
            break;
        }
        initTable(subs);
        deleteSubject(subs);
        cout << "Deleted!\n\nPress any key to continue..." << endl;
        getch();
        system("cls");
		break;
        case 5:
        system("cls");
        printHelp();
        cout << "\n\nPress Any Key to Continue...\n\n";
        getch();
        system("cls");
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

