#include <iostream>
#include <vector>
#include "client.cpp"
#include "tasklist.cpp"
#include "task.cpp"
#include "event.cpp"

using namespace std;

int main() {
  client driver;
  driver.createEvent();
  
  return 0;
}
