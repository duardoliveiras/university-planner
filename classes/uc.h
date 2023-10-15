#include <iostream>
#include <string>
#include <vector>
#ifndef MYUC_H
#define MYUC_H

class myUc {
private:
  std::string ucCode;
  std::vector<std::string> classCode;

public:
  myUc(std::string ucC, std::vector<std::string> classC) {
    ucCode = ucC;
    classCode = classC;
  }
  myUc() {
    ucCode = "";
    classCode = {};
  }

  void SetInfo(std::string ucC, std::vector<std::string> classC) {
    ucCode = ucC;
    classCode = classC;
  }

  // setter
  void setUcCode(std::string n) { ucCode = n; }
  void setClassCode(std::vector<std::string> n) { classCode = n; }

  // getter
  std::string getUcCode() const { return ucCode; }
  std::vector<std::string> getClassCode() const { return classCode; }
};
#endif