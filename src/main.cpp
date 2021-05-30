#include <iostream>
#include <vector>
#include "client.cpp"
#include "tasklist.cpp"
#include "task.cpp"
#include "event.cpp"

using namespace std;

int main() {
  client driver;
  cout << "---TASKS---" << endl;
  for(int i = 0; i < driver.allTasks.size(); i++) {
    driver.allTasks[i].display();
    cout << endl;
  }
  cout << "---TASK-LISTS---" << endl;
  for(int i = 0; i < driver.allLists.size(); i++) {
    driver.allLists[i].display();
    cout << endl;
  }
  cout << "---EVENTS---" << endl;
  for(int i = 0; i < driver.allEvents.size(); i++) {
    driver.allEvents[i].display();
    cout << endl;
  }
  
  return 0;
}
