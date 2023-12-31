#ifndef READ_H
#define READ_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "../classes/student.h"

void errorMessageFile();
void errorMessageLine(std::string);

std::map<std::string, myStudent>
readStudents(std::map<std::string, std::vector<classQtd>> &count);
std::map<std::string, std::vector<myUc>>
readUcs(std::map<std::string, std::vector<classQtd>> &count);

std::map<std::string, myUc> readSchedules();

#endif
