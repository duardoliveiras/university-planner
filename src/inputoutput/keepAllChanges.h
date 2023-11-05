#ifndef KEEPALLCHANGES_H
#define KEEPALLCHANGES_H

#include <algorithm>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "../classes/student.h"

void makeBackup();
bool orderVector(const std::string &str1, const std::string &str2);
void keepAllChanges(std::map<std::string, myStudent> &students,
                    std::stack<alter> &stackAlter);
std::string getSysdate();
void listAllBackups();
void listChanges(int cdBkp);
void printAllBackups();
void backupFile(int cdBkp);

void makeBackup();
void keepAllChanges(std::map<std::string, myStudent> &students);

#endif