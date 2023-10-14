#include <iostream>
#include <string>
#include <vector>

#include "../classes/class.h"

int menuGroup(int n);
int menuOrder(int n);
std::string menuInfo(int n);
std::vector<myClass> readAllClasses();
std::vector<myClass> filterInfoClass(int n, std::vector<myClass> myVector);
std::vector<myClass> orderInfoClass(int n, std::vector<myClass> myVector);
std::vector<myClass> selectClass(std::string std, std::vector<myClass> myVector);

void printClass(std::vector<myClass> vecDB);


void dbClasses(int submenu) {
  int flag = submenu;
  std::string info = "";
  int group = 0;
  int order = 0;

  // read classes
  std::vector<myClass> data = readAllClasses();

  switch (flag) {
  case 1:
    info = menuInfo(flag);
    data = selectClass(info, data);
    break;
  case 2:
    group = menuGroup(flag);
    order = menuOrder(flag);
    data = filterInfoClass(group, data);
    data = orderInfoClass(order, data);
    break;
  case 3:
    data = orderInfoClass(order, data);
    break;
  default:
    std::cout << "ERROR: Invalid choice." << std::endl;
    break;
  }

  printClass(data);
}