#include <iostream>
#include <vector>
#include <string>

#include "../header/client.hpp"

using namespace std;





client::displayMenu() {
	char userInput = ' ';

 	do {
		cout << "Select an option or press 'q' to quit" << endl;
		cout << "1. View (press 'v')" << endl;
		cout << "2. Create a task, tasklist, or an event (press 'c')" << endl;
		
		cin >> userInput;


		switch(userInput) {
			case 'V':
			case 'v':
				cout << "FIXME: Call view function" << endl;
				break;
			case 'C':
			case 'c':
				cout << "FIXME: Call create function" << endl;
				break;
			default:
				cout << "ERROR: Invalid Input, please try again or press 'q' to quit" << endl;
				break;
		}
	}
	while(userInput != 'q' || userInput != 'Q');


	//call save function before return
	
	return;
}



