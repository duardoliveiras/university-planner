#include "uc.h"

myUc::myUc(std::string ucC, std::vector<std::string> classC) {
  ucCode = ucC;
  classCode = classC;
}

myUc::myUc(std::string ucC) {
  ucCode = ucC;
  classCode = {};
}

myUc::myUc() {
  ucCode = "";
  classCode = {};
}

void myUc::SetUc(std::string ucC, std::vector<std::string> classC) {
  ucCode = ucC;
  classCode = classC;
}
void myUc::setUcCode(std::string n) { ucCode = n; }
void myUc::setClassCode(std::vector<std::string> n) { classCode = n; }

std::string myUc::getUcCode() const { return ucCode; }
std::vector<std::string> myUc::getClassCode() const { return classCode; }

void myUc::addClass(std::string code) {
  classCode.push_back(code);
}
