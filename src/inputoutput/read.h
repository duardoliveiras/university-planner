#ifndef READ_H
#define READ_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../classes/class.h"
#include "../classes/student.h"
#include "../classes/uc.h"

void workingMessage();
void errorMessageFile();
void errorMessageLine(std::string);

std::vector<myClass> readAllClasses();
std::vector<myStudent> readAllStudents();
std::vector<myUc> readAllUcs();

#endif
