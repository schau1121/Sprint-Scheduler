#ifndef CLIENT_CPP
#define CLIENT_CPP

#include "../header/client.hpp"

using namespace std;



client::client() {
	//call load function to populate the vector data members
	
	this->sortingMethod = "priority"; //default sorting method

}

client::~client() {}

void client::displayMenu() {
	char choice = ' ';
	int runTime = 0;
	
	if(runTime == 0) { cout << "Welcome to your task scheduler!" << endl; }
	
	


	

	while(choice != 'q' && choice != 'Q') {
		
		cout << "Enter v or V to view your tasks, lists, and events." << endl;
                cout << "Enter c or C to create new tasks, lists, or events." << endl;
                cout << "Enter s or S to set sorting method." << endl;
                cout << "Press q or Q to quit." << endl;
		
		cin >> choice;


		if(choice == 's' || choice == 'S') {
			setSortingMethod();
		}

		else if(choice == 'v' || choice == 'V') {  
			view();
			
				cout << "Enter e or E to edit." << endl;
				cout << "Enter d or D to delete." << endl;
				cout << "Enter m or M to mark as complete." << endl;
				cin >> choice;
				
				if(choice == 'e' || choice == 'E') { 
					cout << "Enter t or T to edit a task." << endl;
					cout << "Enter l or L to edit a list." << endl;
					cout << "Enter e or E to edit an event." << endl; 
					cout << "Press q or Q to quit." << endl;

					cin >> choice;
			                 
					if(choice == 't' || choice == 'T') {  
					       printTasks();
					       cout << "Input the task to edit: " << endl;
					       int thisTask;
					       cin >> thisTask;
					       editTask(allTasks.at(thisTask - 1));					       				       break; 
					}

					if(choice == 'l' || choice == 'L') {  
					       printLists();
                                               cout << "Input the list to edit: " << endl;
                                               int thisList;
                                               cin >> thisList;
                                               editList(allLists.at(thisList - 1));
					}
                		        if(choice == 'e' || choice == 'E') {  
					       printEvents();
                                               cout << "Input the event to edit: " << endl;
                                               int thisEvent;
                                               cin >> thisEvent;
                                               editEvent(allEvents.at(thisEvent - 1));
					}
				 }
				else if(choice == 'd' || choice == 'D') {
					cout << "FIXME: call delete " << endl;
				}
				
				else if(choice == 'm' || choice == 'M') {
				        cout << "Enter t or T to mark a task." << endl;
                                        cout << "Enter l or L to mark a list." << endl;
                                        cout << "Enter e or E to mark an event." << endl;
                                        cout << "Press q or Q to quit." << endl;

                                        cin >> choice;
					
					if(choice == 'q' || choice == 'Q') { break; }	
					
                                        if(choice == 't' || choice == 'T') {
                                               if(allTasks.size() == 0) {
							cout << "Nothing to mark." << endl;
							break;
					       } 
					       printTasks();
                                               cout << "Input the task to mark: " << endl;
                                               int thisTaskI;
                                               cin >> thisTaskI;
					       markAsCompletedT(allTasks.at(thisTaskI - 1));
                                        }
                                        if(choice == 'l' || choice == 'L') {
                                               if(allLists.size() == 0) {
                                                        cout << "Nothing to mark." << endl;
                                                        break;
                                               }

					       printLists();
                                               cout << "Input the list to mark: " << endl;
                                               int thisListI;
                                               cin >> thisListI;
                                               markAsCompletedL(allLists.at(thisListI - 1));
                                        }
                                        if(choice == 'e' || choice == 'E') {
					       if(allEvents.size() == 0) {
                                                        cout << "Nothing to mark." << endl;
                                                        break;
                                               }                                               

					       printEvents();
                                               cout << "Input the event to mark: " << endl;
                                               int thisEventI;
                                               cin >> thisEventI;
                                               markAsCompletedE(allEvents.at(thisEventI - 1));

                                        }

				}
			   
                           
		}

                else if(choice == 'c' || choice == 'C') {  create(); choice = ' '; }
		
		else { cout << "Invalid character or string entered." << endl;
                       cout << "Please enter a valid character: " << endl;
                }
				
			
		runTime++;
	}


	cout << "Goodbye!" << endl;
	



}

void client::markAsCompletedT(Task &obj) {
	if(!obj.isAssigned()) {
		obj.setCompleted(true);
		cout << "Success!" << endl;
	
	}

}
void client::markAsCompletedL(TaskList &obj) {
	obj.setCompleted(true);
}
void client::markAsCompletedE(Event &obj) {}



void client::view() {
	char choice = ' ';

	cout << "Enter a or A to view all." << endl;
	cout << "Enter t or T to view tasks." << endl;
	cout << "Enter l or L to view tasklists." << endl;
	cout << "Enter e or E to view events." << endl;

	cin >> choice;

	while(choice != 'q' && choice != 'Q') {

		if(choice == 'a' || choice == 'A') {  printAll();    break; }
		if(choice == 't' || choice == 'T') {  printTasks();  break; }
		if(choice == 'l' || choice == 'L') {  printLists();  break; }
		if(choice == 'e' || choice == 'E') {  printEvents(); break; }
		
		else { cout << "Invalid character or string entered." << endl;
		       cout << "Please enter a valid character: " << endl;
		       cin >> choice;
		}

	
	}
}

void client::create() {

	char choice = ' ';
	
	cout << "Enter t or T to create a task." << endl;
	cout << "Enter l or L to create a list." << endl;
	cout << "Enter e or E to create an event." << endl;
	cout << "Enter q or Q to quit." << endl;
	
	cin >> choice;

	while(choice != 'q' && choice != 'Q') {

	  if(choice == 'e' || choice == 'E') {
		  createEvent();
		  break;
	  }

	  if(choice == 'l' || choice == 'L') {
		  createList();
		  break;
	  }

	  if(choice == 't' || choice == 'T') {
		  createTask();
		  break;
	  }
	
	  else{
      cout << "Invalid character or string entered." << endl;
      cout << "Please enter a valid character: " << endl;
      cin >> choice;
	  }
	}
}

/*
    Add in parameter for string stream into display function to test that
    shouldn't need to test print functions since they should just loop over the vector and call display(cout)
*/

void client::printAll() {

	if(allTasks.size() == 0 && allLists.size() == 0 && allEvents.size() == 0) {
		cout << "There is nothing to display." << endl; 
		return;
	}

	this->printEvents();
	this->printLists();
	this->printTasks();	
}

void client::printTasks() {

	if(allTasks.size() == 0) { cout << "There are no tasks to display." << endl; return; }

	for(int i = 0; i < allTasks.size(); i++) {
		if(!(allTasks.at(i).isAssigned())) {
			cout << (i+1) << ". ";
			allTasks.at(i).display();
			cout << endl;
		}
	}
}

void client::printLists() {

	if(allLists.size() == 0) { cout << "There are no lists to display." << endl; return; }

 	for(int i = 0; i < allLists.size(); i++) {
		cout << (i+1) << ". ";
		allLists.at(i).display();
		cout << endl;

	}   
}

void client::printEvents() {

	if(allEvents.size() == 0) { cout << "There are no events to display." << endl; return; }

	for(int i = 0; i < allEvents.size(); i++) {
		cout << (i+1) << ". ";
		allEvents.at(i).display();
		cout << endl;

	}
}

/*
    Change date and time format check into bool functions and unit test those
*/
void client::createEvent() {
	string name = "";
	string date = "";
	string time = "";
	string details = "";
	double duration = 0;
		
	cout << "Creating an event..." << endl;
	
	cout << "Enter a name: " << endl;
	getline(cin, name);
	while(name == "") {
		cout << "No event name entered!" << endl;
		cout << "Please enter an event name: " << endl;
		getline(cin, name);
	}
	
	cout << "Enter a due date as MM/DD/YY: " << endl;
	cin >> date;
	while(date[2] != '/' || date[5] != '/') {
		cout << "Wrong date format entered!" << endl;
		cout << "Enter date format as MM/DD/YY: " << endl;
		cin >> date;
	}

	cout << "Enter an event starting time HH:MM AM/PM: " << endl;
	cin >> time;
	while(time[2] != ':' || time.substr(6,7) != "AM" && time.substr(6,7) != "PM" && time.substr(6,7) != "am" && time.substr(6,7) != "pm") {
                cout << "Wrong time format entered!" << endl;
                cout << "Enter time format as HH:MM AM/PM: " << endl;
                cin >> time;
        }
	
	cout << "Enter event details: " << endl;
	getline(cin, details);
	while(details == "") {
                cout << "No event details entered!" << endl;
                cout << "Please enter event details: " << endl;
                getline(cin, details);
        }

	cout << "Enter event duration in hours: " << endl;
	cin >> duration; 
	while(duration == 0) {
                cout << "No event duration entered!" << endl;
                cout << "Please enter event duration: " << endl;
                cin >> duration;
        }

	Event newEvent = Event(name, date, time, details, duration);
	allEvents.push_back(newEvent);
	cout << "Event created!" << endl;	

}

/*
    Change priority checking int function and unit test that
*/
void client::createList(){

	string name = "";
	string details = "";
	int priority = -1;

	cout << "Creating a task list..." << endl;
	
	cout << "Enter a task list name: " << endl;
	getline(cin, name);	
	while(name == "") {
                cout << "No task list name entered!" << endl;
                cout << "Please enter a task list name: " << endl;
                getline(cin, name);
        }

	cout << "Enter task list details: " << endl;
	getline(cin, details);
	while(details == "") {
                cout << "No task list details entered!" << endl;
                cout << "Please enter task list details: " << endl;
                getline(cin, details);
        }

	cout << "Enter task list priority 0-5: " << endl;
	cin >> priority;
	while(priority < 0 || priority > 5) {
		cout << "Invalid priority entered!" << endl;
		cout << "Please enter a priority from 0-5: " << endl;
		cin >> priority;
	}	

	TaskList newList = TaskList(name, details, priority);
	allLists.push_back(newList);

	cout << "Task list created!" << endl;
} 

/*
    use date and priority checking functions from comments above in here 
*/

void client::createTask() {
        
	string name = "";
        string date = "";
        string details = "";
        int priority = -1;
        
	cout << "Creating a task..." << endl;
 
        cout << "Enter a name: ";
        getline(cin, name);
	    while(name == "") {
                cout << "No task name entered!" << endl;
                cout << "Please enter a task name: " << endl;
                getline(cin, name);
        }      
 
        cout << "Enter a due date as MM/DD/YY: ";
        cin >> date;
	while(date[2] != '/' || date[5] != '/') {
                cout << "Wrong date format entered!" << endl;
                cout << "Enter date format as MM/DD/YY: " << endl;
                cin >> date;
        }

        cout << "Enter task details: ";
        getline(cin, details);
 	while(details == "") {
                cout << "No task list details entered!" << endl;
                cout << "Please enter task list details: " << endl;
                getline(cin, details);
        }
      

	cout << "Enter task priority as 0-5: ";
        cin >> priority;
  	while(priority < 0 || priority > 5) {
                cout << "Invalid priority entered!" << endl;
                cout << "Please enter a priority from 0-5: " << endl;
                cin >> priority;
        }
 
        Task newTask = Task(name, date, details, priority);
        allTasks.push_back(newTask);
        cout << "Task created!" << endl;
}

void client::setSortingMethod() {
    int userInput;
    cout << "1. Sort by due date" << endl;
    cout << "2. Sort by priority" << endl;
    cout << "How would you like to sort your task list?" << endl;
    cout << "Enter the number corresponding to which sort you'd like to use: ";
    cin >> userInput;
    while(userInput > 2 || userInput < 0) {
        cout << "\nERROR: Enter either 1 or 2: ";
        cin >> userInput;
    }
    if(userInput == 1) {
        sortingMethod = "date";
    }
    if(userInput == 2) {
        sortingMethod = "priority";
    }
    cout << "\nSorting strategy selected!" << endl;
}

void client::addTaskToTaskList(TaskList &currList) {
    char userInput = ' ';
    while(userInput != 'q' || userInput != 'Q') {
        if(allTasks.empty() == true) {
            cout << "ERROR: There are no tasks created" << endl;
            //can add option to create a task
            return;
        }
        cout << "Printing all unassigned tasks..." << endl;
        printTasks();
        cout << "Enter the number of the task you would like to add to this list: ";
        cin >> userInput;
        while((int)userInput > allTasks.size() || (int)userInput < 0) {
            cout << "ERROR: Invalid input" << endl;
            cout << "Enter the number of the task you would like to add to this list: ";
            cin >> userInput;
        }
        if(!allTasks[userInput - 1].isAssigned()) {
            cout << "Adding " << '\"' << allTasks[(int)userInput - 1].getName() << '\"...' << endl;
            currList.addSubTask(allTasks[(int)userInput - 1]);
            allTasks[(int)userInput - 1].setAssigned(true);
            cout << "Successfully added to this list!" << endl;
            cout << "Enter 'q' to quit or 'c' to continue adding tasks to this list: ";
            cin >> userInput;
        }
        else {
            cout << "ERROR: Task is assigned already" << endl;
            userInput = 'q';
        }
    }
}

void client::addListToEvent(Event &currEvent) {
    char userInput = ' ';
    while(userInput != 'q' || userInput != 'Q') {
        if(allLists.empty() == true) {
            cout << "ERROR: There are no lists created" << endl;
            return;
        }
        cout << "Printing all unassigned lists..." << endl;
        printLists();
        cout << "Enter the number of the list you would like to add to this list (or enter 'q' to quit): ";
        cin >> userInput;
        while((int)userInput > allTasks.size() || (int)userInput < 0) {
            cout << "ERROR: Invalid input" << endl;
            cout << "Enter the number of the list you would like to add to this event: ";
            cin >> userInput;
        }
        if(!allLists[userInput - 1].isAssigned()) {
            cout << "Adding " << '\"' << allLists[(int)userInput - 1].getName() << '\"...' << endl;
            currEvent.addSubTask(allLists[(int)userInput - 1]);
            allLists[(int)userInput - 1].setAssigned(true);
            cout << "Successfully added to this event!" << endl;
            cout << "Enter 'q' to quit or 'c' to continue adding lists to this event: ";
            cin >> userInput;
        }
        else {
            cout << "ERROR: List is assigned already" << endl;
            userInput = 'q';
        } 
    }
}

/*
    Use format checking functions from above in this as well
    Change edit function to take in parameter for string stream
    when called in gtest, define the string stream;
    in client, pass in cin
*/

void client::editTask(Task &currObject) {
    currObject.edit();
}

void client::editList(TaskList &currObject) {
    currObject.edit();
}

void client::editEvent(Event &currObject) {
    currObject.edit();
}

#endif
