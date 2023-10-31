#ifndef KEEPALLCHANGES_H
#define KEEPALLCHANGES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>
#include <map>
#include <filesystem>   
#include "../classes/studentComp.h"

void makeBackup();
void keepAllChanges(std::map<std::string, studentComp> &students, std::stack<alter>& stackAlter);
std::string getSysdate();   
void listAllBackups();
void listChanges(int cdBkp);
void printAllBackups();

#endif