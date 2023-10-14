#include <iostream>
#include <vector>

#include "../classes/uc.h"

std::vector<myUc> readAllUcs();
void printDB(std::vector<int> vecDB);

void dbUcs(int submenu, int order) {
  std::cout << "This function dbUcs is not ready yet." << std::endl;

  // It will not be a vector of integers but of x class.
  std::vector<int> vecDB;

  // read UCS
  std::vector<myUc> ucsData = readAllUcs();

  // filter Ucs depeding on submenu and order and put that info in vecDB
  // vecDB = ucsData

  // print information in vecDB
  printDB(vecDB);
}