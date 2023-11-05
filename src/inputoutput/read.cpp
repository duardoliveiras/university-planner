#include "read.h"


/**
 * @brief Read and process student and class information from a CSV file.
 *
 * This function reads and processes student and class information from a CSV file,
 * populating a map of students and updating class quantity information based on the data.
 *
 * @param count A map of class quantity information.
 * @return A map of students with associated classes.
 */
std::map<std::string, myStudent>
readStudents(std::map<std::string, std::vector<classQtd>> &count) {
  std::string line;
  std::map<std::string, myStudent> students;

  std::ifstream file("schedule/students_classes.csv");
  if (!file.is_open()) {
    errorMessageFile();
  }

  bool header = true;
  while (std::getline(file, line)) {
    if (header) {
      header = false;
      continue;
    }
    std::istringstream ss(line);

    std::string studentCode, studentName, ucCode, classCode;

    std::getline(ss, studentCode, ',');
    std::getline(ss, studentName, ',');
    std::getline(ss, ucCode, ',');
    std::getline(ss, classCode);

    classCode.erase(
        std::find_if(classCode.rbegin(), classCode.rend(),
                     [](unsigned char ch) { return !std::isspace(ch); })
            .base(),
        classCode.end());

    auto it = students.find(studentCode);
    if (it != students.end()) {
      it->second.addClass(myUc(ucCode, classCode));
    } else {
      myStudent newStudent(studentCode, studentName);
      newStudent.addClass(myUc(ucCode, classCode));
      students[studentCode] = newStudent;
    }

    // verify if the uc exists in the count tree
    auto it_count = count.find(ucCode);

    // if not exists, add the class with one student in the count tree
    if (it_count == count.end()) {
      std::vector<classQtd> classVec;
      classVec.push_back({classCode, 1});
      count.emplace(ucCode, classVec);
    } else {
      // if uc exist, then verify if the class exists in the vector
      bool exist = false;
      for (auto &class_it : it_count->second) {
        // if exists, add +1 in the qtd
        if (class_it.classCode == classCode) {
          class_it.qtd++;
          exist = true;
          break;
        }
      }
      // if not exists, add the class with one student in the vector
      if (!exist) {
        it_count->second.push_back({classCode, 1});
      }
    }
  }
  file.close();

  return students;
}

/**
 * @brief Read and process UC and class information from a CSV file.
 *
 * This function reads and processes UC and class information from a CSV file,
 * populating a map of UCs and their associated classes, as well as updating class quantity information
 * based on the data.
 *
 * @param count A map of class quantity information.
 * @return A map of UCs and their associated classes.
 */
std::map<std::string, std::vector<myUc>>
readUcs(std::map<std::string, std::vector<classQtd>> &count) {
  std::string line;
  std::map<std::string, std::vector<myUc>> ucClasses;

  std::ifstream file("schedule/classes_per_uc.csv");
  if (!file.is_open()) {
    errorMessageFile();
  }

  bool header = true;
  while (std::getline(file, line)) {
    // testing
    // std::cout << "line" << std::endl;

    if (header) {
      header = false;
      continue;
    }
    std::istringstream ss(line);
    std::string ucCode, classCode;

    std::getline(ss, ucCode, ',');
    std::getline(ss, classCode, ',');

    auto it = ucClasses.find(ucCode);

    classCode.erase(
        std::find_if(classCode.rbegin(), classCode.rend(),
                     [](unsigned char ch) { return !std::isspace(ch); })
            .base(),
        classCode.end());

    if (it != ucClasses.end()) {
      // exist
      myUc newUc;
      newUc.setUcCode(ucCode);
      newUc.setClassCode(classCode);
      it->second.push_back(newUc);
    } else {
      // doesnt exist
      std::vector<myUc> ucVector;
      myUc newUc;
      newUc.setUcCode(ucCode);
      newUc.setClassCode(classCode);
      ucVector.push_back(newUc);
      ucClasses[ucCode] = ucVector;
    }

    bool exist = false;

    // try to find the uc in the count tree
    auto it_count = count.find(ucCode);

    // if found, verify if the class exists in the vector
    if (it_count != count.end()) {
      for (auto &class_it : it_count->second) {
        if (class_it.classCode == classCode) {
          exist = true;
        }
      }
      // if exist uc in the count tree, but not exist the class, add the class
      // with 0 students
      if (!exist) {
        it_count->second.push_back({classCode, 0});
      }
      // if not found, add the uc and class with 0 students
    } else {
      std::vector<classQtd> classVec;
      classVec.push_back({classCode, 0});
      count.emplace(ucCode, classVec);
    }
  }
  file.close();

  return ucClasses;
}

/**
 * @brief Read and process class schedule information from a CSV file.
 *
 * This function reads and processes class schedule information from a CSV file,
 * populating a map of classes and their associated details, including UC code, day, type, start time, and duration.
 *
 * @return A map of classes with their associated information.
 */
std::map<std::string, myUc> readSchedules() {
  std::string line;
  std::map<std::string, myUc> classes;
  std::map<std::string, int> dayToInt = {
      {"Sunday", 1},   {"Monday", 2}, {"Tuesday", 3}, {"Wednesday", 4},
      {"Thursday", 5}, {"Friday", 6}, {"Saturday", 7}};

  std::ifstream file("schedule/classes.csv");
  if (!file.is_open()) {
    errorMessageFile();
  }

  bool header = true;
  while (std::getline(file, line)) {
    if (header) {
      header = false;
      continue;
    }
    std::istringstream ss(line);
    std::string classCode, ucCode, day, type;
    double startTime, duration;
    int dayInt = 0;

    std::getline(ss, classCode, ',');
    std::getline(ss, ucCode, ',');
    std::getline(ss, day, ',');
    ss >> startTime;
    ss.ignore();
    ss >> duration;
    ss.ignore();
    std::getline(ss, type);

    type.erase(std::find_if(type.rbegin(), type.rend(),
                            [](unsigned char ch) { return !std::isspace(ch); })
                   .base(),
               type.end());

    auto it1 = dayToInt.find(day);
    if (it1 != dayToInt.end()) {
      dayInt = it1->second;
    } else {
      std::cout << "Invalid day: " << day << std::endl;
    }

    // Check if the class code already exists in the map
    auto it2 = classes.find(ucCode + classCode);
    if (it2 != classes.end()) {
      it2->second.addClassInfo(type, day, dayInt, startTime, duration);
    } else {
      myUc newUcClass;
      newUcClass.setUcCode(ucCode);
      newUcClass.addClass(classCode);
      newUcClass.addClassInfo(type, day, dayInt, startTime, duration);
      classes[ucCode + classCode] = newUcClass;
    }
  }
  return classes;
}
