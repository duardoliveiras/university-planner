#ifndef DBUCS_H
#define DBUCS_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../classes/uc.h"

int menuGroup(int n);
int menuOrder(int n);
std::string menuInfo(int n);
std::vector<myUc> readAllUcs();
std::vector<myUc> filterInfoUc(int n, std::string str, std::vector<myUc> &ucs);
std::vector<myUc> orderInfoUc(int n, std::vector<myUc> &ucs);
std::vector<myUc> selectUc(std::string str, std::vector<myUc> &ucs);

void printUc(const std::vector<myUc> &ucs);

void menuUcs(std::string code = "", int type = 0, int filter = 0,
             int order = 0);

void workingMessage();
void errorMessage();

bool compareClassesCode(const myUc &uc1, const myUc &uc2);
bool compareUcsCode(const myUc &uc1, const myUc &uc2);

#endif