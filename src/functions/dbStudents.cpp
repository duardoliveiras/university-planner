#include "dbStudents.h"
#include <climits>
#include <algorithm>
#include <fstream>


int equilibre = 3;
int max_students = 6;

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

// ------------------------------------------------ //

// receives the student pointer by reference and removes the UC
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

// receives the stuede pointer by reference and add the new Class
void addClassStudent(std::string ucCode, std::string classCode, std::map<std::string, studentComp>::iterator& it){

    ClassComp classe(ucCode, classCode);
    it->second.getClasses().push_back(classe);
}


// receives the student pointer by reference and class Tree (classes) and th UC code and class code
bool valideNewClass(std::string ucCode, std::string classCode, std::map<std::string, studentComp>::iterator& it, std::map<std::string, ClassComp>& classes){

    // call function to order the classes of the student by int day
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
        std::cout << "Error in find class" << std::endl;
        return true;
    }else{
      // verify if has a class in the same day and time
      for(const auto& class_info : it_class->second.getClassInfoVec()){
        // get all classes of the day of class 
        const std::set<classInfo>& classesOfDay = orderClasses[class_info.dayInt];

        // and verify if the student has a class in the same time  
        // aula -> student classes
        // class_info -> class to add
        for(const auto& aula : classesOfDay){
          if(class_info.startTime >= aula.startTime && class_info.startTime < aula.startTime + aula.duration){
            std::cout << "Error: Incompatible schedules" << std::endl;
            return true;
          }
        } 
      }
      return false;
    }
}

// receives classCount Tree pointer and verify if the class is able to accept new students
std::list<std::string> valideFreeClass(std::map<std::string, std::vector<classQtd>>::iterator it_count){
  int min = INT_MAX;
  std::list<std::string> free_classes;

  // first verify the class with the minimum number of students
  for(auto& classe : it_count->second){
    if(classe.qtd < min){
      min = classe.qtd;
    }
  }
  // then verify if the class is able to accept new students and add to the list
  for(auto& classe : it_count->second){
    if(!(classe.qtd+1 - min > equilibre) && classe.qtd+1  <= max_students ){
       free_classes.push_back(classe.classCode);
    }
  }

  // return list
  return free_classes;
}


// Receives the student pointer and print your classes
void printStudentClasses(std::map<std::string, studentComp>::iterator& it){
  system("clear");
  std::cout<< "\nCode: " << it->first << " - ";
  std::cout<< "Name: " << it->second.getName() << std::endl;
  std::cout<< "Classes: " << std::endl;
  for(const auto& classe : it->second.getClasses()){
    std::cout << "  " << classe.getUcCode() << " - " << classe.getClassCode() << std::endl;
  }
}

// Receives the classCount by reference and verify if the new uc is already in the tree
// then print  the classes that are able to accept new students
void printFreeClasses(std::string ucCode, std::map<std::string, std::vector<classQtd>>& count){
        
        auto it_count = count.find(ucCode);

        // searches for Code in the classCont tree and returns a list of all classes that are able to accept new students
        if(it_count != count.end()){
          std::list<std::string> free_classes = valideFreeClass(it_count);
          std::cout << "   Classes: " << std::endl;

          if(!free_classes.empty()){
            for(auto it_list = free_classes.begin(); it_list != free_classes.end(); it_list++){
              std::cout << "      " << *it_list << std::endl;
            }
          }else{
            std::cout << "      No classes available" << std::endl;
          }
        }else{
          std::cout << " Uc not found" << std::endl;
        }

}


// This function receives the student pointer, the class tree (classes)
std::map<int, std::set<classInfo>> orderStudentClass(std::map<std::string, studentComp>::iterator& it, std::map<std::string, ClassComp>& classes){

    // map to order the classes by day
    std::map<int, std::set<classInfo>> orderClasses;

    // for each class of the student, search in the class tree and add the classInfo in the orderClasses map
    for(const auto& classe : it->second.getClasses()){
      std::string value = classe.getUcCode() + classe.getClassCode();

      // remove blank spaces
      value.erase(value.begin(), std::find_if(value.begin(), value.end(), [](unsigned char ch) {
          return !std::isspace(ch);
      }));
      value.erase(std::find_if(value.rbegin(), value.rend(), [](unsigned char ch) {
          return !std::isspace(ch);
      }).base(), value.end());

      // student one class pointer, verify if the class exists in the class tree
      auto it_class = classes.find(value);

      // if the class does not exist, print error
      if(it_class == classes.end()){
        std::cerr << "Error in find class" << std::endl;
      }else{
        // if exists, add the classInfo in the orderClasses map
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