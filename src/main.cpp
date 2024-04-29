//
// Created by Eux on 04/03/2024.
//

#include <iostream>
#include <vector>
#include "functions.h"
#include "class.h"
#include "functions.cpp"
#include "class.cpp"


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
		progLogic(subs);
		break;
	    case 2:
        system("clear");
        initTable(subs);
        cout << "\n\nPress any key to continue..." << endl;
        getchar();
		break;
	    case 3:
		break;
        case 4:
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

