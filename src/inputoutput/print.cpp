#include "print.h"

void printStudents(const std::map<std::string, myStudent> &students) {
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
void printUcs(const std::map<std::string, myUc> &ucs) {
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

// Receives the student pointer and print your classes
void printStudentClasses(std::map<std::string, myStudent>::iterator &it) {
  system("clear");
  // organizerUcStudent(it); // addd later
  std::cout << "\nCode: " << it->first << " - ";
  std::cout << "Name: " << it->second.getStudentName() << std::endl;
  std::cout << "Classes: " << std::endl;
  for (const auto &classe : it->second.getClasses()) {
    std::cout << "  " << classe.getUcCode() << " - " << classe.getClassCode()
              << std::endl;
  }
}
// // Receives the classCount by reference and verify if the new uc is already
// in
// // the tree then print  the classes that are able to accept new students
void printFreeClasses(std::string ucCode,
                      std::map<std::string, std::vector<classQtd>> &count) {
  workingMessage();
  //   auto it_count = count.find(ucCode);

  //   // searches for Code in the classCont tree and returns a list of all
  //   classes
  //   // that are able to accept new students
  //   if (it_count != count.end()) {
  //     std::list<std::string> free_classes = valideFreeClass(it_count);
  //     std::cout << "   Classes: " << std::endl;

  //     if (!free_classes.empty()) {
  //       for (auto it_list = free_classes.begin(); it_list !=
  //       free_classes.end();
  //            it_list++) {
  //         std::cout << "      " << *it_list << std::endl;
  //       }
  //     } else {
  //       std::cout << "      No classes available" << std::endl;
  //     }
  //   } else {
  //     std::cout << " Uc not found" << std::endl;
  //   }
}