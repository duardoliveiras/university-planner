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

void errorMessage();

std::map<std::string, myStudent> selectStudent(const std::string &str, const std::map<std::string, myStudent> &students);
std::vector<myStudent> filterInfoStudent(int n, std::string str, const std::vector<myStudent> &students);
std::vector<myStudent> orderInfoStudent(int n, std::vector<myStudent> &students);

bool removeUcStudent(std::string ucCod, std::map<std::string, myStudent>::iterator &it);
void addClassStudent(std::string ucCode, std::string classCode, std::map<std::string, myStudent>::iterator &it, std::stack<alter> &stackAlter);

std::map<int, std::set<classInfo>> orderStudentClass(std::map<std::string, myStudent>::iterator &it, std::map<std::string, myUc> &classes);
bool valideNewClass(std::string ucCode, std::string classCode, std::map<std::string, myStudent>::iterator &it, std::map<std::string, myUc> &classes);

void showStudentClasses(std::map<std::string, myStudent>::iterator &it, std::map<std::string, myUc> &classes);
std::string weekDayString(int day);
bool verifyUcCode(std::string ucCode, std::map<std::string, myStudent>::iterator &it);

bool compareStudentsCodeAsc(const myStudent &student1,const myStudent &student2);
bool compareStudentsCodeDesc(const myStudent &student1, const myStudent &student2);
bool compareStudentNameAsc(const myStudent &student1, const myStudent &student2);
bool compareStudentNameDesc(const myStudent &student1, const myStudent &student2);

#endif
