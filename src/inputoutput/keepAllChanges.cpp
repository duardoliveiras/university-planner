#include "keepAllChanges.h"
#include <ctime>


std::string getSysdate(){

  std::time_t date = std::time(0);
  std::tm *now = std::localtime(&date);

  return std::to_string(now->tm_year + 1900) + "-" + std::to_string(now->tm_mon + 1) + "-" + std::to_string(now->tm_mday) + "-" + std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec);

}

// Make a backup with the lastest archive modified
// add the date on the name of the backup
void makeBackup()
{
  std::ifstream file("schedule/students_classes.csv", std::ios::binary);

  if (!file)
  {
    std::cerr << "Error opening file" << std::endl;
  }

  std::string dateString = getSysdate();

  std::string backupName = "schedule/backup/students_classes-" + dateString + ".csv";
  std::ofstream backup(backupName, std::ios::binary);

  if (!backup)
  {
    std::cerr << "Backup already exists" << std::endl;
    return;
  }

  backup << file.rdbuf();
  file.close();
  backup.close();
}

// Save all changes made in the tree of students
// in the file students_classes.csv
void keepAllChanges(std::map<std::string, studentComp> &students, std::stack<alter>& stackAlter)
{

  makeBackup();

  std::ofstream alter("schedule/alter.txt", std::ios::app);

  if (!alter.is_open())
  {
    std::cerr << "Error opening file" << std::endl;
  }
  

  while (!stackAlter.empty())
  {
    alter << stackAlter.top().studentCode << "," << stackAlter.top().studentName << "," << stackAlter.top().type << "," << stackAlter.top().ucCode << "," << stackAlter.top().classCode << getSysdate() << std::endl;
    stackAlter.pop();
  }

  std::ofstream file("schedule/students_classes.csv");

  if (!file.is_open())
  {
    std::cerr << "Error opening file" << std::endl;
  }

  // Header
  file << "StudentCode,StudentName,UcCode,ClassCode" << std::endl;

  // Write the tree in the file
  for (auto it = students.begin(); it != students.end(); it++)
  {
    for (auto classe : it->second.getClasses())
    {
      // std::cout<< it->second.getCode() << "," << it->second.getName() << "," << classe.getUcCode() << "," << classe.getClassCode() << std::endl;
      file << it->second.getCode() << "," << it->second.getName() << "," << classe.getUcCode() << "," << classe.getClassCode() << std::endl;
    }
  }
}


void listAllChanges(){
  std::string way = "schedule/backup";
  std::vector<std::string> backups;

  for(const auto &in : std::filesystem::directory_iterator(way)){
    if(std::filesystem::is_regular_file(in)){
      backups.push_back(in.path());
    }
  for(unsigned i = 0; i < backups.size(); i++){
    std::cout << i << " - " << backups[i] << std::endl;
  }
  }
}