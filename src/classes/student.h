#ifndef MYSTUDENT_H
#define MYSTUDENT_H

#include <iostream>
#include <string>
#include <vector>

#include "uc.h"

struct alter {
  std::string studentCode;
  std::string studentName;
  std::string type;
  std::string ucCode;
  std::string classCode;
};

class myStudent {
private:
  std::string studentCode;
  std::string studentName;
  mutable std::vector<myUc> classes;

public:
  // Constructor functions
  myStudent(const std::string &sCode, const std::string &sName);
  myStudent();

  // Setter functions
  void setStudent(std::string &sCode, std::string &sName);
  void setStudentCode(std::string &n);
  void setStudentName(std::string &n);

  // Getters functions
  std::string getStudentCode() const;
  std::string getStudentName() const;
  std::vector<std::string> getUcCode() const;
  std::vector<std::string> getClassCode() const;
  std::vector<myUc> &getClasses() const;

  // Others functions
  void addClass(const myUc &myClass);
  void changeClass(const myUc &myClass);
  void addUc(const myUc &myClass);
  void removeUc(const myUc &myClass);
  bool valideQtClasses();
};

#endif