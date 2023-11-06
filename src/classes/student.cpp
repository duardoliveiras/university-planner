#include "student.h"

/**
 * @brief Constructor for the myStudent class.
 * @param code Student's code.
 * @param name Student's name.
 */
myStudent::myStudent(const std::string &sCode, const std::string &sName) {
  studentCode = sCode;
  studentName = sName;
}
/**
 * @brief Default constructor for the myStudent class.
 *
 * This constructor initializes a myStudent object with default values for
 * the student code and student name.
 */
myStudent::myStudent() {
  studentCode = "";
  studentName = "";
}

void myStudent::setStudent(std::string &sCode, std::string &sName) {
  studentCode = sCode;
  studentName = sName;
}

/**
 * @brief Set the student code for the myStudent object.
 * @param n The new student code to be set.
 */
void myStudent::setStudentCode(std::string &n) { studentCode = n; }

/**
 * @brief Set the student name for the myStudent object.
 * @param n The new student name to be set.
 */
void myStudent::setStudentName(std::string &n) { studentName = n; }

/**
 * @brief Get the student code for the myStudent object.
 * @return The student code.
 */
std::string myStudent::getStudentCode() const { return studentCode; }

/**
 * @brief Get the student name for the myStudent object.
 * @return The student name.
 */
std::string myStudent::getStudentName() const { return studentName; }

/**
 * @brief Returns a vector of UC codes associated with this student.
 *
 * This function iterates through the courses (UCs) associated with this student
 * and collects the UC codes of each course in the UC code vector.
 *
 * @return A vector of strings containing the UC codes associated with the
 * student.
 */
std::vector<std::string> myStudent::getUcCode() const {
  std::vector<std::string> ucCodes;
  for (const auto &uc : classes) {
    ucCodes.push_back(uc.getUcCode());
  }
  return ucCodes;
}

/**
 * @brief Returns a vector of class codes associated with this student.
 *
 * This function iterates through the courses (UCs) associated with this student
 * and collects the class codes of each course in the class code vector.
 *
 * @return A vector of strings containing the class codes associated with the
 * student.
 */
std::vector<std::string> myStudent::getClassCode() const {
  std::vector<std::string> classCodes;
  for (const auto &uc : classes) {
    std::vector<classInfo> classInfoVec = uc.getClassInfoVec();
    for (const auto &classInfo : classInfoVec) {
      classCodes.push_back(classInfo.code);
    }
  }
  return classCodes;
}

/**
 * @brief Gets a reference to the vector containing the student's classes.
 * @return A reference to a vector of ClassComp objects.
 */
std::vector<myUc> &myStudent::getClasses() const { return classes; }

/**
 * @brief Adds a class to the student's classes vector.
 * @param classe ClassComp object to be added.
 */
void myStudent::addClass(const myUc &myClass) { classes.push_back(myClass); }

/**
 * @brief Validates if the quantity of classes exceeds the limit.
 * @return True if the number of classes is greater than 7, false otherwise.
 */
bool myStudent::valideQtClasses() {
  if (classes.size() >= 7) {
    return true;
  }
  return false;
}
