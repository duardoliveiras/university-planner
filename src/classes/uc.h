#ifndef MYUC_H
#define MYUC_H

#include <iostream>
#include <string>
#include <vector>

class myUc {
private:
  std::string ucCode;
  std::vector<std::string> classCode;

public:
  // Constructor functions
  myUc(std::string ucC, std::vector<std::string> classC);
  myUc();

  // Setter functions
  void SetUc(std::string ucC, std::vector<std::string> classC);
  void setUcCode(std::string n);
  void setClassCode(std::vector<std::string> n);

  // Getters functions
  std::string getUcCode() const;
  std::vector<std::string> getClassCode() const;
};

#endif