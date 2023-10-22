#include <iostream>
#include <string>
#include <vector>

#include "../classes/uc.h"

int menuGroup(int n);
int menuOrder(int n);
std::string menuInfo(int n);
std::vector<myUc> readAllUcs();
std::vector<myUc> filterInfoUc(int n,
                                         std::vector<myUc> myVector);
std::vector<myUc> orderInfoUc(int n, std::vector<myUc> myVector);
std::vector<myUc> selectUc(std::string str,
                                     std::vector<myUc> myVector);

void printUc(const std::vector<myUc> &ucs);

void menuUcs(std::string code = "", int type = 0, int filter = 0,
                  int order = 0);
