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

void dbStudents(int submenu) {
  int flag = submenu;
  std::string info = "";
  int group = 0;
  int order = 0;

  // read students
  std::vector<myStudent> data = readAllStudents();

  switch (flag) {
  case 1:
    info = menuInfo(flag);
    data = selectStudent(info, data);
    break;
  case 2:
    group = menuGroup(flag);
    order = menuOrder(flag);
    data = filterInfoStudent(group, data);
    data = orderInfoStudent(order, data);
    break;
  case 3:
    data = orderInfoStudent(order, data);
    break;
  default:
    std::cout << "ERROR: Invalid choice." << std::endl;
    break;
  }

  printStudent(data);
}