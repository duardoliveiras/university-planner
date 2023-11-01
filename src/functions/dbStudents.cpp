#include "dbStudents.h"
#include "dbUcs.h"
#include <algorithm>
#include <climits>
#include <fstream>
#include <string>

int equilibre = 3;
int max_students = 6;

std::vector<myStudent> filterInfoStudent(int n, std::string str,
                                         std::vector<myStudent> &students) {
  //   std::vector<myStudent> filterStudent;
  //   switch (n) {
  //   case 1:
  //     // 1) Uc Code
  //     // for (const auto &mystudent : students) {
  //     //   // if (str == mystudent.getUcCode()) {
  //     //   //   selectStudent.push_back(mystudent);
  //     //   // }
  //     // }
  //     break;
  //   case 2:
  //     // 2) Class Code
  //     // for (const auto &mystudent : students) {
  //     //   // if (str == mystudent.getClassCode()) {
  //     //   //   filterStudent.push_back(mystudent);
  //     //   // }
  //     // }
  //     break;
  //   case 3:
  //     // 3) Year
  //     break;
  //   default:
  //     errorMessage();
  //     break;
  //   }
  //   return filterStudent;
  workingMessage();
  return students;
}

// bool compareStudentsCode(const myStudent &student1, const myStudent
// &student2) {
//   return student1.getStudentCode() < student2.getStudentCode();
// }
// // bool compareClassesCode(const myStudent &student1, const myStudent
// &student2)
// // {
// //   return student1.getClassCode() < student2.getClassCode();
// // }
// // bool compareUcsCode(const myStudent &student1, const myStudent
// &student2)
// {
// //   return student1.getUcCode() < student2.getUcCode();
// // }

// std::vector<myStudent> orderInfoStudent(int n,
//                                         std::vector<myStudent> &students) {
//   std::vector<myStudent> orderStudent = students;

//   switch (n) {
//   case 1:
//     // 2) Sort by uc code asc
//     std::sort(orderStudent.begin(), orderStudent.end(), compareUcsCode);
//     break;
//   case 2:
//     // 2) Sort by uc code desc
//     std::sort(orderStudent.begin(), orderStudent.end(), compareUcsCode);
//     std::reverse(orderStudent.begin(), orderStudent.end());
//     break;
//   case 3:
//     // 3) Sort by class code asc
//     std::sort(orderStudent.begin(), orderStudent.end(),
//     compareClassesCode);

//     break;
//   case 4:
//     // 4) Sort by class code desc
//     std::sort(orderStudent.begin(), orderStudent.end(),
//     compareClassesCode); std::reverse(orderStudent.begin(),
//     orderStudent.end()); break;
//   case 5:
//     // 5) Sort by student code asc
//     std::sort(orderStudent.begin(), orderStudent.end(),
//     compareStudentsCode); break;
//   case 6:
//     // 6) Sort by student code desc
//     std::sort(orderStudent.begin(), orderStudent.end(),
//     compareStudentsCode); std::reverse(orderStudent.begin(),
//     orderStudent.end()); break;
//   default:
//     errorMessage();
//     break;
//   }

//   return orderStudent;
// }

// std::vector<myStudent> selectStudent(std::string str,
//                                      std::vector<myStudent> &students) {
//   std::vector<myStudent> selectStudent;

//   for (const auto &mystudent : students) {
//     if (str == std::to_string(mystudent.getStudentCode())) {
//       selectStudent.push_back(mystudent);
//     }
//   }

//   return selectStudent;
// }

// // ------------------------------------------------ //

// // receives the student pointer by reference and removes the UC
bool removeUcStudent(std::string ucCod,
                     std::map<std::string, myStudent>::iterator &it) {
  //   bool remove = false;
  //   // for (unsigned i = 0; i < it->second.getClasses().size(); i++) {
  //   //   if (it->second.getClasses()[i].getUcCode() == ucCod) {
  //   //     it->second.getClasses().erase(it->second.getClasses().begin() +
  //   i);
  //   //     remove = true;
  //   //   }
  //   // }
  //   return remove;
  workingMessage();
  return false;
}

// // receives the stuede pointer by reference and add the new Class
void addClassStudent(std::string ucCode, std::string classCode,
                     std::map<std::string, myStudent>::iterator &it) {
  workingMessage();
  //   // myUc classe(ucCode, classCode);
  //   // it->second.getClasses().push_back(classe);
  // }

  // // receives the student pointer by reference and class Tree (classes) and
  // th UC
  // // code and class code
}

bool valideNewClass(std::string ucCode, std::string classCode,
                    std::map<std::string, myStudent>::iterator &it,
                    std::map<std::string, myUc> &classes) {
  workingMessage();
  //   // call function to order the classes of the student by int day
  //   std::map<int, std::set<classInfo>> orderClasses =
  //       orderStudentClass(it, classes);

  //   std::string value = ucCode + classCode;

  //   // Remove blank spaces
  //   value.erase(value.begin(),
  //               std::find_if(value.begin(), value.end(),
  //                            [](unsigned char ch) { return
  //                            !std::isspace(ch);
  //                            }));
  //   value.erase(std::find_if(value.rbegin(), value.rend(),
  //                            [](unsigned char ch) { return
  //                            !std::isspace(ch);
  //                            })
  //                   .base(),
  //               value.end());

  //   auto it_class = classes.find(value);

  //   if (it_class == classes.end()) {
  //     std::cout << "Error in find class" << std::endl;
  //     return true;
  //   } else {
  //     // verify if has a class in the same day and time
  //     for (const auto &class_info : it_class->second.getClassInfoVec()) {
  //       // get all classes of the day of class
  //       const std::set<classInfo> &classesOfDay =
  //       orderClasses[class_info.dayInt];

  //       // and verify if the student has a class in the same time
  //       // aula -> student classes
  //       // class_info -> class to add
  //       for (const auto &aula : classesOfDay) {
  //         if (class_info.startTime >= aula.startTime &&
  //             class_info.startTime < aula.startTime + aula.duration) {
  //           std::cout << "Error: Incompatible schedules" << std::endl;
  //           return true;
  //         }
  //       }
  //     }
  //     return false;
  //   }
  return false;
}

// // receives classCount Tree pointer and verify if the class is able to
// accept
// // new students
// std::list<std::string> valideFreeClass(
//     std::map<std::string, std::vector<classQtd>>::iterator it_count) {
//   int min = INT_MAX;
//   std::list<std::string> free_classes;

//   // first verify the class with the minimum number of students
//   for (auto &classe : it_count->second) {
//     if (classe.qtd < min) {
//       min = classe.qtd;
//     }
//   }
//   // then verify if the class is able to accept new students and add to the
//   list for (auto &classe : it_count->second) {
//     if (!(classe.qtd + 1 - min > equilibre) && classe.qtd + 1 <=
//     max_students) {
//       free_classes.push_back(classe.classCode);
//     }
//   }

//   // return list
//   return free_classes;
// }

// void organizerUcStudent(std::map<std::string,myStudent>::iterator &it) {
//   workingMessage();
//   //   // std::sort(it->second.getClasses().begin(),
//   //   it->second.getClasses().end(),
//   //   //           myUc::compareUcCode);
// }

// // This function receives the student pointer, the class tree (classes)
std::map<int, std::set<classInfo>>
orderStudentClass(std::map<std::string, myStudent>::iterator &it,
                  std::map<std::string, myUc> &classes) {

  // map to order the classes by day
  std::map<int, std::set<classInfo>> orderClasses;

  //   // for each class of the student, search in the class tree and add the
  //   // classInfo in the orderClasses map
  //   // for (const auto &classe : it->second.getClasses()) {
  //   //   std::string value = classe.getUcCode() + classe.getClassCode();

  //   //   // remove blank spaces
  //   //   value.erase(value.begin(),
  //   //               std::find_if(value.begin(), value.end(), [](unsigned
  //   char ch)
  //   //               {
  //   //                 return !std::isspace(ch);
  //   //               }));
  //   //   value.erase(std::find_if(value.rbegin(), value.rend(),
  //   //                            [](unsigned char ch) { return
  //   !std::isspace(ch);
  //   //                            })
  //   //                   .base(),
  //   //               value.end());

  //   //   // student one class pointer, verify if the class exists in the
  //   class
  //   //   tree auto it_class = classes.find(value);

  //   //   // if the class does not exist, print error
  //   //   if (it_class == classes.end()) {
  //   //     std::cerr << "Error in find class" << std::endl;
  //   //   } else {
  //   //     // if exists, add the classInfo in the orderClasses map
  //   //     for (const auto &classInfo : it_class->second.getClassInfoVec()) {
  //   //       orderClasses[classInfo.dayInt].insert(classInfo);
  //   //     }
  //   //   }
  //   // }
  //   /*
  //   for(const auto& pair : orderClasses ){
  //     std::cout << "Day: " << pair.first << std::endl;
  //     for(const auto& info : pair.second){
  //       std::cout << info.startTime << " - ";
  //       std::cout << info.duration << " - ";
  //       std::cout << info.type << std::endl;
  //     }
  //     std::cout << std::endl;
  //   }
  //   */
  workingMessage();
  return orderClasses;
}
