#include <iostream>
#include <vector>

#include "../classes/student.h"

void printStudent(const std::vector<myStudent> &students) {
  std::cout << "Student Code | Student Name | Uc Code | Class Code"
            << std::endl;

  for (const auto &student : students) {
    std::cout << student.getStudentCode() << " | " << student.getStudentName()
              << " | ";

    const auto &ucCodes = student.getUcCode();
    for (const auto &ucCode : ucCodes) {
      std::cout << ucCode << " | ";
    }

    const auto &classCodes = student.getClassCode();
    for (const auto &classCode : classCodes) {
      std::cout << classCode;
    }
    std::cout << std::endl;
  }
}
