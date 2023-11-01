#ifndef DBSTUDENTS_H
#define DBSTUDENTS_H

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "../classes/student.h"

// int menuGroup(int n);
// int menuOrder(int n);
// std::string menuInfo(int n);
// std::vector<myStudent> readAllStudents();
// std::vector<myStudent> filterInfoStudent(int n, std::string str,
//                                          std::vector<myStudent> &students);
// std::vector<myStudent> orderInfoStudent(int n,
//                                         std::vector<myStudent> &students);
// std::vector<myStudent> selectStudent(std::string str,
//                                      std::vector<myStudent> &students);

// void printStudent(const std::vector<myStudent> &students);

void menuStudents(std::string code = "", int type = 0, int filter = 0,
                  int order = 0);
bool removeUcStudent(std::string ucCod,
                     std::map<std::string, myStudent>::iterator &it);
void addClassStudent(std::string ucCode, std::string classCode,
                     std::map<std::string, myStudent>::iterator &it);
std::map<int, std::set<classInfo>>
orderStudentClass(std::map<std::string, myStudent>::iterator &it,
                  std::map<std::string, myUc> &classes);
bool valideNewClass(std::string ucCode, std::string classCode,
                    std::map<std::string, myStudent>::iterator &it,
                    std::map<std::string, myUc> &classes);
// std::list<std::string> valideFreeClass(
//     std::map<std::string, std::vector<classQtd>>::iterator it_count);

void workingMessage();
void errorMessage();

// bool compareStudentsCode(const myStudent &student1, const myStudent
// &student2); bool compareClassesCode(const myStudent &student1, const
// myStudent &student2); bool compareUcsCode(const myStudent &student1, const
// myStudent &student2);

#endif