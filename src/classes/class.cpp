#include "class.h"

Slot::Slot(std::string wd, float startH, float dur, std::string t) {
  weekday = wd;
  startHour = startH;
  duration = dur;
  type = t;
}

std::string Slot::getWeekday() const { return weekday; }
float Slot::getStartHour() const { return startHour; }
float Slot::getDuration() const { return duration; }
std::string Slot::getType() const { return type; }

myClass::myClass(std::string cCode, std::string ucC,
                 const std::vector<Slot> &s) {
  classCode = cCode;
  ucCode = ucC;
  slot = s;
}

myClass::myClass() {
  classCode = "";
  ucCode = "";
  slot = {};
}

void myClass::setClass(std::string cCode, std::string ucC,
                       const std::vector<Slot> &s) {
  classCode = cCode;
  ucCode = ucC;
  slot = s;
}
void myClass::setClassCode(std::string n) { classCode = n; }
void myClass::setUcCode(std::string n) { ucCode = n; }
void myClass::setSlot(std::vector<Slot> n) { slot = n; }

std::string myClass::getClassCode() const { return classCode; }
std::string myClass::getUcCode() const { return ucCode; }
std::vector<Slot> myClass::getSlot() const { return slot; }
