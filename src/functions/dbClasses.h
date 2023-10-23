#ifndef DBCLASSES_H
#define DBCLASSES_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../classes/class.h"

int menuGroup(int n);
int menuOrder(int n);
std::string menuInfo(int n);
std::vector<myClass> readAllClasses();
std::vector<myClass> filterInfoClass(int n, std::vector<myClass> &myVector);
std::vector<myClass> orderInfoClass(int n, std::vector<myClass> &myVector);
std::vector<myClass> selectClass(std::string str,
                                 std::vector<myClass> &myVector);

void printClass(const std::vector<myClass> &classes);

void menuClasses(std::string code = "", int type = 0, int filter = 0,
                 int order = 0);

void workingMessage();
void errorMessage();

bool compareClassesCode(const myClass &class1, const myClass &class2);
bool compareUcsCode(const myClass &class1, const myClass &class2);

#endif