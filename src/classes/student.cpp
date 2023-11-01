#include "student.h"

myStudent::myStudent(const std::string &sCode, const std::string &sName) {
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
std::vector<std::string> myStudent::getUcCode() const {
  std::vector<std::string> ucCodes;
  for (const auto &uc : classes) {
    ucCodes.push_back(uc.getUcCode());
  }
  return ucCodes;
}
std::vector<std::string> myStudent::getClassCode() const {
  std::vector<std::string> classCodes;
  for (const auto &uc : classes) {
    std::vector<classInfo> classInfoVec = uc.getClassInfoVec();
    for (const auto &classInfo : classInfoVec) {
      classCodes.push_back(classInfo.code);
    }
  }
  return classCodes;
}
std::vector<myUc> &myStudent::getClasses() { return classes; }

void myStudent::addClass(const myUc &myClass) { classes.push_back(myClass); }

bool myStudent::valideQtClasses() {
  if (classes.size() > 7) {
    return true;
  }
  return false;
}
