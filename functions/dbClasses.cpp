#include <iostream>
#include <vector>

#include "../classes/classe.h"

std::vector<myClass> readAllClasses();
void printDB(std::vector<int> vecDB);

void dbClasses(int submenu, int order) {
  std::cout << "This function dbClasses is not ready yet." << std::endl;

  // It will not be a vector of integers but of x class.
  std::vector<int> vecDB;

  // read classes
  std::vector<myClass> ucsData = readAllClasses();

  // filter classes depeding on submenu and order and put that info in vecDB
  // vecDB = ucsData

  // print information in vecDB
  printDB(vecDB);
}