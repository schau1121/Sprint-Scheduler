#include "../header/client.hpp"

void client::Delete(){

	char choice;
	
	cout << "Enter t or T to delete a task." << endl;
	cout << "Enter l or L to delete a list." << endl;
	cout << "Enter e or E to delete an event." << endl;

	cin >> choice;

	if(choice == 'e' || 'E') {
		deleteEvent();
	}

	if(choice == 'l' || 'L') {
		deleteList();
	}

	if(choice == 't' || 'T') {
		deleteTask();
	}

	else {
		cout << "Invalid character or string entered." << endl;
		cout << "Please enter a valid character: " << endl;
		cin >> choice;
	}
} 

void client::deleteEvent(){



}

void client::deleteList(){



}

void client::deleteTask(){ 



}
