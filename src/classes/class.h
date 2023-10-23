#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <string>
#include <vector>

struct Slot {
  std::string weekday;
  float startHour;
  float duration;
  std::string type;

  // Constructor functions
  Slot(std::string wd, float startH, float dur, std::string t);

  // Getters functions
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
  // Constructor functions
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