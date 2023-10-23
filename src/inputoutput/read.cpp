#include "read.h"
#include <sstream>

std::vector<myClass> readAllClasses() {
  std::vector<myClass> data;

  std::ifstream classesdata("schedule/classes.csv");

  // Check if open
  if (!classesdata.is_open()) {
    errorMessageFile();
  }

  std::string line;
  bool header = true;

  while (std::getline(classesdata, line)) {
    if (header) {
      header = false;
      continue;
    }

    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) {
      tokens.push_back(token);
    }

    // Check if file has at least 7 parameters:
    // ClassCode,UcCode,Weekday,StartHour,Duration,Type,Date
    if (tokens.size() < 6) {
      errorMessageLine(line);
    }

    // Store information
    std::string classCode = tokens[0];
    std::string ucCode = tokens[1];

    std::string weekday = tokens[2];
    float startHour = std::stof(tokens[3]);
    float duration = std::stof(tokens[4]);
    std::string type = tokens[5];

    Slot slot{weekday, startHour, duration, type};

    std::vector<Slot> slots = {slot};
    myClass myclass(classCode, ucCode, slots);
    data.push_back(myclass);
  }

  classesdata.close();
  return data;
}

std::vector<myStudent> readAllStudents() {
  std::vector<myStudent> data;

  std::ifstream studentsdata("schedule/students_classes.csv");

  // Check if open
  if (!studentsdata.is_open()) {
    errorMessageFile();
  }

  std::string line;
  bool header = true;

  while (std::getline(studentsdata, line)) {

    if (header) {
      header = false;
      continue;
    }

    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) {
      tokens.push_back(token);
    }

    // Check if file have 4 parameters:
    // StudentCode,StudentName,UcCode,ClassCode
    if (tokens.size() < 4) {
      errorMessageLine(line);
    }

    // Store information
    int studentCode = std::stoi(tokens[0]);
    std::string studentName = tokens[1];
    std::vector<std::string> ucCode = {tokens[2]};
    std::vector<std::string> classCode = {tokens[3]};

    myStudent mystudent(studentCode, studentName, ucCode, classCode);
    data.push_back(mystudent);
  }

  studentsdata.close();
  return data;
}

std::vector<myUc> readAllUcs() {
  std::vector<myUc> data;

  std::ifstream ucdata("schedule/classes_per_uc.csv");

  // Check if open
  if (!ucdata.is_open()) {
    errorMessageFile();
  }

  std::string line;
  bool header = true;

  while (std::getline(ucdata, line)) {
    if (header) {
      header = false;
      continue;
    }

    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) {
      tokens.push_back(token);
    }

    // Check if file have 2 parameters:
    // UcCode,ClassCode
    if (tokens.size() < 2) {
      errorMessageLine(line);
    }

    // Store information
    std::string ucCode = tokens[0];
    std::vector<std::string> classCode = {tokens[1]};

    myUc uc(ucCode, classCode);
    data.push_back(uc);
  }
  ucdata.close();
  return data;
}


