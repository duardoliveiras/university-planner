#include "print.h"

int equilibre = 3;
int max_students = 6;

/**
 * @brief Print student information.
 *
 * This function prints a tabular representation of student information,
 * including student code, student name, associated UC codes, and class codes.
 *
 * @param students A map containing student information.
 */
void printStudent(const std::map<std::string, myStudent> &students) {
  std::cout << "Student Code | Student Name"
            << std::endl;
  
  for (const auto &studentPair : students) {
    const myStudent &student = studentPair.second;
    std::cout << student.getStudentCode() << " | " << student.getStudentName() << std::endl;
    std::cout << "   " << "Classes: " << std::endl;
    for(const auto &classe : student.getClasses()) {
      std::cout << "   " << classe.getUcCode() << " - " << classe.getClassCode() << std::endl;
    }

  }
}

//O(n) 
// n = number of lines in the file
/**
 * @brief Print students information from a vector.
 *
 * This function prints a tabular representation of student information,
 * including student code, student name, associated UC codes, and class codes,
 * from a vector of myStudent objects.
 *
 * @param students A vector containing myStudent objects.
 */
void printStudents(const std::vector<myStudent> &students) {
  std::cout << "Student Code | Student Name"
            << std::endl;

  if (students.empty()) {
    std::cout << "Empty vector ucs" << std::endl;
  }

  for (const auto &student : students) {
    std::cout << student.getStudentCode() << " | " << student.getStudentName() << std::endl;
    std::cout << "   " << "Classes: " << std::endl;
    for(const auto &classe : student.getClasses()) {
      std::cout << "   " << classe.getUcCode() << " - " << classe.getClassCode() << std::endl;
    }
  }
}

// O(m)
// Find the student in the map
// m = number of students
// m >= 7
/**
 * @brief Print student's classes.
 *
 * This function clears the screen and displays information about a student's
 * classes, including the student's code, name, and associated class codes.
 *
 * @param it An iterator pointing to a student in a map.
 */
void printStudentClasses(std::map<std::string, myStudent>::iterator &it) {
  system("clear");
  std::cout << "\nCode: " << it->first << " - ";
  std::cout << "Name: " << it->second.getStudentName() << std::endl;
  std::cout << "Classes: " << std::endl;
  for (const auto &classe : it->second.getClasses()) {
    std::cout << "  " << classe.getUcCode() << " - " << classe.getClassCode()
              << std::endl;
  }
}

//O(n) 
// n = number of lines in the file
/**
 * @brief Print UC classes information.
 *
 * This function displays information about UC classes, including UC code, class
 * code, type, day, dayInt, start time, and duration, from a vector of myUc
 * objects.
 *
 * @param ucVector A vector of myUc objects.
 * @param classes A map of class information.
 */
void printUcClasses(const std::vector<myUc> &ucVector) {
  std::cout << "UcCode | ClassCode | Type | Day | DayInt | StartTime | Duration"
            << std::endl;

  for (const auto &classes : ucVector) {

    auto infoVec = classes.getClassInfoVec();
    for (const auto &classInfo : infoVec) {
      std::string type = classInfo.type;
      std::string day = classInfo.day;
      int dayInt = classInfo.dayInt;
      double startTime = classInfo.startTime;
      double duration = classInfo.duration;
      std::cout << classes.getUcCode() << " | " << classes.getClassCode()
                << " | " << type << " | " << day << " | " << dayInt << " | "
                << startTime << " | " << duration << std::endl;
    }
  }
}

// O(n)
/**
 * @brief Print UC information.
 *
 * This function displays information about UCs, including UC code and class
 * code, from a vector of myUc objects.
 *
 * @param ucs A vector of myUc objects.
 */
void printUcs(const std::vector<myUc> &ucs) {
  std::cout << "UcCode | ClassCode" << std::endl;

  for (const auto &uc : ucs) {
    std::cout << uc.getUcCode() << " | " << uc.getClassCode() << std::endl;
  }
}

// O(m)
// Iterator to UC
// m = number of classes in the UC
/**
 * @brief Find and return valid free classes.
 *
 * This function calculates and returns a list of valid free classes based on
 * the input class information. Valid free classes have a minimum number of
 * students and can accept new students within certain limits.
 *
 * @param it_count An iterator pointing to class quantity information.
 * @return A list of valid free class codes.
 */
std::list<std::string> valideFreeClass(
    std::map<std::string, std::vector<classQtd>>::iterator it_count) {
  int min = INT_MAX;
  std::list<std::string> free_classes;

  // first verify the class with the minimum number of students
  for (auto &classe : it_count->second) {
    if (classe.qtd < min) {
      min = classe.qtd;
    }
  }
  // then verify if the class is able to accept new students and add to the
  // list
  for (auto &classe : it_count->second) {
    if (!(classe.qtd + 1 - min > equilibre) && classe.qtd + 1 <= max_students) {
      free_classes.push_back(classe.classCode);
    }
  }

  // return list
  return free_classes;
}

// O(log(n) + m)
// n = number of UCs
// m = number of free classes

/**
 * @brief Verify class code for availability.
 *
 * This function checks whether a given class code in the context of a specific
 * UC code is available and can accept new students. It uses the class quantity
 * information to determine availability.
 *
 * @param classCode The class code to verify.
 * @param ucCode The UC code associated with the class.
 * @param count A map of class quantity information.
 * @return True if the class code is available, else false.
 */
bool verifyClassCode(std::string classCode, std::string ucCode,
                     std::map<std::string, std::vector<classQtd>> &count) {
  auto it_count = count.find(ucCode);

  if (it_count != count.end()) {
    std::list<std::string> free_classes = valideFreeClass(it_count);
    for (auto it_list = free_classes.begin(); it_list != free_classes.end();
         it_list++) {
      if (*it_list == classCode) {
        return true;
      }
    }
  } else {
    std::cout << "Error in find uc" << std::endl;
  }
  return false;
}

// O(log(n) + m)
// n = number of UCs
// m = number of free classes
void printFreeClasses(std::string ucCode,
                      std::map<std::string, std::vector<classQtd>> &count) {

  auto it_count = count.find(ucCode);
  std::list<std::string> free_classes;

  if (it_count != count.end()) {
    free_classes = valideFreeClass(it_count);
    std::cout << "   Classes: " << std::endl;

    if (!free_classes.empty()) {
      for (auto it_list = free_classes.begin(); it_list != free_classes.end();
           it_list++) {
        std::cout << "      " << *it_list << std::endl;
      }
    } else {
      std::cout << "      No classes available" << std::endl;
    }
  } else {
    std::cout << " Uc not found" << std::endl;
  }
}

// orderStudentClass:
// O(m*log(n)*k)
// n = number of UCs
// m = number of classes
// k = number of type of classes (T,TP)

// O(m*k) 
// m = number of classes
// k = number of type of classes (T,TP)

/**
 * @brief Print available free classes for a specific UC.
 *
 * This function identifies and prints the class codes that are available for
 * enrollment within a given UC, based on class quantity information.
 *
 * @param ucCode The UC code for which to find available classes.
 * @param count A map of class quantity information.
 */
void printStudentSchedules(std::map<std::string, myStudent>::iterator &it,
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
