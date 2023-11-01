#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../classes/student.h"
#include "../classes/uc.h"

void workingMessage();
void errorMessage();

void printStudents(const std::map<std::string, myStudent> &students);
void printUcs(const std::map<std::string, myUc> &ucs);
void printStudentClasses(std::map<std::string, myStudent>::iterator &it);
void printFreeClasses(std::string ucCode,
                      std::map<std::string, std::vector<classQtd>> &count);

#endif