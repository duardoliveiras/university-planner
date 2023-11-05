#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <list>
#include <map>
#include <stack>

#include "classes/student.h"
#include "classes/uc.h"
#include "functions/dbStudents.h"
#include "functions/dbUcs.h"
#include "inputoutput/keepAllChanges.h"
#include "inputoutput/print.h"
#include "inputoutput/read.h"

void errorMessage();
void errorCheck(int n);

void menuStudents(std::string str = "", int type = 0, int filter = 0,
                  int order = 0);
void menuUcs(std::string str = "", int type = 0, int filter = 0, int order = 0);

void menuStudentCode(int flag);
void menuTryAgain(int menuType, std::map<std::string, myStudent>::iterator &it);

void menu();
void menuSeeDatabase();
void menuRequests();
void menuRemove(std::map<std::string, myStudent>::iterator &it);
void menuAdd(std::map<std::string, myStudent>::iterator &it);
void menuSwitch(std::map<std::string, myStudent>::iterator &it);

void menuBackup();
void menuChanges();
void restoreBackup();
int selectBackupCode();

int selectOrderStudents();
int selectOrderUcs();
int selectType();
int selectFilter();
std::string selectCode();
std::string selectValue();

void saveOrReturn();
void save();

#endif
