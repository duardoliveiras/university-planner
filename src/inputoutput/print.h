#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <string>
#include <vector>

#include "../classes/class.cpp"
#include "../classes/student.cpp"
#include "../classes/uc.cpp"

void printClass(const std::vector<myClass> &classes);
void printStudent(const std::vector<myStudent> &students);
void printUc(const std::vector<myUc> &vecUc);

#endif