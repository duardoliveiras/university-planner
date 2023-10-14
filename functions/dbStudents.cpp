#include <iostream>
#include <vector>

#include "../classes/student.h"

std::vector<myStudent> readAllStudents();
void printStudent(std::vector<myStudent> vecDB);

int menuGroup(int n);
int menuOrder(int n);
int menuInfo(int n);
std::vector<myStudent> filterInfo(int info,
                                  std::vector<myStudent> myStudentVector);
std::vector<myStudent> orderInfo(int order,
                                 std::vector<myStudent> myStudentVector);

void dbStudents(int submenu) {
  std::cout << "This function dbStudents is not ready yet." << std::endl;
  int flag = submenu;
  int info = 0;
  int group = 0;
  int order = 0;

  // read students
  std::vector<myStudent> data = readAllStudents();

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

  printStudent(data);
}