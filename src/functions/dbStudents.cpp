#include "dbStudents.h"

bool compareStudentsCode(const myStudent &student1, const myStudent &student2) {
  return student1.getStudentCode() < student2.getStudentCode();
}
bool compareClassesCode(const myStudent &student1, const myStudent &student2) {
  return student1.getClassCode() < student2.getClassCode();
}
bool compareUcsCode(const myStudent &student1, const myStudent &student2) {
  return student1.getUcCode() < student2.getUcCode();
}

std::map<std::string, myStudent>
filterInfoStudent(int n, std::string str,
                  std::map<std::string, myStudent> &students) {
  std::map<std::string, myStudent> filterStudent;
  switch (n) {
  case 1:
    // 1) Uc Code
    break;
  case 2:
    // 2) Class Code
    break;
  case 3:
    // 3) Year
    break;
  default:
    errorMessage();
    break;
  }
  return filterStudent;
}

std::map<std::string, myStudent>
orderInfoStudent(int n, std::map<std::string, myStudent> &students) {
  std::map<std::string, myStudent> orderStudent = students;

  switch (n) {
  case 1:
    // 2) Sort by uc code asc
    // std::sort(orderStudent.begin(), orderStudent.end(), compareUcsCode);
    break;
  case 2:
    // 2) Sort by uc code desc
    // std::sort(orderStudent.begin(), orderStudent.end(), compareUcsCode);
    // std::reverse(orderStudent.begin(), orderStudent.end());
    break;
  case 3:
    // 3) Sort by class code asc
    // std::sort(orderStudent.begin(), orderStudent.end(), compareClassesCode);

    break;
  case 4:
    // 4) Sort by class code desc
    // std::sort(orderStudent.begin(), orderStudent.end(), compareClassesCode);
    // std::reverse(orderStudent.begin(), orderStudent.end());
    break;
  case 5:
    // 5) Sort by student code asc
    // std::sort(orderStudent.begin(), orderStudent.end(), compareStudentsCode);
    break;
  case 6:
    // 6) Sort by student code desc
    // std::sort(orderStudent.begin(), orderStudent.end(), compareStudentsCode);
    // std::reverse(orderStudent.begin(), orderStudent.end());
    break;
  default:
    errorMessage();
    break;
  }

  return orderStudent;
}

std::map<std::string, myStudent>
selectStudent(const std::string &str,
              const std::map<std::string, myStudent> &students) {
  std::map<std::string, myStudent> selectedStudents;

  for (auto &studentPair : students) {
    const myStudent &mystudent = studentPair.second;
    if (str == mystudent.getStudentCode()) {
      selectedStudents[studentPair.first] = mystudent;
    }
  }

  return selectedStudents;
}

// ------------------------------------------------ //

// receives the student pointer by reference and removes the UC
bool removeUcStudent(std::string ucCod,
                     std::map<std::string, myStudent>::iterator &it) {
  bool remove = false;
  for (unsigned i = 0; i < it->second.getClasses().size(); i++) {
    if (it->second.getClasses()[i].getUcCode() == ucCod) {
      it->second.getClasses().erase(it->second.getClasses().begin() + i);
      remove = true;
    }
  }
  return remove;
}

// receives the stuede pointer by reference and add the new Class
void addClassStudent(std::string ucCode, std::string classCode,
                     std::map<std::string, myStudent>::iterator &it,
                     std::stack<alter> &stackAlter) {

  myUc classe(ucCode, classCode);
  it->second.getClasses().push_back(classe);

  stackAlter.push({it->second.getStudentCode(), it->second.getStudentName(),
                   "add", ucCode, classCode});
}

// receives the student pointer by reference and class Tree (classes) and th UC
// code and class code
bool valideNewClass(std::string ucCode, std::string classCode,
                    std::map<std::string, myStudent>::iterator &it,
                    std::map<std::string, myUc> &classes) {

  // call function to order the classes of the student by int day
  std::map<int, std::set<classInfo>> orderClasses =
      orderStudentClass(it, classes);

  std::string value = ucCode + classCode;

  // Remove blank spaces
  value.erase(value.begin(),
              std::find_if(value.begin(), value.end(),
                           [](unsigned char ch) { return !std::isspace(ch); }));
  value.erase(std::find_if(value.rbegin(), value.rend(),
                           [](unsigned char ch) { return !std::isspace(ch); })
                  .base(),
              value.end());

  auto it_class = classes.find(value);

  if (it_class == classes.end()) {
    std::cout << "Error in find class" << std::endl;
    return true;
  } else {
    // verify if has a class in the same day and time
    for (const auto &class_info : it_class->second.getClassInfoVec()) {
      // get all classes of the day of class
      const std::set<classInfo> &classesOfDay = orderClasses[class_info.dayInt];

      // and verify if the student has a class in the same time
      // aula -> student classes
      // class_info -> class to add
      for (const auto &aula : classesOfDay) {
        if (class_info.startTime >= aula.startTime &&
            class_info.startTime < aula.startTime + aula.duration) {
          std::cout << "Error: Incompatible schedules" << std::endl;
          return true;
        }
      }
    }
    return false;
  }
}

void organizerUcStudent(std::map<std::string, myStudent>::iterator &it) {

  std::sort(it->second.getClasses().begin(), it->second.getClasses().end(),
            myUc::compareUcCode);
}

// This function receives the student pointer and the class tree (classes)
std::map<int, std::set<classInfo>>
orderStudentClass(std::map<std::string, myStudent>::iterator &it,
                  std::map<std::string, myUc> &classes) {

  // map to order the classes by day
  std::map<int, std::set<classInfo>> orderClasses;

  // for each class of the student, search in the class tree and add the
  // classInfo in the orderClasses map
  for (const auto &classe : it->second.getClasses()) {
    std::string value = classe.getUcCode() + classe.getClassCode();

    // remove blank spaces
    value.erase(value.begin(),
                std::find_if(value.begin(), value.end(), [](unsigned char ch) {
                  return !std::isspace(ch);
                }));
    value.erase(std::find_if(value.rbegin(), value.rend(),
                             [](unsigned char ch) { return !std::isspace(ch); })
                    .base(),
                value.end());

    // student one class pointer, verify if the class exists in the class tree
    auto it_class = classes.find(value);

    // if the class does not exist, print error
    if (it_class == classes.end()) {
      std::cerr << "Error in find class" << std::endl;
    } else {
      // if exists, add the classInfo in the orderClasses map
      for (auto &classInfo : it_class->second.getClassInfoVec()) {
        classInfo.code = classe.getUcCode();
        orderClasses[classInfo.dayInt].insert(classInfo);
      }
    }
  }

  return orderClasses;
}
std::string weekDayString(int day) {
  switch (day) {
  case 2:
    return "Monday";
    break;
  case 3:
    return "Tuesday";
    break;
  case 4:
    return "Wednesday";
    break;
  case 5:
    return "Thursday";
    break;
  case 6:
    return "Friday";
    break;
  case 7:
    return "Saturday";
    break;
  default:
    return "Error Day";
    break;
  }
}
void showStudentClasses(std::map<std::string, myStudent>::iterator &it,
                        std::map<std::string, myUc> &classes) {
  auto orderClasses = orderStudentClass(it, classes);
  std::cout << "\nSchedules: " << std::endl;
  for (const auto &pair : orderClasses) {
    std::string day = weekDayString(pair.first);
    std::cout << "Day: " << day << std::endl;
    for (const auto &info : pair.second) {
      std::cout << info.code << " - ";
      std::cout << info.startTime << " to ";
      std::cout << info.startTime + info.duration << " - ";
      std::cout << info.type << std::endl;
    }
    std::cout << std::endl;
  }
}

// Checks whether the student is already enrolled in a UC class. If it returns
// true it means a problem was found
bool verifyUcCode(std::string ucCode,
                  std::map<std::string, myStudent>::iterator &it) {

  for (const auto &classe : it->second.getClasses()) {
    if (classe.getUcCode() == ucCode) {
      return true;
    }
  }

  return false;
}