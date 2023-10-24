#include <iostream>


#include "classes/studentComp.h"
#include <map>
#include "classes/ClassComp.h"
#include <string>
#include <fstream>
#include <sstream>

void menu();

int main() {
  system("clear");



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


for(const auto& pair : students){
  std::string studentCode = pair.first;
  studentComp student = pair.second;

  std::cout << "Student code: " << studentCode << std::endl;
  std::cout << "Student name: " << student.getName() << std::endl;

}
  
  menu();



  return 0;
}