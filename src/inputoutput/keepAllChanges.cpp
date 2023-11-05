#include "keepAllChanges.h"
#include <ctime>

std::vector<std::string> backups;

/**
 * @brief Compare two strings in descending order.
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @return True if 'str1' is greater than 'str2', otherwise false.
 */
bool orderVector(const std::string &str1, const std::string &str2) {
  return str1 > str2;
}

/**
 * @brief Get the system date.
 * @return A string with the system date.
 */
std::string getSysdate() {

  std::time_t date = std::time(0);
  std::tm *now = std::localtime(&date);

  return std::to_string(now->tm_year + 1900) + "-" +
         std::to_string(now->tm_mon + 1) + "-" + std::to_string(now->tm_mday) +
         "-" + std::to_string(now->tm_hour) + ":" +
         std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec);
}

/**
 * @brief Creates a backup of the "students_classes.csv" file with the lastest
 * archive modified. The backup file is named with the current system date.
 */
void makeBackup() {
  std::ifstream file("schedule/students_classes.csv", std::ios::binary);

  if (!file) {
    std::cerr << "Error opening file" << std::endl;
  }

  std::string dateString = getSysdate();

  std::string backupName =
      "schedule/backup/students_classes-" + dateString + ".csv";
  std::ofstream backup(backupName, std::ios::binary);

  if (!backup) {
    std::cerr << "Error to create a backup file" << std::endl;
    return;
  }

  backup << file.rdbuf();
  file.close();
  backup.close();
}

/**
 * @brief Saves all changes made to the student tree in the
 * "students_classes.csv" file.
 * @param students Reference to the map containing student data.
 * @param stackAlter Reference to a stack containing alteration records.
 */
void keepAllChanges(std::map<std::string, myStudent> &students,
                    std::stack<alter> &stackAlter) {
  makeBackup();
  std::ofstream alter("schedule/alter/students_classes-" + getSysdate() +
                          ".csv",
                      std::ios::app);
  if (!alter.is_open()) {
    std::cerr << "Error opening file" << std::endl;
  }

  while (!stackAlter.empty()) {
    alter << "The student: " << stackAlter.top().studentCode << " - "
          << stackAlter.top().studentName << " " << stackAlter.top().type
          << " UC: " << stackAlter.top().ucCode
          << " Class: " << stackAlter.top().classCode << std::endl;
    stackAlter.pop();
  }

  std::ofstream file("schedule/students_classes.csv");

  if (!file.is_open()) {
    std::cerr << "Error opening file" << std::endl;
  }

  // Header
  file << "StudentCode,StudentName,UcCode,ClassCode" << std::endl;

  // Write the tree in the file
  for (auto it = students.begin(); it != students.end(); it++) {
    for (auto classe : it->second.getClasses()) {
      file << it->second.getStudentCode() << "," << it->second.getStudentName()
           << "," << classe.getUcCode() << "," << classe.getClassCode()
           << std::endl;
    }
  }
}

/**
 * @brief List all backup files.
 *
 * If no backup files exist, this function searches for and populates
 * the 'backups' vector with filenames from the "schedule/backup" directory.
 */
void listAllBackups() {
  if (backups.size() == 0) {
    std::string way = "schedule/backup";
    for (const auto &in : std::filesystem::directory_iterator(way)) {
      if (std::filesystem::is_regular_file(in)) {
        backups.push_back(in.path().filename().string());
      }
    }
    std::sort(backups.begin(), backups.end(), orderVector);
  }
}

/**
 * @brief Prints all backup file names stored in the public vector backups.
 */
bool printAllBackups() {
  if (backups.size() != 0) {
    std::cout << "Backups: " << std::endl;
    for (unsigned i = 0; i < backups.size(); i++) {
      std::cout << i << " - " << backups.at(i) << std::endl;
    }
    return true;
  } else {
    std::cout << "No backups" << std::endl;
    return false;
  }
}

/**
 * @brief Print the changes from backup files.
 *
 * This function prints the content of backup files located in the
 * "schedule/alter" directory, up to the specified 'cdBkp' index, to the
 * standard output.
 *
 * @param cdBkp The index of the backup files to print.
 */
void printChanges(int cdBkp) {
  unsigned size = cdBkp;
  for (unsigned i = 0; i <= size; i++) {
    std::ifstream file("schedule/alter/" + backups[i], std::ios::binary);

    if (!file) {
      std::cerr << "Error opening file" << std::endl;
    }

    std::string line;

    while (std::getline(file, line)) {
      std::cout << "   " << line << std::endl;
    }
    file.close();
  }

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

/**
 * @brief Backup a specific file and remove related changes.
 *
 * This function backs up a specified file from "schedule/backup" to
 * "schedule/students_classes.csv" and removes related change files in the
 * "schedule/alter" and "schedule/backup" directories.
 *
 * @param cdBkp The index of the backup file to restore.
 */
void backupFile(int cdBkp) {

  std::string path = "schedule/backup/" + backups[cdBkp];

  std::ifstream backup(path, std::ios::binary);

  if (!backup) {
    std::cerr << "Error opening file" << std::endl;
  }

  std::ofstream file("schedule/students_classes.csv", std::ios::binary);

  if (!file) {
    std::cerr << "Error opening file" << std::endl;
  }

  file << backup.rdbuf();
  file.close();
  backup.close();

  unsigned size = cdBkp;
  for (unsigned i = 0; i <= size; i++) {
    if (std::filesystem::exists("schedule/alter/" + backups[cdBkp])) {
      try {
        std::filesystem::remove("schedule/alter/" + backups[i]);
        std::filesystem::remove("schedule/backup/" + backups[i]);
      } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "Error to remove the file" << e.what() << std::endl;
      }
    } else {
      std::cout << "The file of changes not exist" << std::endl;
    }
  }
}
