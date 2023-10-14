#include <iostream>
#include <string>
#include <vector>

#include "../classes/uc.h"

int menuGroup(int n);
int menuOrder(int n);
int menuInfo(int n);
std::vector<myUc> readAllUcs();
std::vector<myUc> filterInfoUc(int n, std::vector<myUc> myVector);
std::vector<myUc> orderInfoUc(int n, std::vector<myUc> myVector);
void printUc(std::vector<myUc> vecDB);

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
    data = filterInfoUc(info, data);
    break;
  case 2:
    group = menuGroup(flag);
    order = menuOrder(flag);
    data = filterInfoUc(group, data);
    data = orderInfoUc(order, data);
    break;
  case 3:
    data = orderInfoUc(order, data);
    break;
  default:
    std::cout << "ERROR: Invalid choice." << std::endl;
    break;
  }

  printUc(data);
}