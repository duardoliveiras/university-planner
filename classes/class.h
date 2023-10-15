#include <iostream>
#include <string>
#include <vector>
#ifndef MYCLASS_H
#define MYCLASS_H

struct ClassDate {
  std::string date;
  int day;
  int month;
  std::string year;
};

class myClass {
private:
  std::string classCode;
  std::string ucCode;
  std::vector<ClassDate> classDate;

public:
  myClass(std::string cCode, std::string ucC,
          const std::vector<ClassDate> &date) {
    classCode = cCode;
    ucCode = ucC;
    classDate = date;
  }

  myClass() {
    classCode = "";
    ucCode = "";
    classDate = {};
  }

  void setClass(std::string cCode, std::string ucC,
                const std::vector<ClassDate> &date) {
    classCode = cCode;
    ucCode = ucC;
    classDate = date;
  }

  // SET
  void setclassCode(std::string n) { classCode = n; }
  void setUcCodee(std::string n) { ucCode = n; }
  void setClassDate(std::vector<ClassDate> n) { classDate = n; }

  // GET
  std::string getclassCode() const { return classCode; }
  std::string getUcCodee() const { return ucCode; }
  std::vector<ClassDate> getClassDate() const { return classDate; }
};
#endif