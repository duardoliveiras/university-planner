#include "uc.h"

myUc::myUc(const std::string &ucC, std::string &classC) {
  ucCode = ucC;
  classCode = classC;
}

myUc::myUc() {
  ucCode = "";
  classCode = {};
}

void myUc::SetUc(std::string &ucC, std::string &classC) {
  ucCode = ucC;
  classCode = classC;
}
void myUc::setUcCode(std::string &n) { ucCode = n; }
void myUc::setClassCode(std::string &n) { classCode = n; }

std::string myUc::getUcCode() const { return ucCode; }
std::string myUc::getClassCode() const { return classCode; }
std::vector<classInfo> myUc::getClassInfoVec() const { return classInfoVec; }

void myUc::addClass(const std::string &code) { classCode = code; }

void myUc::addClassInfo(std::string type, std::string day, int dayInt,
                        double startTime, double duration) {
  classInfo newClassInfo;
  newClassInfo.type = type;
  newClassInfo.day = day;
  newClassInfo.dayInt = dayInt;
  newClassInfo.startTime = startTime;
  newClassInfo.duration = duration;

  classInfoVec.push_back(newClassInfo);
}

bool myUc::compareUcCode(const myUc &a, const myUc &b) {
  return a.ucCode < b.ucCode;
}