#include <iostream>
#include <vector>
#include "client.cpp"
#include "tasklist.cpp"
#include "task.cpp"
#include "event.cpp"


using namespace std;

int main() {
  Event event = Event("Productivity block", "05/28/21", "10:00 AM", "Finish homework", 2.0);
  TaskList list = TaskList("Homework", "Finish project section", 3);
  list.addSubTask(Task("CS100 Final Project Sprint", "06/01/21", "Finish edit feature", 5));
  event.addSubTask(list);
  event.edit();
  
  return 0;
}
