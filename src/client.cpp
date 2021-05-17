#include "../header/client.hpp"

void client:: createEvent() {

	string name = "";
	string date = "";
	string time = "";
	string details = "";
	double duration = 0;
		
	cout << "Creating an event..." << endl;
	
	cout << "Enter a name: " << endl;
	cin >> name;
	if(name == "") {
		cout << "ERROR: NEED AN EVENT NAME." << endl;
		return;
	}
	
	cout << "Enter a due date as MM/DD/YY: " << endl;
	cin >> date;

	cout << "Enter an event starting time as MONTH/DAY/HOUR: " << endl;
	cin >> time;
	
	cout << "Enter event details: " << endl;
	getline(cin, details);

	cout << "Enter event duration in hours: " << endl;
	cin >> duration; 

	Base* newEvent = new Event(name, date, time, details, duration);
	allObjects.push_back(newEvent);
	allEvents.push_back(newEvent);
	cout << "Event created!" << endl;	

}
