#ifndef PRINT_H
#define PRINT_H

#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

#include "../classes/student.h"
#include "../functions/dbStudents.h"

void workingMessage();
void errorMessage();

void printStudents(const std::vector<myStudent> &students);
void printStudent(const std::map<std::string, myStudent> &students);

void printUcClasses(const std::vector<myUc> &ucVector, std::map<std::string, myUc> &classes);
void printUcs(const std::vector<myUc> &ucs);

void printStudentSchedules(std::map<std::string, myStudent>::iterator &it,
                           std::map<std::string, myUc> &classes);
void printStudentClasses(std::map<std::string, myStudent>::iterator &it);
void printFreeClasses(std::string ucCode,
                      std::map<std::string, std::vector<classQtd>> &count);
std::list<std::string> valideFreeClass(
    std::map<std::string, std::vector<classQtd>>::iterator it_count);

#endif
