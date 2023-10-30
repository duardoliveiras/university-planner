#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <map>
#include <list>
#include "classes/studentComp.h"
#include "classes/ClassComp.h"
#include "inputoutput/read.h"

void errorMessage();
void errorCheck(int n);
void workingMessage();

void menu();

void menuSeeDatabase();
void menuRequests();

void menuRemove(std::map<std::string, studentComp>::iterator& it);
void menuAdd(std::map<std::string, studentComp>::iterator& it);
void menuStudentCode(int flag);
void menuSwitch(std::map<std::string, studentComp>::iterator& it);

void menuStudents(std::string str = "", int type = 0, int filter = 0,
                  int order = 0);
void menuClasses(std::string str = "", int type = 0, int filter = 0,
                 int order = 0);
void menuUcs(std::string str = "", int type = 0, int filter = 0, int order = 0);

int selectOrder();
int selectType();
int selectFilter();
std::string selectCode();
std::string selectValue();

bool removeUcStudent(std::string ucCod, std::map<std::string, studentComp>::iterator& it);
void addClassStudent(std::string ucCode, std::string classCode, std::map<std::string, studentComp>::iterator& it);

std::map<int, std::set<classInfo>> orderStudentClass(std::map<std::string, studentComp>::iterator& it, std::map<std::string, ClassComp>& classes);
bool valideNewClass(std::string ucCode, std::string classCode, std::map<std::string, studentComp>::iterator& it, std::map<std::string, ClassComp>& classes);
std::list<std::string> valideFreeClass(std::map<std::string, std::vector<classQtd>>::iterator it_count);

void printStudentClasses(std::map<std::string, studentComp>::iterator& it);
void printFreeClasses(std::string ucCode, std::map<std::string, std::vector<classQtd>>& count);

#endif
