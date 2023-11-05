#include "dbStudents.h"

// O(1)
/**
 * @brief Function to compare students based on their codes in ascending order.
 *
 * @param student1 The first student to compare.
 * @param student2 The second student to compare.
 * @return Returns true if the code of the first student is less than that of the second.
 */
bool compareStudentsCodeAsc(const myStudent &student1,
                            const myStudent &student2) {
  return student1.getStudentCode() < student2.getStudentCode();
}
// O(1)
/**
 * @brief Function to compare students based on their codes in descending order.
 *
 * @param student1 The first student to compare.
 * @param student2 The second student to compare.
 * @return Returns true if the code of the first student is greater than that of the second.
 */
bool compareStudentsCodeDesc(const myStudent &student1,
                             const myStudent &student2) {
  return student1.getStudentCode() > student2.getStudentCode();
}
// O(1)
/**
 * @brief Function to compare students based on their names in ascending order.
 *
 * @param student1 The first student to compare.
 * @param student2 The second student to compare.
 * @return Returns true if the name of the first student is less than that of the second.
 */
bool compareStudentNameAsc(const myStudent &student1,
                           const myStudent &student2) {
  return student1.getStudentName() < student2.getStudentName();
}
// O(1)
/**
 * @brief Function to compare students based on their names in descending order.
 *
 * @param student1 The first student to compare.
 * @param student2 The second student to compare.
 * @return Returns true if the name of the first student is greater than that of the second.
 */
bool compareStudentNameDesc(const myStudent &student1,
                            const myStudent &student2) {
  return student1.getStudentName() > student2.getStudentName();
}

// O(n)
// n = number of lines in the file
/**
 * @brief Filter student information based on specified criteria.
 *
 * @param n Filter criterion: 1 for Uc Code, 2 for Class Code.
 * @param str Search string.
 * @param students Vector of students to filter.
 * @return Vector of students matching the criteria.
 */
std::vector<myStudent>
filterInfoStudent(int n, std::string str,
                  const std::vector<myStudent> &students) {
  std::vector<myStudent> filterStudents;
  switch (n) {
  case 1:
    // Filter by Uc Code
    for (const auto &student : students) {
      for (const auto &uc : student.getClasses()) {
        if (uc.getUcCode() == str) {
          filterStudents.push_back(student);
          break;
        }
      }
    }
    break;
  case 2:
    // Filter by Class Code
    for (const auto &student : students) {
      for (const auto &uc : student.getClasses()) {
        for (const auto &classInfo : uc.getClassInfoVec()) {
          if (classInfo.code == str) {
            filterStudents.push_back(student);
            break; // No need to check other class codes for this student
          }
        }
      }
    }
    break;
  default:
    errorMessage();
    break;
  }
  return filterStudents;
}

// O(n*log(n))
// n = number of lines in the file
/**
 * @brief Order a vector of students based on the specified criterion.
 *
 * @param n Ordering criterion: 1 for ascending Student Code, 2 for descending Student Code,
 * 3 for ascending Student Name, 4 for descending Student Name.
 * @param students Vector of students to be ordered.
 * @return Ordered vector of students based on the specified criterion.
 */
std::vector<myStudent> orderInfoStudent(int n,
                                        std::vector<myStudent> &students) {
  switch (n) {
  case 1:
    // Order by Student Code Asc
    std::sort(students.begin(), students.end(), compareStudentsCodeAsc);
    break;
  case 2:
    // Order by Student Code Desc
    std::sort(students.begin(), students.end(), compareStudentsCodeDesc);
    break;
  case 3:
    // Order by Student Name Asc
    std::sort(students.begin(), students.end(), compareStudentNameAsc);
    break;
  case 4:
    // Order by Student Name Desc
    std::sort(students.begin(), students.end(), compareStudentNameDesc);
    break;
  default:
    errorMessage();
    break;
  }

  return students;
}

// O(m)
// m = number of students
/**
 * @brief Select students from a map based on a given student code.
 *
 * @param str Student code to search for.
 * @param students Map of students to select from.
 * @return Map of selected students with matching student codes.
 */
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

// O(m*log(m))
// m = number of UCs of the student
/**
 * @brief Organize the classes of a student based on Uc Code in ascending order.
 *
 * @param it Iterator pointing to a student in the map of students.
 *
 * This function organizes the classes of a student in ascending order based on their Uc Codes.
 */
void organizerUcStudent(std::map<std::string, myStudent>::iterator &it) {

  std::sort(it->second.getClasses().begin(), it->second.getClasses().end(),
            myUc::compareUcCode);
}

// O(m)
// m = number of UCs of the student
/**
 * @brief Remove a specific Uc Code from a student's classes.
 *
 * @param ucCode Uc Code to be removed.
 * @param it Iterator pointing to a student in the map of students.
 * @param stackAlter Stack for recording changes.
 * @param count Map for tracking class counts.
 * @return Returns true if the Uc Code was successfully removed; otherwise, returns false.
 *
 * This function removes a specific Uc Code from a student's classes. It records the change in the stack
 * for later reference and updates the class count in the "count" map.
 */
bool removeUcStudent(std::string ucCode,
                     std::map<std::string, myStudent>::iterator &it,
                     std::stack<alter> &stackAlter,
                     std::map<std::string, std::vector<classQtd>> &count) {

  bool remove = false;
  for (unsigned i = 0; i < it->second.getClasses().size(); i++) {
    if (it->second.getClasses()[i].getUcCode() == ucCode) {
      stackAlter.push({it->second.getStudentCode(), it->second.getStudentName(),
                       "remove", ucCode,
                       it->second.getClasses()[i].getUcCode()});
      it->second.getClasses().erase(it->second.getClasses().begin() + i);
      remove = true;
      updateCountClasses(ucCode, it->second.getClasses()[i].getClassCode(),
                         count, 0);
    }
  }
  return remove;
}

// O(log(m))
// m = number of distinct student
/**
 * @brief Add a new class to a student's record.
 *
 * @param ucCode Uc Code of the new class.
 * @param classCode Class Code of the new class.
 * @param it Iterator pointing to a student in the map of students.
 * @param stackAlter Stack for recording changes.
 *
 * This function receives a reference to a student pointer and adds a new class to the student's record. It also organizes the classes, records the change in the stack, and updates the student's class list.
 */
void addClassStudent(std::string ucCode, std::string classCode,
                     std::map<std::string, myStudent>::iterator &it,
                     std::stack<alter> &stackAlter) {

  myUc classe(ucCode, classCode);
  it->second.getClasses().push_back(classe);
  organizerUcStudent(it);
  stackAlter.push({it->second.getStudentCode(), it->second.getStudentName(),
                   "add", ucCode, classCode});
}


// O(m*log(n)
// n = number of UCs
// m = number of classes

/**
 * @brief Update the class count tree by adding or removing a class.
 *
 * @param ucCode Uc Code associated with the class.
 * @param classCode Class Code to be added or removed.
 * @param count Map for tracking class counts.
 * @param type 1 for adding a class, 0 for removing a class.
 *
 * This function updates the class count in the "count" map by either adding or removing a class.
 */
void updateCountClasses(std::string ucCode, std::string classCode,
                        std::map<std::string, std::vector<classQtd>> &count,
                        int type) {

  auto it_count = count.find(ucCode);
  if (it_count != count.end()) {
    for (auto &classe : it_count->second) {
      if (classe.classCode == classCode) {
        if (type == 1) {
          classe.qtd++;
        } else {
          classe.qtd--;
        }
      }
    }
  }
}


// O(m*log(n)*k)
// n = number of UCs
// m = number of classes of the student
// k = number of type of classes (T,TP)

/**
 * @brief Validate the addition of a new class to a student's schedule.
 *
 * @param ucCode Uc Code of the class to be added.
 * @param classCode Class Code of the class to be added.
 * @param it Iterator pointing to a student in the map of students.
 * @param classes Map of classes to validate against.
 * @return Returns true if the addition of the class is valid, or false if it conflicts with the student's existing schedule.
 *
 * This function validates whether adding a new class to a student's schedule is compatible with their existing classes. It checks for schedule conflicts and ensures the class exists in the "classes" map.
 */
bool valideNewClass(std::string ucCode, std::string classCode,
                    std::map<std::string, myStudent>::iterator &it,
                    std::map<std::string, myUc> &classes) {

  // call function to order the
  // classes of the student by
  // int day
  std::map<int, std::set<classInfo>> orderClasses =
      orderStudentClass(it, classes);

  std::string value = ucCode + classCode;

  auto it_class = classes.find(value);

  if (it_class == classes.end()) {
    std::cout << "Error in "
                 "find class"
              << std::endl;
    return true;
  } else {
    // verify if has a class in
    // the same day and time
    for (const auto &class_info : it_class->second.getClassInfoVec()) {
      // get all classes of the
      // day of class
      const std::set<classInfo> &classesOfDay = orderClasses[class_info.dayInt];

      // and verify if the
      // student has a class in
      // the same time aula -> student classes
      // class_info -> class to add
      for (const auto &aula : classesOfDay) {

        if (aula.type != "T" && class_info.type != "T" &&
            class_info.startTime >= aula.startTime &&
            class_info.startTime < aula.startTime + aula.duration) {
          std::cout << "Error: "
                       "Incompatible"
                       " schedules"
                    << std::endl;
          return true;
        }
      }
    }
    return false;
  }
}

// O(m*log(n)*k)
// n = number of UCs
// m = number of classes
// k = number of type of classes (T,TP)
/**
 * @brief Organize a student's classes by day.
 *
 * @param it Iterator pointing to a student in the map of students.
 * @param classes Map of classes to organize.
 * @return Map of classes organized by day.
 *
 * This function organizes a student's classes by day and returns a map where classes are grouped by their respective days.
 */
std::map<int, std::set<classInfo>>
orderStudentClass(std::map<std::string, myStudent>::iterator &it,
                  std::map<std::string, myUc> &classes) {

  // map to order the classes
  // by day
  std::map<int, std::set<classInfo>> orderClasses;

  // for each class of the
  // student, search in the
  // class tree and add the
  // classInfo in the
  // orderClasses map
  for (const auto &classe : it->second.getClasses()) {
    std::string value = classe.getUcCode() + classe.getClassCode();

    // student one class
    // pointer, verify if the
    // class exists in the
    // class tree
    auto it_class = classes.find(value);

    // if the class does not
    // exist, print error
    if (it_class == classes.end()) {
      std::cerr << "Error in "
                   "find class"
                << std::endl;
    } else {
      // if exists, add the
      // classInfo in the
      // orderClasses map
      for (auto &classInfo : it_class->second.getClassInfoVec()) {
        classInfo.code = classe.getUcCode();
        orderClasses[classInfo.dayInt].insert(classInfo);
      }
    }
  }
  return orderClasses;
}

/**
 * @brief Convert a numeric day value to a corresponding day of the week string.
 *
 * @param day Numeric representation of a day (e.g., 2 for Monday).
 * @return Corresponding day of the week string.
 *
 * This function converts a numeric day value to a string representation of the corresponding day of the week.
 */
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

// O(m)
// m = number of classes of the student
/**
 * @brief Check whether a student is already enrolled in a UC class.
 *
 * @param ucCode Uc Code to check for enrollment.
 * @param it Iterator pointing to a student in the map of students.
 * @return Returns true if the student is already enrolled in a class with the specified Uc Code; otherwise, returns false.
 *
 * This function checks whether a student is already enrolled in a class with the specified Uc Code and returns true if a match is found, indicating a potential problem.
 */
bool verifyUcCode(std::string ucCode,
                  std::map<std::string, myStudent>::iterator &it) {

  for (const auto &classe : it->second.getClasses()) {
    if (classe.getUcCode() == ucCode) {
      return true;
    }
  }

  return false;
}