#include "uc.h"

/**
 * @brief Constructor for the myUc class.
 * @param code UC's code.
 * @param name UC's name.
 */
myUc::myUc(const std::string &ucC, std::string &classC) {
  ucCode = ucC;
  classCode = classC;
}

/**
 * @brief Default constructor for the myUc class.
 *
 * This constructor initializes a myUc object with default values for
 * the UC code and class code.
 */
myUc::myUc() {
  ucCode = "";
  classCode = {};
}

/**
 * @brief Set the UC code for the myUc object.
 * @param n The new UC code to be set.
 */
void myUc::SetUc(std::string &ucC, std::string &classC) {
  ucCode = ucC;
  classCode = classC;
}

/**
 * @brief Set the UC code for the myUc object.
 * @param n The new UC code to be set.
 */
void myUc::setUcCode(std::string &n) { ucCode = n; }

/**
 * @brief Set the class code for the myUc object.
 * @param n The new class code to be set.
 */
void myUc::setClassCode(std::string &n) { classCode = n; }

/**
 * @brief Get the UC code for the myUc object.
 * @return The UC code.
 */
std::string myUc::getUcCode() const { return ucCode; }

/**
 * @brief Get the class code for the myUc object.
 * @return The class code.
 */
std::string myUc::getClassCode() const { return classCode; }

/**
 * @brief Returns a vector of classInfo associated with this UC.
 *
 * This function iterates through the classInfo (classes) associated with this
 * UC and collects the classInfo of each class in the classInfo vector.
 *
 * @return A vector of classInfo containing the classInfo associated with the
 * UC.
 */
std::vector<classInfo> myUc::getClassInfoVec() const { return classInfoVec; }

/**
 * @brief Adds a class to the classInfo vector.
 *
 * This function adds a class to the classInfo vector.
 *
 * @param code The class code to be added.
 */
void myUc::addClass(const std::string &code) { classCode = code; }

/**
 * @brief Adds a class to the classInfo vector.
 *
 * This function adds a class to the classInfo vector.
 *
 * @param code The class code to be added.
 */
void myUc::addClassInfo(std::string type, std::string day, int dayInt,
                        double startTime, double duration) {
  classInfo newClassInfo;
  newClassInfo.type = type;
  newClassInfo.day = day;
  newClassInfo.dayInt = dayInt;
  newClassInfo.startTime = startTime;
  newClassInfo.duration = duration;

  classInfoVec.push_back(newClassInfo);
}

/**
 * @brief Adds a class to the classInfo vector.
 *
 * This function adds a class to the classInfo vector.
 *
 * @param code The class code to be added.
 */
bool myUc::compareUcCode(const myUc &a, const myUc &b) {
  return a.ucCode < b.ucCode;
}