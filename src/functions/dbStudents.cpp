#include "dbStudents.h"
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



void removeUcStudent(std::string ucCod, std::map<std::string, studentComp> &students){

  std::cout<<"chama no pagode" << std::endl;

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