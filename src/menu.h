#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <list>
#include <map>

#include "classes/student.h"
#include "classes/uc.h"
#include "functions/dbStudents.h"
#include "functions/dbUcs.h"
#include "inputoutput/keepAllChanges.h"
#include "inputoutput/print.h"
#include "inputoutput/read.h"

void errorMessage();
void errorCheck(int n);

void menuStudents(std::string str, int type, int filter, int order);
void menuStudentCode(int flag);

void menu();
void menuSeeDatabase();
void menuRequests();
void menuRemove(std::map<std::string, myStudent>::iterator &it);
void menuAdd(std::map<std::string, myStudent>::iterator &it);
void menuSwitch(std::map<std::string, myStudent>::iterator &it);
void menuStudents(std::string str, int type, int filter, int order);
void menuUcs(std::string str, int type, int filter, int order);

void saveOrReturn();
void save();

int selectOrder();
int selectType();
std::string selectCode();
int selectFilter();
std::string selectValue();

#endif
