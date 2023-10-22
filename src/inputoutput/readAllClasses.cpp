#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../classes/class.h"

void workingMessage();
void errorMessageFile();
void errorMessageLine(std::string);

std::vector<myClass> readAllClasses() { // FUNCTION FINISH
  std::vector<myClass> data;

  // std::ifstream classesdata("schedule/classes.csv");

  // // check if open
  // if (!classesdata.is_open()) {
  //   errorMessageFile();
  // }

  // std::string line;
  // bool header = true;

  // while (std::getline(classesdata, line)) {
  //   if (header) {
  //     header = false;
  //     continue;
  //   }

  //   std::stringstream ss(line);
  //   std::string token;
  //   std::vector<std::string> tokens;

  //   while (std::getline(ss, token, ',')) {
  //     tokens.push_back(token);
  //   }

  //   // Check if file has at least 7 parameters:
  //   // ClassCode,UcCode,Weekday,StartHour,Duration,Type,Date
  //   if (tokens.size() < 7) {
  //     errorMessageLine(line);
  //   }

  //   // Store information
  //   std::string classCode = tokens[0];
  //   std::string ucCode = tokens[1];

  //   // Parse Slot data
  //   std::string weekday = tokens[2];
  //   float startHour = std::stof(tokens[3]);
  //   float duration = std::stof(tokens[4]);
  //   std::string type = tokens[5];
  //   std::string date = tokens[6];

  //   // Create Slot object and add it to the vector
  //   Slot slot{weekday, startHour, duration, type};
  //   std::vector<Slot> slots = {slot};

  //   myClass myclass(classCode, ucCode, slots);
  //   data.push_back(myclass);
  // }

  // classesdata.close();
  return data;
}
