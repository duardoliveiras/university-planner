#include <iostream>
#include <string>
#include <vector>
#ifndef MYCLASS_H
#define MYCLASS_H

struct Slot {
  std::string weekday;
  float startHour;
  float duration;
  std::string type;

  Slot(std::string wd, float startH, float dur, std::string t) {
    weekday = wd;
    startHour = startH;
    duration = dur;
    type = t;
  }

  // getter
  std::string getWeekday() const { return weekday; }
  float getStartHour() const { return startHour; }
  float getDuration() const { return duration; }
  std::string getType() const { return type; }
};

class myClass {
private:
  std::string classCode;
  std::string ucCode;
  std::vector<Slot> slot;

public:
  myClass(std::string cCode, std::string ucC, const std::vector<Slot> &s) {
    classCode = cCode;
    ucCode = ucC;
    slot = s;
  }

  myClass() {
    classCode = "";
    ucCode = "";
    slot = {};
  }

  void setClass(std::string cCode, std::string ucC,
                const std::vector<Slot> &s) {
    classCode = cCode;
    ucCode = ucC;
    slot = s;
  }

  // setter
  void setclassCode(std::string n) { classCode = n; }
  void setUcCode(std::string n) { ucCode = n; }
  void setSlot(std::vector<Slot> n) { slot = n; }

  // getter
  std::string getclassCode() const { return classCode; }
  std::string getUcCode() const { return ucCode; }
  std::vector<Slot> getSlot() const { return slot; }
};
#endif