#ifndef MENU_H
#define MENU_H

#include <iostream>

void errorMessage();
void errorCheck(int n);
void workingMessage();

void menu();

void menuSeeDatabase();
void menuRequests();

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

#endif
