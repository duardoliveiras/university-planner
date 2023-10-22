#include <iostream>
#include <string>
#include <vector>

#include "../classes/class.h"
#include "../classes/student.h"
#include "../classes/uc.h"

void workingMessage();

void printClass(std::vector<myClass> classes) {

  std::cout
      << "ClassCode | UcCode | Weekday | StartHour | Duration | Type | Date"
      << std::endl;

  for (const auto &myclass : classes) {
    std::cout << myclass.getclassCode() << " | " << myclass.getUcCode();
  }
  std::cout << std::endl;
}

void printStudent(const std::vector<myStudent> &students) {
  std::cout << "Student Code | Student Name | Uc Code | Class Code"
            << std::endl;

  for (const auto &mystudent : students) {
    std::cout << mystudent.getStudentCode() << " | "
              << mystudent.getStudentName() << " | ";

    const auto &ucCodes = mystudent.getUcCode();
    for (const auto &ucCode : ucCodes) {
      std::cout << ucCode << " | ";
    }

    const auto &classCodes = mystudent.getClassCode();
    for (const auto &classCode : classCodes) {
      std::cout << classCode;
    }
    std::cout << std::endl;
  }
}

void printUc(std::vector<myUc> vecUc) { workingMessage(); }