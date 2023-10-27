#include "dbStudents.h"
#include <climits>
#include <algorithm>
#include <fstream>

void menuStudents(std::string str, int type, int filter, int order) {
  // read Database
  std::vector<myStudent> data = readAllStudents();

  if (type == 1) {
    data = selectStudent(str, data);
  } else {
    if (type == 2) {
      data = filterInfoStudent(filter, str, data);
    }
    data = orderInfoStudent(order, data);
  }

  printStudent(data);
}

std::vector<myStudent> filterInfoStudent(int n, std::string str,
                                         std::vector<myStudent> &students) {
  std::vector<myStudent> filterStudent;
  switch (n) {
  case 1:
    // 1) Uc Code
  case 2:
    // 2) Class Code
  case 3:
    // 3) Year
  default:
    errorMessage();
    break;
  }
  return filterStudent;
}

bool compareStudentsCode(const myStudent &student1, const myStudent &student2) {
  return student1.getStudentCode() < student2.getStudentCode();
}
bool compareClassesCode(const myStudent &student1, const myStudent &student2) {
  return student1.getClassCode() < student2.getClassCode();
}
bool compareUcsCode(const myStudent &student1, const myStudent &student2) {
  return student1.getUcCode() < student2.getUcCode();
}

std::vector<myStudent> orderInfoStudent(int n,
                                        std::vector<myStudent> &students) {
  std::vector<myStudent> orderStudent = students;

  switch (n) {
  case 1:
    // 2) Sort by uc code asc
    std::sort(orderStudent.begin(), orderStudent.end(), compareUcsCode);
    break;
  case 2:
    // 2) Sort by uc code desc
    std::sort(orderStudent.begin(), orderStudent.end(), compareUcsCode);
    std::reverse(orderStudent.begin(), orderStudent.end());
    break;
  case 3:
    // 3) Sort by class code asc
    std::sort(orderStudent.begin(), orderStudent.end(), compareClassesCode);

    break;
  case 4:
    // 4) Sort by class code desc
    std::sort(orderStudent.begin(), orderStudent.end(), compareClassesCode);
    std::reverse(orderStudent.begin(), orderStudent.end());
    break;
  case 5:
    // 5) Sort by student code asc
    std::sort(orderStudent.begin(), orderStudent.end(), compareStudentsCode);
    break;
  case 6:
    // 6) Sort by student code desc
    std::sort(orderStudent.begin(), orderStudent.end(), compareStudentsCode);
    std::reverse(orderStudent.begin(), orderStudent.end());
    break;
  default:
    errorMessage();
    break;
  }

  return orderStudent;
}

std::vector<myStudent> selectStudent(std::string str, std::vector<myStudent> &students) {
  std::vector<myStudent> selectStudent;

  for (const auto &mystudent : students) {
    if (str == std::to_string(mystudent.getStudentCode())) {
      selectStudent.push_back(mystudent);
    }
  }

  return selectStudent;
}



bool removeUcStudent(std::string ucCod, std::map<std::string, studentComp>::iterator& it){
    bool remove = false;
    for(unsigned i = 0; i < it->second.getClasses().size(); i++){
        if(it->second.getClasses()[i].getUcCode() == ucCod){
            it->second.getClasses().erase(it->second.getClasses().begin() + i);
            remove = true;
        }
    }
    return remove;
}

void addClassStudent(std::string ucCode, std::string classCode, std::map<std::string, studentComp>::iterator& it){

    ClassComp classe(ucCode, classCode);

    it->second.getClasses().push_back(classe);
}

bool valideNewClass(std::string ucCode, std::string classCode, std::map<std::string, studentComp>::iterator& it, std::map<std::string, ClassComp>& classes){

    std::map<int, std::set<classInfo>> orderClasses = orderStudentClass(it, classes);

    std::string value = ucCode + classCode;

      // Remove blank spaces
      value.erase(value.begin(), std::find_if(value.begin(), value.end(), [](unsigned char ch) {
          return !std::isspace(ch);
      }));
      value.erase(std::find_if(value.rbegin(), value.rend(), [](unsigned char ch) {
          return !std::isspace(ch);
      }).base(), value.end());

    auto it_class =  classes.find(value);
    
    if(it_class == classes.end()){
        std::cerr << "Error in find class" << std::endl;
        return true;
    }else{

      for(const auto& class_info : it_class->second.getClassInfoVec()){
        const std::set<classInfo>& classesOfDay = orderClasses[class_info.dayInt];
        for(const auto& aula : classesOfDay){
          if(class_info.startTime >= aula.startTime && class_info.startTime < aula.startTime + aula.duration){
            return true;
          }
        } 
      }
      return false;
    }
}

std::list<std::string> valideFreeClass(std::map<std::string, std::vector<classQtd>>::iterator it_count){
  int min = INT_MAX;
  std::list<std::string> free_classes;

  for(auto& classe : it_count->second){
    if(classe.qtd < min){
      min = classe.qtd;
    }
  }
  for(auto& classe : it_count->second){
    if(!(classe.qtd+1 - min > 3) && classe.qtd+1  <= 6 ){
       free_classes.push_back(classe.classCode);
    }
  }

  return free_classes;
}

void printStudentClasses(std::map<std::string, studentComp>::iterator& it){
  system("clear");
  std::cout<< "\nCode: " << it->first << " - ";
  std::cout<< "Name: " << it->second.getName() << std::endl;
  std::cout<< "Classes: " << std::endl;
  for(const auto& classe : it->second.getClasses()){
    std::cout << "  " << classe.getUcCode() << " - " << classe.getClassCode() << std::endl;
  }
}

std::map<int, std::set<classInfo>> orderStudentClass(std::map<std::string, studentComp>::iterator& it, std::map<std::string, ClassComp>& classes){

    std::map<int, std::set<classInfo>> orderClasses;

    for(const auto& classe : it->second.getClasses()){
    std::string value = classe.getUcCode() + classe.getClassCode();

      // Remove blank spaces
      value.erase(value.begin(), std::find_if(value.begin(), value.end(), [](unsigned char ch) {
          return !std::isspace(ch);
      }));
      value.erase(std::find_if(value.rbegin(), value.rend(), [](unsigned char ch) {
          return !std::isspace(ch);
      }).base(), value.end());

      auto it_class = classes.find(value);

      if(it_class == classes.end()){
        std::cerr << "Error in find class" << std::endl;
      }else{
        for(const auto& classInfo : it_class->second.getClassInfoVec()){
          orderClasses[classInfo.dayInt].insert(classInfo);
          
        }
      }
    }
    /*
    for(const auto& pair : orderClasses ){
      std::cout << "Day: " << pair.first << std::endl;
      for(const auto& info : pair.second){
        std::cout << info.startTime << " - ";
        std::cout << info.duration << " - ";
        std::cout << info.type << std::endl;
      }
      std::cout << std::endl;
    }
    */
    return orderClasses;
}

/* 
void removeUcStudent(std::string ucCod, std::string registrationNumber){

    std::string studentData = "schedule/students_classes.csv";
    std::string studentDataNew = "output/studentes_classes_new.csv";

    std::string lineRemove;
    

    std::ifstream in(studentData);
    std::ofstream out(studentDataNew);

    if(!in.is_open() || !out.is_open()){
      std::cerr << "Error in open archives" << std::endl;
    }
    
    std::string line;

    while(std::getline(in,line)){
     
      size_t studentCodePos = line.find(registrationNumber);
      size_t ucCodePos = line.find(ucCod);

      if(studentCodePos != std::string::npos && ucCodePos != std::string::npos ){
        continue;
      }

      out << line << '\n';

    }
  

    in.close();
    out.close();
}
*/