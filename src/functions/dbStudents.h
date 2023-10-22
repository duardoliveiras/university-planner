#include <iostream>
#include <string>
#include <vector>

#include "../classes/student.h"

int menuGroup(int n);
int menuOrder(int n);
std::string menuInfo(int n);
std::vector<myStudent> readAllStudents();
std::vector<myStudent> filterInfoStudent(int n,
                                         std::vector<myStudent> myVector);
std::vector<myStudent> orderInfoStudent(int n, std::vector<myStudent> myVector);
std::vector<myStudent> selectStudent(std::string str,
                                     std::vector<myStudent> myVector);

void printStudent(const std::vector<myStudent> &students);

void menuStudents(std::string code = "", int type = 0, int filter = 0,
                  int order = 0);
