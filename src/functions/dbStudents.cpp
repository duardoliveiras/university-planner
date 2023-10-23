#include "dbStudents.h"

void menuStudents(std::string code, int type, int filter, int order) {
  // read Database
  std::vector<myStudent> data = readAllStudents();

  if (type == 1) {
    std::cout << "polaaaaaaa";
    data = selectStudent(code, data);
  } else {
    if (type == 2) {
      // filterInfoStudent(filter, data);
    }
    // orderInfoStudent(order, data);
  }

  printStudent(data);
}

std::vector<myStudent> filterInfoStudent(int n,
                                         std::vector<myStudent> &myVector) {
  workingMessage();
  return myVector;
}
std::vector<myStudent> orderInfoStudent(int n,
                                        std::vector<myStudent> &myVector) {
  workingMessage();
  return myVector;
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