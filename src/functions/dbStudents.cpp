#include "dbStudents.h"

void menuStudents(std::string code, int type, int filter, int order) {
  // read Database
  std::vector<myStudent> data = readAllStudents();
  std::cout << code;
  std::cout << type;
  std::cout << filter;
  std::cout << order;
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
  std::vector<myStudent> scheduleStudent;

  for (const auto &student : students) {
    if (str == std::to_string(student.getStudentCode())) {
      scheduleStudent.push_back(student);
    }
  }

  return scheduleStudent;
}