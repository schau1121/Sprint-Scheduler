#include <iostream>
#include <vector>
#include "client.cpp"
#include "tasklist.cpp"
#include "task.cpp"
#include "event.cpp"

using namespace std;

int main() {
  client run;
  run.displayMenu();
  return 0;
}

/*
delete out of range error
need to call add task to taskList somewhere
and add taskList to event
*/

