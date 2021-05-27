#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "client.cpp"
#include "tasklist.cpp"
#include "task.cpp"
#include "event.cpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

int main() {
  ofstream outFile;
  outFile.open("save.json");
  if(outFile.is_open()) {
    json j;
    j["task"]["name"] = "Task 1";
    outFile << setw(4) << j << endl;
  }


  return 0;
}
