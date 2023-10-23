#include "dbStudents.h"

void menuStudents(std::string code, int type, int filter, int order) {
  // read Database
  std::vector<myStudent> data = readAllStudents();

  if (type == 1) {
    std::cout << "polaaaaaaa";
    data = selectStudent(code, data);
  } else {
    if (type == 2) {
      data = filterInfoStudent(filter, data);
    }
    data = orderInfoStudent(order, data);
  }

  printStudent(data);
}

std::vector<myStudent> filterInfoStudent(int n,
                                         std::vector<myStudent> &myVector) {
  workingMessage();
  return myVector;
}
std::vector<myStudent> orderInfoStudent(int n,
                                        std::vector<myStudent> &students) {
  std::vector<myStudent> orderStudent;

  switch (n) {
  case 1:
    // 2) Sort by uc code asc
    break;
  case 2:
    // 2) Sort by uc code desc
    break;
  case 3:
    // 3) Sort by class code asc
    break;
  case 4:
    // 4) Sort by class code desc
    break;
  case 5:
    // 5) Sort by year
    break;
  default:
    errorMessage();
    break;
  }

  return orderStudent;
}

std::vector<myStudent> selectStudent(std::string str,
                                     std::vector<myStudent> &students) {
  std::vector<myStudent> selectStudent;

  for (const auto &mystudent : students) {
    if (str == std::to_string(mystudent.getStudentCode())) {
      selectStudent.push_back(mystudent);
    }
  }

  return selectStudent;
}