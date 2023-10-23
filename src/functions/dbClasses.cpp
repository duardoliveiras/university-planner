#include "dbClasses.h"

void menuClasses(std::string code, int type, int filter, int order) {
  // read Database
  std::vector<myClass> data = readAllClasses();

  if (type == 1) {
    data = selectClass(code, data);
  } else {
    if (type == 2) {
      data = filterInfoClass(filter, data);
    }
    data = orderInfoClass(order, data);
  }

  printClass(data);
}

std::vector<myClass> filterInfoClass(int n, std::vector<myClass> &myVector) {
  workingMessage();
  return myVector;
}

std::vector<myClass> orderInfoClass(int n, std::vector<myClass> &myVector) {
  std::vector<myClass> orderClass;

  switch (n) {
  case 1:
    // 2) Sort by uc code asc
    break;
  case 2:
    // 2) Sort by uc code desc
    break;
  case 3:
    // 3) Sort by class code asc
    break;
  case 4:
    // 4) Sort by class code desc
    break;
  case 5:
    // 5) Sort by year
    break;
  default:
    errorMessage();
    break;
  }

  return orderClass;
}

std::vector<myClass> selectClass(std::string str,
                                 std::vector<myClass> &classes) {
  std::vector<myClass> selectClass;

  for (const auto &myclass : classes) {
    if (str == myclass.getClassCode()) {
      selectClass.push_back(myclass);
    }
  }

  return selectClass;
}