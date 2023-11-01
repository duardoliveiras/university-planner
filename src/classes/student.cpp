#include "student.h"

myStudent::myStudent(std::string &sCode, std::string &sName) {
  studentCode = sCode;
  studentName = sName;
}

myStudent::myStudent() {
  studentCode = "";
  studentName = "";
}

void myStudent::setStudent(std::string &sCode, std::string &sName) {
  studentCode = sCode;
  studentName = sName;
}
void myStudent::setStudentCode(std::string &n) { studentCode = n; }
void myStudent::setStudentName(std::string &n) { studentName = n; }

std::string myStudent::getStudentCode() const { return studentCode; }
std::string myStudent::getStudentName() const { return studentName; }

void myStudent::addClass(const myUc &myClass) { classes.push_back(myClass); }

bool myStudent::valideQtClasses() {
  if (classes.size() > 7) {
    return true;
  }
  return false;
}
