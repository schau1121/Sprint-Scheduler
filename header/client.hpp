#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <vector>
#include <string>

//header files
#include "base.hpp"
#include "sortstrategy.hpp"
#include "../src/task.cpp"
#include "../src/tasklist.cpp"


using namespace std;

class client {
	private:
		vector<Base*> allObjects;
		vector<Base*> allTasks;
		vector<Base*> allLists;
		vector<Base*> allEvents;
		string sortingMethod;
	public:
		//constructor
		client();
		~client();

		void displayMenu();
		
		void load();
		void save();
		void clear();


		//print functions
		void view();
		void printAll(); 
		void printTasks();
		void printLists();
		void printEvents(); 

		//sort function
		void setSortingMethod();
		
		//completed functions
		void markAsCompleted();

		
		//create functions
		void create();
		void createTask();
		void createList();
		void createEvent();	

		
		//edit functions
		void addTaskToTaskList(Base* currList);	
		void addListToEvent(Base* currEvent);



		//edit functions
		void editList(Base* currObject);
		void editEvent(Base* currObject);
		void editTask(Base* currObject);


		//delete functions
		void delTask();
		void delList();
		void delEvent();


};

#endif //MENU_HPP
