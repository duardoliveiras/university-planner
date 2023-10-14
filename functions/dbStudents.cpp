#include <iostream>
#include <vector>

#include "../classes/student.h"

std::vector<myStudent> readAllStudents();
void printDB(std::vector<int> vecDB);

void dbStudents(int submenu, int order) {
  std::cout << "This function dbStudents is not ready yet." << std::endl;

  // It will not be a vector of integers but of x class.
  std::vector<int> vecDB;

  // read students
  std::vector<myStudent> ucsData = readAllStudents();

  // filter students depeding on submenu and order and put that info in vecDB
  // vecDB = ucsData

  // print information in vecDB
  printDB(vecDB);
}