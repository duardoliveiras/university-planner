#include <iostream>
#include <string>
#include <vector>

#include "uc.h"

myUc::myUc(std::string ucC, std::vector<std::string> classC) {
  ucCode = ucC;
  classCode = classC;
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
