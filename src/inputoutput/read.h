#ifndef READ_H
#define READ_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include "../classes/class.h"
#include "../classes/student.h"
#include "../classes/uc.h"

#include "../classes/studentComp.h"
#include "../classes/ClassComp.h"

void errorMessageFile();
void errorMessageLine(std::string);

std::vector<myClass> readAllClasses();
std::vector<myStudent> readAllStudents();
std::vector<myUc> readAllUcs();

std::map<std::string, ClassComp> read_classes();
std::map<std::string, studentComp> read_students();

#endif
