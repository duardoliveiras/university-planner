#include "print.h"

void printStudent(const std::vector<myStudent> &students) {
  std::cout << "Student Code | Student Name | Uc Code | Class Code"
            << std::endl;

  for (const auto &mystudent : students) {
    std::cout << mystudent.getStudentCode() << " | "
              << mystudent.getStudentName();

    // const auto &ucCodes = mystudent.getUcCode();
    // for (const auto &ucCode : ucCodes) {
    //   std::cout << ucCode << " | ";
    // }

    // const auto &classCodes = mystudent.getClassCode();
    // for (const auto &classCode : classCodes) {
    //   std::cout << classCode;
    // }
    std::cout << std::endl;
  }
}

void printUc(const std::vector<myUc> &ucs) {
  std::cout << "UcCode | ClassCode | Type | Day | DayInt | StartTime | Duration"
            << std::endl;

  for (const auto &myuc : ucs) {
    std::string ucCode = myuc.getUcCode();
    const auto &classCodes = myuc.getClassCode();
    const auto &classInfoVec = myuc.getClassInfoVec();

    for (size_t i = 0; i < classCodes.size(); ++i) {
      std::string classCode = classCodes[i];
      std::string type = classInfoVec[i].type;
      std::string day = classInfoVec[i].day;
      int dayInt = classInfoVec[i].dayInt;
      double startTime = classInfoVec[i].startTime;
      double duration = classInfoVec[i].duration;

      std::cout << ucCode << " | " << classCode << " | " << type << " | " << day
                << " | " << dayInt << " | " << startTime << " | " << duration
                << std::endl;
    }
  }
}

// // Receives the student pointer and print your classes
void printStudentClasses(std::map<std::string, myStudent>::iterator &it) {
  //   system("clear");
  //   organizerUcStudent(it);
  //   std::cout << "\nCode: " << it->first << " - ";
  //   std::cout << "Name: " << it->second.getStudentName() << std::endl;
  //   std::cout << "Classes: " << std::endl;
  //   // for (const auto &classe : it->second.getStudentClasses()) {
  //   //   std::cout << "  " << classe.getUcCode() << " - " <<
  //   classe.getClassCode()
  //   //             << std::endl;
  //   // }
  workingMessage();
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