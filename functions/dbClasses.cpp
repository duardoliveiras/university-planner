#include <iostream>
#include <vector>

#include "../classes/class.h"

std::vector<myClass> readAllClasses();
void printClass(std::vector<myClass> vecDB);

int menuGroup(int n);
int menuOrder(int n);
int menuInfo(int n);
std::vector<myClass> filterInfo(int info,
                                  std::vector<myClass> myClassVector);
std::vector<myClass> orderInfo(int order,
                                 std::vector<myClass> myClassVector);

void dbClasses(int submenu) {
  std::cout << "This function dbClasses is not ready yet." << std::endl;
  int flag = submenu;
  int info = 0;
  int group = 0;
  int order = 0;

  // read classes
  std::vector<myClass> data = readAllClasses();

  switch (flag) {
  case 1:
    info = menuInfo(flag);
    data = filterInfo(info, data);
    break;
  case 2:
    group = menuGroup(flag);
    order = menuOrder(flag);
    data = filterInfo(group, data);
    data = orderInfo(order, data);
    break;
  case 3:
    data = orderInfo(order, data);
    break;
  default:
    std::cout << "ERROR: Invalid choice." << std::endl;
    break;
  }

  printClass(data);
}