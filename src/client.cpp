#include "../header/client.hpp"

void client::Delete(){

	char choice = ' ';
	
	cout << "Enter t or T to delete a task." << endl;
	cout << "Enter l or L to delete a list." << endl;
	cout << "Enter e or E to delete an event." << endl;
	cout << "Enter q or Q to quit." << endl;
	
	cin >> choice;

	while(choice != 'q' && choice != 'Q'){

	if(choice == 'e' || choice == 'E') {
		deleteEvent();
		break;
	}

	if(choice == 'l' || choice == 'L') {
		deleteList();
		break;
	}

	if(choice == 't' || choice == 'T') {
		deleteTask();
		break;	
	}	
	else {

		cout << "Invalid character or string entered." << endl;
                cout << "Please enter a valid character: " << endl;
                cin >> choice;
        }

	}

}

void client::deleteEvent(){

	int choice = -1;

	printEvents();

        cout << "Please enter the index of which event you would like to delete, indices start at 1: " << endl;

	cin >> choice; 

	while(choice == -1 || choice > allEvents.size()) { 
	
		cout << "Choice is out of range." << endl;
		cout << "Please enter a number between 1 and last index available." << endl;
		cin >> choice;
	}
	
	allEvents.erase(choice - 1);
}

void client::deleteList(){

int choice = -1;

        printLists();

        cout << "Please enter the index of which list you would like to delete, indices start at 1: " << endl;

        cin >> choice;

        while(choice == -1 || choice > allLists.size()) {

		cout << "Choice is out of range." << endl;
                cout << "Please enter a number between 1 and last index available." << endl;
                cin >> choice;

	}
	
	if(allLists.at(choice - 1).isAssigned()){
		
	
	}
	

	allLists.erase(choice - 1);
	
	
}

void client::deleteTask(){ 

	int choice = -1;

        printTasks();

        cout << "Please enter the index of which task you would like to delete, indices start at 1: " << endl;

        cin >> choice;

        while(choice == -1 || choice > allLists.size()) {

		cout << "Choice is out of range." << endl;
                cout << "Please enter a number between 1 and last index available." << endl;
                cin >> choice;

        }

	if(allTasks.at(choice - 1).isAssigned()) {

	
	}


        allTasks.erase(choice - 1);

}
