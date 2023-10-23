#ifndef MYSTUDENT_H
#define MYSTUDENT_H

#include <iostream>
#include <string>
#include <vector>

class myStudent {
private:
  int studentCode;
  std::string studentName;
  std::vector<std::string> ucCode;
  std::vector<std::string> classCode;

public:
  // Constructor functions
  myStudent(int sCode, std::string sName, std::vector<std::string> ucC,
            std::vector<std::string> classC);
  myStudent();

  // Setter functions
  void setStudent(int sCode, std::string sName, std::vector<std::string> ucC,
                  std::vector<std::string> classC);
  void setStudentCode(int n);
  void setStudentName(std::string n);
  void setUcCode(std::vector<std::string> n);
  void setClassCode(std::vector<std::string> n);

  // Getters functions
  int getStudentCode() const;
  std::string getStudentName() const;
  std::vector<std::string> getUcCode() const;
  std::vector<std::string> getClassCode() const;
};

#endif