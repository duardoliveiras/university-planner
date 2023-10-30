#include "keepAllChanges.h"
#include <ctime>

void makeBackup() {
    std::ifstream file("schedule/students_classes.csv", std::ios::binary);

    if(!file){
      std::cerr<< "Error opening file" << std::endl;
    }

    std::time_t date = std::time(0);
    std::tm* now = std::localtime(&date);

    std::string dateString = std::to_string(now->tm_year + 1900) + "-" + std::to_string(now->tm_mon + 1) + "-" + std::to_string(now->tm_mday)
    + "-" + std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec);

    std::string backupName = "schedule/students_classes_backup" + dateString + ".csv" ;
    std::ofstream backup(backupName, std::ios::binary);

    if(!backup){
      std::cerr<< "Backup already exists" << std::endl;
      return;
    }

    backup << file.rdbuf();
    file.close();
    backup.close();


}

void keepAllChanges(std::map<std::string, studentComp>::iterator& it) {

    makeBackup();

    

}


