#ifndef MYSTUDENT_H
#define MYSTUDENT_H

#include <iostream>
#include <string>
#include <vector>

#include "uc.h"

class myStudent {
private:
  std::string studentCode;
  std::string studentName;
  std::vector<myUc> classes;

public:
  // Constructor functions
  myStudent(std::string &sCode, std::string &sName);
  myStudent();

  // Setter functions
  void setStudent(std::string &sCode, std::string &sName);
  void setStudentCode(std::string &n);
  void setStudentName(std::string &n);

  // Getters functions
  std::string getStudentCode() const;
  std::string getStudentName() const;
  // get student classes;

  void addClass(const myUc &myClass);
  void changeClass(const myUc &myClass);
  void addUc(const myUc &myClass);
  void removeUc(const myUc &myClass);

  bool valideQtClasses();
};

#endif