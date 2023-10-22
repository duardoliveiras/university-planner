#ifndef MENU_H
#define MENU_H

#include <iostream>

void errorMessage();
void errorCheck(int n);
void workingMessage();

void dbStudents(int submenu);
void dbUcs(int submenu);
void dbClasses(int submenu);

void menuSeeDatabase();
void menuRequests();

void menuStudents(std::string str = "", int type = 0, int filter = 0,
                  int order = 0);
void menuClasses(int type, int order = 0);
void menuUcs(int type, int order = 0);
void requests(int flag, int code);
int selectOrder();
int selectType();
std::string selectCode();
int menuCode();

void requests(int n);

std::string menuSelectInfo(int n);

void menu();

#endif
