#ifndef KEEPALLCHANGES_H
#define KEEPALLCHANGES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include "../classes/studentComp.h"

void makeBackup();
void keepAllChanges(std::map<std::string, studentComp>::iterator& it);


#endif