#include <iostream>
#include <vector>
#include <string>

#include "../header/client.hpp"

using namespace std;

client::client() {
	//call load function to populate the vector data members
	
	this->sortingMethod = "priority" //default sorting method

}




client::~client() {

	for(auto i : allTasks) {
		delete i;
	}
	allTaks.clear();
	
	for(auto i : allLists) {
		delete i;
	}
	allLists.clear();

	for(auto i : allEvents) {
		delete i;
	}
	allEvents.clear();

	//delete all pointers within the vector data members
	//clear the contents of the vectors
}







