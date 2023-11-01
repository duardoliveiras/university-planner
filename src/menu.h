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

void menuStudents(std::string str = "", int type = 0, int filter = 0,
                  int order = 0);
void menuUcs(std::string str = "", int type = 0, int filter = 0, int order = 0);

void menuStudentCode(int flag);

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

int selectOrder();
int selectType();
int selectFilter();
std::string selectCode();
std::string selectValue();

std::map<int, std::set<classInfo>>
orderStudentClass(std::map<std::string, myStudent>::iterator &it,
                  std::map<std::string, myUc> &classes);
bool valideNewClass(std::string ucCode, std::string classCode,
                    std::map<std::string, myStudent>::iterator &it,
                    std::map<std::string, myUc> &classes);
std::list<std::string> valideFreeClass(
    std::map<std::string, std::vector<classQtd>>::iterator it_count);
void showStudentClasses(std::map<std::string, myStudent>::iterator &it,
                        std::map<std::string, myUc> &classes);

bool verifyUcCode(std::string ucCode,
                  std::map<std::string, myStudent>::iterator &it);

void saveOrReturn();
void save();

#endif
