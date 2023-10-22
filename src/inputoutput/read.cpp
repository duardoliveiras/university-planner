#include "read.h"

std::vector<myClass> readAllClasses() {
  std::vector<myClass> data;

  std::ifstream classesdata("schedule/classes.csv");

  // check if open
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
    if (tokens.size() < 7) {
      errorMessageLine(line);
    }

    // Store information
    std::string classCode = tokens[0];
    std::string ucCode = tokens[1];

    // Parse Slot data
    std::string weekday = tokens[2];
    float startHour = std::stof(tokens[3]);
    float duration = std::stof(tokens[4]);
    std::string type = tokens[5];
    std::string date = tokens[6];

    // Create Slot object and add it to the vector
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

  // check if open
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

  workingMessage();

  // READ FILE AND STORE INFO IN DATA

  return data;
}
