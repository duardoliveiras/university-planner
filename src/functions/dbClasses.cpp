#include "dbClasses.h"

void menuClasses(std::string code, int type, int filter, int order) {
  // read Database
  std::vector<myClass> data = readAllClasses();

  if (type == 1) {
    data = selectClass(code, data);
  } else {
    if (type == 2) {
      // filterInfoClass(filter, data);
    }
    // orderInfoClass(order, data);
  }

  printClass(data);
}

std::vector<myClass> filterInfoClass(int n, std::vector<myClass> &myVector) {
  workingMessage();
  return myVector;
}

std::vector<myClass> orderInfoClass(int n, std::vector<myClass> &myVector) {
  workingMessage();
  return myVector;
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