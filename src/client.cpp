#include "../header/client.hpp"

void client::createList(){

	string name = "";
	string details = "";
	int priority = 0;

	cout << "Creating a task list..." << endl;
	
	cout << "Enter a task list name: " << endl;
	cin >> name;
	
	if(name == "") {
	cout << "ERROR: NEED TASK LIST NAME" << endl;
	return;
	}

	cout << "Enter task list details: " << endl;
	getline(cin, details);

	cout << "Enter task list priority 0-5: " << endl;
	cin >> priority;

	Base* newList = new tasklist(name, details, priority);
	allObjects.push_back(newList);
	allLists.push_back(newList);

	cout << "Task list created!" << endl;
}
