#ifndef DBUCS_H
#define DBUCS_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../classes/uc.h"
#include "../inputoutput/read.h"

void workingMessage();
void errorMessage();

bool compareClassesCode(const myUc &uc1, const myUc &uc2);
bool compareUcsCode(const myUc &uc1, const myUc &uc2);

std::map<std::string, myUc> selectUc(const std::string &str,
                                     const std::map<std::string, myUc> &ucs);

// std::vector<myUc> filterInfoUc(int n, std::string str, std::vector<myUc>
// &ucs); std::vector<myUc> orderInfoUc(int n, std::vector<myUc> &ucs);

#endif