#ifndef KEEPALLCHANGES_H
#define KEEPALLCHANGES_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../classes/student.h"

void makeBackup();
void keepAllChanges(std::map<std::string, myStudent> &students);

void workingMessage();

#endif