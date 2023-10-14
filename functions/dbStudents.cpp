#include <iostream>
#include <vector>

#include "../classes/student.h"

std::vector<myStudent> readAllStudents();
void printStudent(std::vector<myStudent> vecDB);

int menuGroup(int flag);
int menuOrder(int flag);
int menuInfo(int flag);
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
  std::vector<myStudent> ucsData = readAllStudents();

  switch (flag) {
  case 1:
    info = menuInfo(flag);
    ucsData = filterInfo(info, ucsData);
    break;
  case 2:
    group = menuGroup(flag);
    order = menuOrder(flag);
    ucsData = filterInfo(group, ucsData);
    ucsData = orderInfo(order, ucsData);
    break;
  case 3:
    ucsData = orderInfo(order, ucsData);
    break;
  default:
    std::cout << "ERROR: Invalid choice." << std::endl;
    break;
  }

  printStudent(ucsData);
}