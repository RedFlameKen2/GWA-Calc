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

