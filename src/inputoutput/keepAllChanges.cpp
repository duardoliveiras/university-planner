#include "keepAllChanges.h"

// Make a backup with the lastest archive modified
// add the date on the name of the backup
void makeBackup() {
  //   std::ifstream file("schedule/students_classes.csv", std::ios::binary);

  //   if (!file) {
  //     std::cerr << "Error opening file" << std::endl;
  //   }

  //   std::time_t date = std::time(0);
  //   std::tm *now = std::localtime(&date);

  //   std::string dateString =
  //       std::to_string(now->tm_year + 1900) + "-" +
  //       std::to_string(now->tm_mon + 1) + "-" + std::to_string(now->tm_mday)
  //       +
  //       "-" + std::to_string(now->tm_hour) + ":" +
  //       std::to_string(now->tm_min) +
  //       ":" + std::to_string(now->tm_sec);

  //   std::string backupName =
  //       "schedule/students_classes_backup" + dateString + ".csv";
  //   std::ofstream backup(backupName, std::ios::binary);

  //   if (!backup) {
  //     std::cerr << "Backup already exists" << std::endl;
  //     return;
  //   }

  //   backup << file.rdbuf();
  //   file.close();
  //   backup.close();
  workingMessage();
}

// Save all changes made in the tree of students
// in the file students_classes.csv
void keepAllChanges(std::map<std::string, myStudent> &students) {
  workingMessage();
  // makeBackup();

  // std::ofstream file("schedule/students_classes.csv");

  // if (!file.is_open()) {
  //   std::cerr << "Error opening file" << std::endl;
  // }

  // // Header
  // file << "StudentCode,StudentName,UcCode,ClassCode" << std::endl;

  // // Write the tree in the file
  // for (auto it = students.begin(); it != students.end(); it++) {
  //   // for (auto classe : it->second.getClasses()) {
  //   //   // std::cout<< it->second.getCode() << "," << it->second.getName()
  //   <<
  //   //   ","
  //   //   // << classe.getUcCode() << "," << classe.getClassCode() <<
  //   std::endl;
  //   //   file << it->second.getStudentCode() << "," <<
  //   //   it->second.getStudentName() << ","
  //   //        << classe.getUcCode() << "," << classe.getClassCode() <<
  //   //        std::endl;
  //   // }
  // }
}
