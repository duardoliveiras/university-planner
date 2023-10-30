#include "read.h"
#include <sstream>
#include <algorithm>



std::vector<myClass> readAllClasses() {
  std::vector<myClass> data;

  std::ifstream classesdata("schedule/classes.csv");

  // Check if open
  if (!classesdata.is_open()) {
    errorMessageFile();
  }

  std::string line;
  bool header = true;

  while (std::getline(classesdata, line)) {
    if (header) {
      header = false;
      continue;
    }

    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) {
      tokens.push_back(token);
    }

    // Check if file has at least 7 parameters:
    // ClassCode,UcCode,Weekday,StartHour,Duration,Type,Date
    if (tokens.size() < 6) {
      errorMessageLine(line);
    }

    // Store information
    std::string classCode = tokens[0];
    std::string ucCode = tokens[1];

    std::string weekday = tokens[2];
    float startHour = std::stof(tokens[3]);
    float duration = std::stof(tokens[4]);
    std::string type = tokens[5];

    Slot slot{weekday, startHour, duration, type};

    std::vector<Slot> slots = {slot};
    myClass myclass(classCode, ucCode, slots);
    data.push_back(myclass);
  }

  classesdata.close();
  return data;
}

std::vector<myStudent> readAllStudents() {
  std::vector<myStudent> data;

  std::ifstream studentsdata("schedule/students_classes.csv");

  // Check if open
  if (!studentsdata.is_open()) {
    errorMessageFile();
  }

  std::string line;
  bool header = true;

  while (std::getline(studentsdata, line)) {

    if (header) {
      header = false;
      continue;
    }

    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) {
      tokens.push_back(token);
    }

    // Check if file have 4 parameters:
    // StudentCode,StudentName,UcCode,ClassCode
    if (tokens.size() < 4) {
      errorMessageLine(line);
    }

    // Store information
    int studentCode = std::stoi(tokens[0]);
    std::string studentName = tokens[1];
    std::vector<std::string> ucCode = {tokens[2]};
    std::vector<std::string> classCode = {tokens[3]};

    myStudent mystudent(studentCode, studentName, ucCode, classCode);
    data.push_back(mystudent);
  }

  studentsdata.close();
  return data;
}

std::vector<myUc> readAllUcs() {
  std::vector<myUc> data;

  std::ifstream ucdata("schedule/classes_per_uc.csv");

  // Check if open
  if (!ucdata.is_open()) {
    errorMessageFile();
  }

  std::string line;
  bool header = true;

  while (std::getline(ucdata, line)) {
    if (header) {
      header = false;
      continue;
    }

    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (std::getline(ss, token, ',')) {
      tokens.push_back(token);
    }

    // Check if file have 2 parameters:
    // UcCode,ClassCode
    if (tokens.size() < 2) {
      errorMessageLine(line);
    }

    // Store information
    std::string ucCode = tokens[0];
    std::vector<std::string> classCode = {tokens[1]};

    myUc uc(ucCode, classCode);
    data.push_back(uc);
  }
  ucdata.close();
  return data;
}


// read to vector ClasseComp
/* 
std::vector<ClassComp> read_classes(){

std::vector<ClassComp> classes;
std::ifstream file("schedule/classes.csv");
std::string line;

if (!file.is_open()) {
    std::cerr << "Error opening file" << std::endl;
}

std::getline(file, line);

while (std::getline(file, line)) {
    std::istringstream ss(line);
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

    ClassComp classe(ucCode, classCode);

    classe.setDay(day);
    classe.setStartTime(startTime);
    classe.setDuration(duration);
    classe.setType(type);


    classes.push_back(classe);

}
  file.close();
  
  for(const auto& classe : classes){
    std::cout << classe.getUcCode() << " - ";
    std::cout << classe.getClassCode() << " - ";
    std::cout << classe.getDay() << " - ";
    std::cout << classe.getStartTime() << " - ";
    std::cout << classe.getDuration() << " - ";
    std::cout << classe.getType() << std::endl;
  }
  

  return classes;
}
*/ 

// read to tree classeComp with vector classInfo
std::map<std::string, ClassComp> read_classes(){
    std::map<std::string, ClassComp> classes;
    std::ifstream file("schedule/classes.csv");
    std::string line;

    if(!file.is_open()){
      std::cerr<< "Error opening file" << std::endl;
    }

    while(std::getline(file,line)){

      std::istringstream ss(line);
      std::string classCode, ucCode, day, type; 
      int dayInt;
      double startTime, duration;

      if(std::getline(ss, classCode, ',') && std::getline(ss, ucCode, ',') && std::getline(ss, day, ',')
       && ss >> startTime && ss.ignore() && ss >> duration && ss.ignore() && std::getline(ss, type)){
        
        // Change day to int
        if(day == "Monday"){
          dayInt = 2;
        }else if(day == "Tuesday"){
          dayInt = 3;
        }else if(day == "Wednesday"){
          dayInt = 4;
        }else if(day == "Thursday"){
          dayInt = 5;
        }else if(day == "Friday"){
          dayInt = 6;
        }else if(day == "Saturday"){
          dayInt = 7;
        }else{
          dayInt = 0;
        }
        
        // create a object of classComp
        ClassComp classe(ucCode, classCode);
        // and add the classInfo
        classe.addClassInfo(type, day, dayInt, startTime, duration);

        // try to find the class in the tree
        auto it = classes.find(classe.getUcCode() + classe.getClassCode());

        // if not found, add the class in the tree
        if(it == classes.end()){
          classes.emplace(ucCode + classCode, classe);
        }else{
          // if found, add the +1 classInfo in the class
          it->second.addClassInfo(type, day, dayInt, startTime, duration);
        }
      }

    }

    file.close();
      /*
      for(const auto& classe : classes){
        std::cout << classe.second.getUcCode() << " - ";
        std::cout << classe.second.getClassCode() << std::endl;
        for(const auto& info : classe.second.getClassInfoVec()){
          std::cout<< "   ";
          std::cout << info.day << " - ";
          std::cout << info.dayInt << " - ";
          std::cout << info.startTime << " - ";
          std::cout << info.duration << " - ";
          std::cout << info.type << std::endl;
        }
      }
      */
    
    
    return classes;
}

// read ucs and update countClass
std::map<std::string, myUc> read_ucs(std::map<std::string, std::vector<classQtd>>& count){
      
      std::map<std::string, myUc> ucs;
      std::ifstream file("schedule/classes_per_uc.csv");
      std::string line;

      if (!file.is_open()) {
          std::cerr << "Error opening file" << std::endl;
      }

      while (std::getline(file,line)){
         std::istringstream ss(line);
         std::string ucCode, classCode;

        if(std::getline(ss, ucCode, ',') && std::getline(ss, classCode)){
            myUc uc(ucCode);
            // try to find the uc in the tree
            auto it = ucs.find(ucCode);
            
          classCode.erase(std::find_if(classCode.rbegin(), classCode.rend(), [](unsigned char ch) {
          return !std::isspace(ch);
          }).base(), classCode.end());

            // if not found, add the class in the uc and add the uc in the tree
            if(it == ucs.end()){
               uc.addClass(classCode);
               ucs.emplace(ucCode, uc);
            
            }else{ // if found, only add the class in the uc
                it->second.addClass(classCode);
            }

            bool exist = false;

            // try to find the uc in the count tree
            auto it_count = count.find(ucCode);

            // if found, verify if the class exists in the vector
            if(it_count != count.end()){
              for(auto& class_it : it_count->second){
                if(class_it.classCode == classCode){
                  exist = true;
                }
              }
              // if exist uc in the count tree, but not exist the class, add the class with 0 students
              if(!exist){
                it_count->second.push_back({classCode, 0});
              }
            // if not found, add the uc and class with 0 students
            }else{
              std::vector<classQtd> classVec;
              classVec.push_back({classCode, 0});
              count.emplace(ucCode, classVec);
            }
        }
      
      
      }
      file.close();

      /*
      for(const auto& myUc : ucs){
        std::cout << myUc.second.getUcCode() << std::endl;
        std::cout<< " --- Classes: " << std::endl;

        for(const auto& classCode : myUc.second.getClassCode()){
          std::string a = classCode;
          std::cout<< a << std::endl;
        }
      }
      */
      return ucs;
}

// Read students and countClass
std::map<std::string, studentComp> read_students(std::map<std::string, std::vector<classQtd>>& count){
  
  std::map<std::string, studentComp> students;
  std::ifstream file("schedule/students_classes.csv");
  std::string line;

  bool header = true;

  if (!file.is_open()) {
      std::cerr << "Error opening file" << std::endl;
  }

  while (std::getline(file, line)) {
      if(header){
        header = false;
        continue;
      }
      std::istringstream ss(line);
      std::string studentCode, name, uc, classCode;


      if (std::getline(ss, studentCode, ',') && std::getline(ss, name, ',') &&
          std::getline(ss, uc, ',') && std::getline(ss, classCode)) { 
          
          // create a object of classComp
          ClassComp classe(uc, classCode);
          // create a object of studentComp
          studentComp student(studentCode, name);
          // try to find the student in the tree
          auto it = students.find(studentCode);

      classCode.erase(std::find_if(classCode.rbegin(), classCode.rend(), [](unsigned char ch) {
          return !std::isspace(ch);
      }).base(), classCode.end());

          // if student not found, then add class to student and add student to tree
          if (it == students.end()) {
              student.addClass(classe);
              students.emplace(studentCode, student);
          } else {
              // if student found, only add class to student
              it->second.addClass(classe);
          }

          // verify if the uc exists in the count tree
          auto it_count = count.find(uc);

          // if not exists, add the class with one student in the count tree
          if (it_count == count.end()) {
              std::vector<classQtd> classVec;
              classVec.push_back({classCode, 1});
              count.emplace(uc, classVec);
          } else {
              // if uc exist, then verify if the class exists in the vector
              bool exist = false;
              for(auto& class_it : it_count->second){
                // if exists, add +1 in the qtd
                if(class_it.classCode == classCode){
                  class_it.qtd++;
                  exist = true;
                  break;
                }
              }
              // if not exists, add the class with one student in the vector
              if(!exist){
                it_count->second.push_back({classCode, 1});
              }
          }

      }
  }

  file.close();


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
  
  } */
  return students;

}

