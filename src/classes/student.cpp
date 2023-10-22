#include <iostream>
#include <string>
#include <vector>

#include "student.h"

myStudent::myStudent(int sCode, std::string sName, std::vector<std::string> ucC,
                     std::vector<std::string> classC) {
  studentCode = sCode;
  studentName = sName;
  ucCode = ucC;
  classCode = classC;
}

myStudent::myStudent() {
  studentCode = 0;
  studentName = "";
  ucCode = {};
  classCode = {};
}

void myStudent::setStudent(int sCode, std::string sName,
                           std::vector<std::string> ucC,
                           std::vector<std::string> classC) {
  studentCode = sCode;
  studentName = sName;
  ucCode = ucC;
  classCode = classC;
}

void myStudent::setStudentCode(int n) { studentCode = n; }
void myStudent::setStudentName(std::string n) { studentName = n; }
void myStudent::setUcCode(std::vector<std::string> n) { ucCode = n; }
void myStudent::setClassCode(std::vector<std::string> n) { classCode = n; }

int myStudent::getStudentCode() const { return studentCode; }
std::string myStudent::getStudentName() const { return studentName; }
std::vector<std::string> myStudent::getUcCode() const { return ucCode; }
std::vector<std::string> myStudent::getClassCode() const { return classCode; }
