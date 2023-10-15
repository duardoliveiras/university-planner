#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../classes/student.h"

void workingMessage();
void errorMessageFile();
void errorMessageLine(std::string);

std::vector<myStudent> readAllStudents() {
  std::vector<myStudent> data;

  std::ifstream studentsdata("schedule/students_classes.csv");

  // check if open
  if (!studentsdata.is_open()) {
    errorMessageFile();
  }

  std::string line;
  bool isFirstLine = true;

  while (std::getline(studentsdata, line)) {
    if (isFirstLine) {
      isFirstLine = false;
      continue; // Skip the first line (header)
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

    myStudent student(studentCode, studentName, ucCode, classCode);
    data.push_back(student);
  }

  studentsdata.close();
  return data;
}
