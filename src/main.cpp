#include <iostream>

//insert includes for header files

using namespace std;

/*
    So as of right now, I'm thinking that we are going to need to store our objects
    in a vector or some kind of list, and then we iterate over that list to
    save our data into a JSON file

    this would be so much easier in python but i found a framework that should help

    So when our app initializes we should parse through the json and collect all the objects
    so that we can edit & display them
    */

//MENU FUNCTION
void menu() {
	char userInput = ' ';

	do {cout << "Select an option or press q to quit: " << endl;
		cin >> userInput;

		switch(userInput) {
			case 'A':
			case 'a':
				cout << "FIXME: Add function" << endl;
				break;
			case 'D':
			case 'd':
				cout << "FIXME: Delete function" << endl;
				break;
			case 'E':
			case 'e':
				cout << "FIXME: Edit function" << endl;
				break;
			case 'P':
			case 'p':
				cout << "FIXME: Display function" << endl;
				break;
			default:
				cout << "Invalid input, please try again." << endl;
				break;

		}

	} while( userInput != 'q');

	return;
	
}

void save() {
	cout << "FIXME: Implement save function" << endl;
	return;

}

int main() {

    //run menu
 	menu();   

    //save files
    	save();

    return 0;
}
