#include <iostream>
#include <vector>

#include "../classes/uc.h"

std::vector<myUc> readAllUcs();
void printUc(std::vector<myUc> vecDB);

int menuGroup(int n);
int menuOrder(int n);
int menuInfo(int n);
std::vector<myUc> filterInfo(int info, std::vector<myUc> myStudentVector);
std::vector<myUc> orderInfo(int order, std::vector<myUc> myStudentVector);

void dbUcs(int submenu) {
  std::cout << "This function dbUcs is not ready yet." << std::endl;
  int flag = submenu;
  int info = 0;
  int group = 0;
  int order = 0;

  // read ucs
  std::vector<myUc> data = readAllUcs();

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

  printUc(data);
}