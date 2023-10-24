#include <iostream>


#include "classes/studentComp.h"
#include <map>
#include "classes/ClassComp.h"
#include <string>
#include <fstream>
#include <sstream>
#include <set>

void menu();

int main() {
  system("clear");


std::map<std::string, ClassComp> classes;
std::ifstream file2("schedule/classes.csv");
std::string line2;

if (!file2.is_open()) {
    std::cerr << "Error opening file" << std::endl;
}

std::getline(file2, line2);

while (std::getline(file2, line2)) {
    std::istringstream ss(line2);
    std::string classCode, ucCode, day, type;
    double startTime, duration;

    std::getline(ss, classCode, ',');
    std::getline(ss, ucCode, ',');
    std::getline(ss, day, ',');
    ss >> startTime;
    ss.ignore();
    ss >> duration;
    ss.ignore();
    getline(ss, type, ',');

    ClassComp classe(classCode, ucCode);

    classe.setDay(day);
    classe.setStartTime(startTime);
    classe.setDuration(duration);
    classe.setType(type);


    classes.emplace(classCode + ucCode + type, classe);

}

file2.close();

/*
for(const auto& pair : classes){
  ClassComp classe = pair.second;
  std::cout << classe.getClassCode() << " - ";
  std::cout << classe.getUcCode() << " - ";
  std::cout << classe.getDay() << " - ";
  std::cout << classe.getStartTime() << " - ";
  std::cout << classe.getDuration() << " - ";
  std::cout << classe.getType() << std::endl;
}
*/


std::map<std::string, studentComp> students;
std::ifstream file("schedule/students_classes.csv");
std::string line;

if (!file.is_open()) {
    std::cerr << "Error opening file" << std::endl;
}

while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string studentCode, name, uc, classCode;

    if (std::getline(ss, studentCode, ',') && std::getline(ss, name, ',') &&
        std::getline(ss, uc, ',') && std::getline(ss, classCode)) {

        ClassComp classe(classCode, uc);
        studentComp student(studentCode, name);

        auto it = students.find(studentCode);

        if (it == students.end()) {
            // O aluno não foi encontrado, então insira um novo par chave-valor.
            student.addClass(classe);
            students.emplace(studentCode, student);
        } else {
            // O aluno foi encontrado, então apenas adicione a classe ao aluno existente.
            it->second.addClass(classe);
        }
    }
}

file.close();




// print tree
/*
for(const auto& pair : students){
  std::string studentCode = pair.first;
  studentComp student = pair.second;
  int count = 0;
  std::cout << "Student code: " << studentCode << " ";
  std::cout << "Student name: " << student.getName() << std::endl;
  std::cout << "--- Classes ---" << std::endl;

  for(const ClassComp& classe : student.getClasses()){
    std::cout << classe.getUcCode() << " - ";
    std::cout << classe.getClassCode() << std::endl;
   
    count++;

  }
  std::cout << "Total classes: " << count << std::endl;

}
*/

  
  
  
  menu();



  return 0;
}