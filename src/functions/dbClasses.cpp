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

bool compareClassesCode(const myClass &class1, const myClass &class2) {
  return class1.getClassCode() < class2.getClassCode();
}
bool compareUcsCode(const myClass &class1, const myClass &class2) {
  return class1.getUcCode() < class2.getUcCode();
}

std::vector<myClass> orderInfoClass(int n, std::vector<myClass> &classes) {
  std::vector<myClass> orderClass = classes;

  switch (n) {
  case 1:
    // 2) Sort by uc code asc
    std::sort(orderClass.begin(), orderClass.end(), compareUcsCode);
    break;
  case 2:
    // 2) Sort by uc code desc
    std::sort(orderClass.begin(), orderClass.end(), compareUcsCode);
    std::reverse(orderClass.begin(), orderClass.end());
    break;
  case 3:
    // 3) Sort by class code asc
    std::sort(orderClass.begin(), orderClass.end(), compareClassesCode);

    break;
  case 4:
    // 4) Sort by class code desc
    std::sort(orderClass.begin(), orderClass.end(), compareClassesCode);
    std::reverse(orderClass.begin(), orderClass.end());
    break;
  case 5:
    // 5) Sort by year asc
    std::sort(orderClass.begin(), orderClass.end(), compareClassesCode);
    break;
  case 6:
    // 6) Sort by year desc
    std::sort(orderClass.begin(), orderClass.end(), compareClassesCode);
    std::reverse(orderClass.begin(), orderClass.end());
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