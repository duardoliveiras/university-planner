#include <iostream>
#include <string>
#include <vector>
#ifndef STUDENT_H
#define STUDENT_H


class Student {
  private:
    int studentCode;
    std::string studentName;
    std::vector<std::string> ucCode;
    std::vector<std::string> classCode;

  public:
    Student(int sCode, std::string sName, std::vector<std::string> ucC, std::vector<std::string> classC) {
      studentCode = sCode;
      studentName = sName;
      ucCode = ucC;
      classCode = classC;
    }
    Student() {
      studentCode = 0;
      studentName = "";
      ucCode = {};
      classCode = {};
    }

  void setInfo(int sCode, std::string sName, std::vector<std::string> ucC, std::vector<std::string> classC) {
    studentCode = sCode;
    studentName = sName;
    ucCode = ucC;
    classCode = classC;
  }

  // SET 
  void setStudentCode(int n) {
    studentCode = n;
  }
  void setStudentName(std::string n) {
    studentName = n;
  }
  void setUcCode(std::vector<std::string> n) {
    ucCode = n;
  }
  void setClassCode(std::vector<std::string> n) {
    classCode = n;
  }

  // GET
  int getStudentCode() {
    return studentCode;
  }
  std::string getStudentName() {
    return studentName;
  }
  std::vector<std::string> getUcCode() {
    return ucCode;
  }
  std::vector<std::string> getClassCode() {
    return classCode;
  }


};
#endif