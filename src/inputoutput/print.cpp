#include "print.h"

int equilibre = 3;
int max_students = 6;

void printStudent(const std::map<std::string, myStudent> &students) {
  std::cout << "Student Code | Student Name | Uc Code | Class Code"
            << std::endl;

  for (const auto &studentPair : students) {
    const myStudent &student = studentPair.second;
    std::cout << student.getStudentCode() << " | " << student.getStudentName();

    const auto &ucCodes = student.getUcCode();
    for (const auto &ucCode : ucCodes) {
      std::cout << " | " << ucCode;
    }

    const auto &classCodes = student.getClassCode();
    for (const auto &classCode : classCodes) {
      std::cout << " | " << classCode;
    }
    std::cout << std::endl;
  }
}

void printStudents(const std::vector<myStudent> &students) {
  std::cout << "Student Code | Student Name | Uc Code | Class Code"
            << std::endl;

  for (const auto &student : students) {
    std::cout << student.getStudentCode() << " | " << student.getStudentName();

    const auto &ucCodes = student.getUcCode();
    for (const auto &ucCode : ucCodes) {
      std::cout << " | " << ucCode;
    }

    const auto &classCodes = student.getClassCode();
    for (const auto &classCode : classCodes) {
      std::cout << " | " << classCode;
    }
    std::cout << std::endl;
  }
}

void printUc(const std::map<std::string, myUc> &ucs) {
  std::cout << "UcCode | ClassCode | Type | Day | DayInt | StartTime | Duration"
            << std::endl;

  for (const auto &ucPair : ucs) {
    const myUc &uc = ucPair.second;
    std::string ucCode = uc.getUcCode();
    const auto &classInfoVec = uc.getClassInfoVec();

    for (const auto &classInfo : classInfoVec) {
      std::string classCode = uc.getClassCode();
      std::string type = classInfo.type;
      std::string day = classInfo.day;
      int dayInt = classInfo.dayInt;
      double startTime = classInfo.startTime;
      double duration = classInfo.duration;

      std::cout << ucCode << " | " << classCode << " | " << type << " | " << day
                << " | " << dayInt << " | " << startTime << " | " << duration
                << std::endl;
    }
  }
}

void printStudentClasses(std::map<std::string, myStudent>::iterator &it) {
  system("clear");
  std::cout << "\nCode: " << it->first << " - ";
  std::cout << "Name: " << it->second.getStudentName() << std::endl;
  std::cout << "Classes: " << std::endl;
  for (const auto &classe : it->second.getClasses()) {
    std::cout << "  " << classe.getUcCode() << " - " << classe.getClassCode()
              << std::endl;
  }
}

void printUcs(const std::vector<myUc> &ucs) {
  std::cout << "UcCode | ClassCode | Type | Day | DayInt | StartTime | Duration"
            << std::endl;

  for (const auto &uc : ucs) {
    std::string ucCode = uc.getUcCode();
    const auto &classInfoVec = uc.getClassInfoVec();

    for (const auto &classInfo : classInfoVec) {
      std::string classCode = uc.getClassCode();
      std::string type = classInfo.type;
      std::string day = classInfo.day;
      int dayInt = classInfo.dayInt;
      double startTime = classInfo.startTime;
      double duration = classInfo.duration;

      std::cout << ucCode << " | " << classCode << " | " << type << " | " << day
                << " | " << dayInt << " | " << startTime << " | " << duration
                << std::endl;
    }
  }
}

std::list<std::string> valideFreeClass(
    std::map<std::string, std::vector<classQtd>>::iterator it_count) {
  int min = INT_MAX;
  std::list<std::string> free_classes;

  // first verify the class with the minimum number of students
  for (auto &classe : it_count->second) {
    if (classe.qtd < min) {
      min = classe.qtd;
    }
  }
  // then verify if the class is able to accept new students and add to the list
  for (auto &classe : it_count->second) {
    if (!(classe.qtd + 1 - min > equilibre) && classe.qtd + 1 <= max_students) {
      free_classes.push_back(classe.classCode);
    }
  }

  // return list
  return free_classes;
}

void printFreeClasses(std::string ucCode,
                      std::map<std::string, std::vector<classQtd>> &count) {

  auto it_count = count.find(ucCode);

  if (it_count != count.end()) {
    std::list<std::string> free_classes = valideFreeClass(it_count);
    std::cout << "   Classes: " << std::endl;

    if (!free_classes.empty()) {
      for (auto it_list = free_classes.begin(); it_list != free_classes.end();
           it_list++) {
        std::cout << "      " << *it_list << std::endl;
      }
    } else {
      std::cout << "      No classes available" << std::endl;
    }
  } else {
    std::cout << " Uc not found" << std::endl;
  }
}

void printStudentSchedules(std::map<std::string, myStudent>::iterator &it,
                        std::map<std::string, myUc> &classes) {
  auto orderClasses = orderStudentClass(it, classes);
  std::cout << "\nSchedules: " << std::endl;
  for (const auto &pair : orderClasses) {
    std::string day = weekDayString(pair.first);
    std::cout << "Day: " << day << std::endl;
    for (const auto &info : pair.second) {
      std::cout << info.code << " - ";
      std::cout << info.startTime << " to ";
      std::cout << info.startTime + info.duration << " - ";
      std::cout << info.type << std::endl;
    }
    std::cout << std::endl;
  }
}