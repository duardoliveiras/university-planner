#ifndef DBSTUDENTS_H
#define DBSTUDENTS_H

#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include "../classes/student.h"

void workingMessage();
void errorMessage();

std::map<std::string, myStudent>
selectStudent(const std::string &str,
              const std::map<std::string, myStudent> &students);
std::map<std::string, myStudent>
filterInfoStudent(int n, std::string str,
                  std::map<std::string, myStudent> &students);
std::map<std::string, myStudent>
orderInfoStudent(int n, std::map<std::string, myStudent> &students);

bool removeUcStudent(std::string ucCod,
                     std::map<std::string, myStudent>::iterator &it);
void addClassStudent(std::string ucCode, std::string classCode,
                     std::map<std::string, myStudent>::iterator &it,
                     std::stack<alter> &stackAlter);

std::map<int, std::set<classInfo>>
orderStudentClass(std::map<std::string, myStudent>::iterator &it,
                  std::map<std::string, myUc> &classes);
bool valideNewClass(std::string ucCode, std::string classCode,
                    std::map<std::string, myStudent>::iterator &it,
                    std::map<std::string, myUc> &classes);


void showStudentClasses(std::map<std::string, myStudent>::iterator &it,
                        std::map<std::string, myUc> &classes);
std::string weekDayString(int day);
bool verifyUcCode(std::string ucCode,
                  std::map<std::string, myStudent>::iterator &it);

bool compareStudentsCode(const myStudent &student1, const myStudent &student2);
bool compareClassesCode(const myStudent &student1, const myStudent &student2);
bool compareUcsCode(const myStudent &student1, const myStudent &student2);

#endif