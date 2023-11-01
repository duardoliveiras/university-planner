#ifndef MYUC_H
#define MYUC_H

#include <iostream>
#include <string>
#include <vector>

struct classInfo {
  std::string code;
  std::string type;
  std::string day;
  int dayInt;
  double startTime;
  double duration;

  bool operator<(const classInfo &other) const {
    return startTime < other.startTime;
  }
};

struct classQtd {
  std::string classCode;
  int qtd;

  bool operator<(const classQtd &other) const {
    return classCode < other.classCode;
  }
};

class myUc {
private:
  std::string classCode;
  std::string ucCode;
  std::vector<classInfo> classInfoVec;

public:
  // Constructor functions
  myUc(const std::string &ucC, std::string &classC);
  myUc();

  // Setter functions
  void SetUc(std::string &ucC, std::string &classC);
  void setUcCode(std::string &n);
  void setClassCode(std::string &n);
  // void setClassCode(std::string &n);

  // Getters functions
  std::string getUcCode() const;
  std::string getClassCode() const;
  std::vector<classInfo> getClassInfoVec() const;

  // Others functions
  void addClass(const std::string &code);
  void addClassInfo(std::string type, std::string day, int dayInt,
                    double startTime, double duration);

  bool operator<(const myUc &other) const;
  static bool compareUcCode(const myUc &a, const myUc &b);
};

#endif