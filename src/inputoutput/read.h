#ifndef READ_H
#define READ_H

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "../classes/student.h"
#include "../classes/uc.h"

void errorMessageFile();
void errorMessageLine(std::string);

std::map<std::string, myStudent>
readStudents(std::map<std::string, std::vector<classQtd>> &count);
std::map<std::string, myUc>
readUcs(std::map<std::string, std::vector<classQtd>> &count);

std::map<std::string, myUc> readSchedules();

#endif
