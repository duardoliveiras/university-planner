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

  Slot(std::string wd, float startH, float dur, std::string t);

  std::string getWeekday() const;
  float getStartHour() const;
  float getDuration() const;
  std::string getType() const;
};

class myClass {
private:
  std::string classCode;
  std::string ucCode;
  std::vector<Slot> slot;

public:
  myClass(std::string cCode, std::string ucC, const std::vector<Slot> &s);
  myClass();

  // Setter functions
  void setClass(std::string cCode, std::string ucC, const std::vector<Slot> &s);
  void setClassCode(std::string n);
  void setUcCode(std::string n);
  void setSlot(std::vector<Slot> n);

  // Getters functions
  std::string getClassCode() const;
  std::string getUcCode() const;
  std::vector<Slot> getSlot() const;
};
#endif