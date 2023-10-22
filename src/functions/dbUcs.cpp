#include <iostream>
#include <string>
#include <vector>

#include "../classes/uc.h"

int menuGroup(int n);
int menuOrder(int n);
std::string menuInfo(int n);
std::vector<myUc> readAllUcs();
std::vector<myUc> filterInfoUc(int n, std::vector<myUc> myVector);
std::vector<myUc> orderInfoUc(int n, std::vector<myUc> myVector);
std::vector<myUc> selectUc(std::string str, std::vector<myUc> myVector);

void printUc(std::vector<myUc> vecDB);
void workingMessage();

void menuUcs(int order, int type) { workingMessage(); }

void dbUcs(int submenu) {
  // int flag = submenu;
  // std::string info = "";
  // int group = 0;
  // int order = 0;

  // read ucs
  std::vector<myUc> data = readAllUcs();

  // switch (flag) {
  // case 1:
  //   info = menuInfo(flag);
  //   data = selectUc(info, data);
  //   break;
  // case 2:
  //   group = menuGroup(flag);
  //   order = menuOrder(flag);
  //   data = filterInfoUc(group, data);
  //   data = orderInfoUc(order, data);
  //   break;
  // case 3:
  //   data = orderInfoUc(order, data);
  //   break;
  // default:
  //   std::cout << "ERROR: Invalid choice." << std::endl;
  //   break;
  // }

  printUc(data);
}