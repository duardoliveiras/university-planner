#include <iostream>
#include <string>
#include <vector>

#include "dbStudents.h"

void menuStudents(std::string code, int type, int filter, int order) {
  // read Database
  std::vector<myStudent> data = readAllStudents();

  if (type == 1) {
    selectStudent(code, data);
  } else {
    if (type == 2) {
      filterInfoStudent(filter, data);
    }
    orderInfoStudent(order, data);
  }

  printStudent(data);
}
