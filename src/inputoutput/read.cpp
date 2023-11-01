#include "read.h"

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
    std::getline(ss, classCode, ',');

    auto it = students.find(studentCode);
    if (it != students.end()) {
      std::vector<std::string> classes;
      classes.push_back(classCode);
      it->second.addClass(myUc(ucCode, classes));
    } else {
      myStudent newStudent(studentCode, studentName);
      std::vector<std::string> classes;
      classes.push_back(classCode);
      newStudent.addClass(myUc(ucCode, classes));
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

std::map<std::string, myUc>
readUcs(std::map<std::string, std::vector<classQtd>> &count) {
  std::string line;
  std::map<std::string, myUc> ucClasses;
  bool header = true;

  std::ifstream file("schedule/classes_per_uc.csv");
  if (!file.is_open()) {
    errorMessageFile();
  }

  while (std::getline(file, line)) {
    if (header) {
      header = false;
      continue;
    }
    std::istringstream ss(line);
    std::string ucCode, classCode;

    std::getline(ss, ucCode, ',');
    std::getline(ss, classCode, ',');

    auto it = ucClasses.find(ucCode);

    // classCode.erase(
    //     std::find_if(classCode.rbegin(), classCode.rend(),
    //                  [](unsigned char ch) { return !std::isspace(ch); })
    //         .base(),
    //     classCode.end());

    if (it != ucClasses.end()) {
      it->second.addClass(classCode);
    } else {
      myUc newUcClass;
      newUcClass.setUcCode(ucCode);
      newUcClass.addClass(classCode);
      ucClasses[ucCode] = newUcClass;
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
  //   for (const auto &myUc : ucs) {
  //   std::cout << myUc.second.getUcCode() << std::endl;
  //   std::cout << " --- Classes: " << std::endl;

  //   for (const auto &classCode : myUc.second.getClassCode()) {
  //     std::string a = classCode;
  //     std::cout << a << std::endl;
  //   }
  // }

  return ucClasses;
}

std::map<std::string, myUc> readSchedules() {
  std::string line;
  std::map<std::string, myUc> classes;
  std::map<std::string, int> dayToInt = {
      {"Monday", 1}, {"Tuesday", 2},  {"Wednesday", 3}, {"Thursday", 4},
      {"Friday", 5}, {"Saturday", 6}, {"Sunday", 7}};

  std::ifstream file("schedule/classes.csv");
  if (!file.is_open()) {
    errorMessageFile();
  }

  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string classCode, ucCode, day, type;
    double startTime, duration;
    int dayInt = 0;

    std::getline(ss, classCode, ',');
    std::getline(ss, ucCode, ',');
    std::getline(ss, day, ',');
    ss >> startTime >> duration;
    std::getline(ss, type, ',');

    auto it1 = dayToInt.find(day);
    if (it1 != dayToInt.end()) {
      dayInt = it1->second;
    } else {
      std::cout << "Invalid day: " << day << std::endl;
    }

    // Check if the class code already exists in the map
    auto it2 = classes.find(classCode);
    if (it2 != classes.end()) {
      it2->second.addClassInfo(type, day, dayInt, startTime, duration);
    } else {
      myUc newUcClass;
      newUcClass.addClass(classCode);
      newUcClass.addClassInfo(type, day, dayInt, startTime, duration);
      classes[classCode] = newUcClass;
    }
  }
  return classes;
}
