#include "menu.h"
#include "inputoutput/read.h"

std::map<std::string, std::vector<classQtd>> count;
std::map<std::string, myStudent> students;
std::map<std::string, std::vector<myUc>> ucs = readUcs(count);
std::map<std::string, myUc> classes = readSchedules();

std::stack<alter> stackAlter;

/**
 * @brief Update student information.
 *
 * This function updates the student information by reading data from a CSV file
 * and populating the 'students' map. It relies on the 'readStudents' function
 * to perform the data retrieval and update.
 */
void menuUpdate() { students = readStudents(count); }

/**
 * @brief Display the main menu and handle user options.
 *
 * This function displays the main menu of the application and handles user input to perform various actions.
 * Users can choose to view the database, change the database, perform a backup, or exit the application.
 */
void menu() {

  menuUpdate();
  system("clear");

  int flag = 0;

  std::cout << "------------ Welcome to our app :) ------------" << std::endl;
  std::cout << "| 1) See database                             |" << std::endl;
  std::cout << "| 2) Change database                          |" << std::endl;
  std::cout << "| 3) Backup                                   |" << std::endl;
  std::cout << "| 4) Exit                                     |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> flag;

  errorCheck(flag);

  switch (flag) {
  case 1:
    menuSeeDatabase();
    break;
  case 2:
    menuRequests();
    break;
  case 3:
    menuBackup();
    break;
  case 4:
    exit(0);
  default:
    errorMessage();
    break;
  }
}

/**
 * @brief Display options to view database information.
 *
 * This function presents a menu allowing the user to choose between viewing students, classes and UCs,
 * or their own schedules. It further provides options for selecting display filters, orders, and specific details.
 */
void menuSeeDatabase() {
  int flag = 0;
  int type;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) See Students                             |" << std::endl;
  std::cout << "| 2) See Classes and UC's                     |" << std::endl;
  std::cout << "| 3) See My Schedules                         |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> flag;

  errorCheck(flag);

  if (flag != 3) {
    type = selectType();
  }
  // std::cout << type;

  if (type == 1) {
    std::string code = selectCode();
    switch (flag) {
    case 1:
      menuStudents(code, type);
      break;
    case 2:
      menuUcs(code, type);
      break;
    default:
      errorMessage();
      break;
    }
  } else {
    int filter;
    int order;
    std::string value;
    if (type == 2) {
      filter = selectFilter();
      value = selectValue();
    }
    switch (flag) {
    case 1:
      order = selectOrderStudents();
      menuStudents(value, type, filter, order);
      break;
    case 2:
      order = selectOrderUcs();
      menuUcs(value, type, filter, order);
      break;
    case 3:
      menuStudentCode(4);
      break;
    default:
      errorMessage();
      break;
    }
  }
}

/**
 * @brief Display options to change the database.
 *
 * This function presents a menu allowing the user to choose between adding, removing, or switching database entries.
 * It further provides options for selecting specific actions and database entries.
 */
void menuRequests() {
  int flag = 0;

  system("clear");
  std::cout << "Change database" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Add                                      |" << std::endl;
  std::cout << "| 2) Remove                                   |" << std::endl;
  std::cout << "| 3) Switch                                   |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> flag;

  if (flag > 4 || flag == 0) {
    errorMessage();
  } else {
    menuStudentCode(flag);
  }
}

/**
 * @brief Enter a registration number and access student-related actions.
 *
 * This function prompts the user to enter their registration number and provides access to various student-related actions,
 * such as adding, removing, switching, or viewing schedules.
 *
 * @param flag An integer representing the selected action.
 */
void menuStudentCode(int flag) {
  std::string registrationNumber;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Enter your registration number: ";
  std::cin >> registrationNumber;

  auto it = students.find(registrationNumber);

  if (it == students.end()) {
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "| Registration number not found               |" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    std::cout << "| 1) Try again                                |" << std::endl;
    std::cout << "| 2) Exit                                     |" << std::endl;

    int flag2;

    std::cin >> flag2;

    switch (flag2) {
    case 1:
      system("clear");
      menuStudentCode(flag);
      break;
    case 2:
      exit(0);
    default:
      errorMessage();
      break;
    }

    menuRequests();
  } else {
    // printStudentClasses(it);
  }

  switch (flag) {
  case (1):
    menuAdd(it);
    break;
  case (2):
    menuRemove(it);
    break;
  case (3):
    menuSwitch(it);
    break;
  case (4):
    printStudentSchedules(it, classes);
    break;
  default:
    errorMessage();
  }
}

/**
 * @brief Display options to try the current operation again or exit.
 *
 * This function presents a menu allowing the user to choose between trying the current operation again
 * or exiting the menu for adding, removing, or switching database entries.
 *
 * @param menuType An integer representing the type of operation (1 for add, 2 for remove, 3 for switch).
 * @param it An iterator referring to a specific database entry.
 */
void menuTryAgain(int menuType,
                  std::map<std::string, myStudent>::iterator &it) {
  int flag;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Try again                                |" << std::endl;
  std::cout << "| 2) Exit                                     |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cin >> flag;

  switch (flag) {
  case 1:
    system("clear");
    if (menuType == 1) {
      menuAdd(it);
    } else if (menuType == 2) {
      menuRemove(it);
    } else if (menuType == 3) {
      menuSwitch(it);
    }
    break;
  case 2:
    exit(0);
  default:
    errorMessage();
    break;
  }
}

/**
 * @brief Remove a UC from a student's classes.
 *
 * This function allows the user to remove a specific UC from a student's class list.
 * It prompts the user to enter the UC code, removes it from the student's classes,
 * and provides success or error feedback.
 *
 * @param it An iterator referring to a specific student.
 */
void menuRemove(std::map<std::string, myStudent>::iterator &it) {
  printStudentClasses(it);
  std::string ucCode;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Enter UC code to remove " << std::endl;
  std::cin >> ucCode;
  std::cout << "-----------------------------------------------" << std::endl;

  bool remove = removeUcStudent(ucCode, it, stackAlter, count);

  if (remove) {
    printStudentClasses(it);
    std::cout << "\nRemovido com sucesso" << std::endl;
    saveOrReturn();
  } else {
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "UC code not found" << std::endl;
    menuTryAgain(2, it);
  }
}

/**
 * @brief Add a new class to a student's schedule.
 *
 * This function allows the user to add a new class to a student's schedule by providing the UC code
 * and the class code. It validates the student's schedule and class availability.
 *
 * @param it An iterator referring to a specific student.
 */
void menuAdd(std::map<std::string, myStudent>::iterator &it) {
  printStudentClasses(it);
  std::string ucCode;
  std::string classCode;
  bool check_class = false;

  // validates if the student is enrolled in more than 7 classes
  if (it->second.valideQtClasses()) {
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << " You have already 7 classes" << std::endl;
  } else {
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Enter UC code to see all classes: " << std::endl;
    std::cin >> ucCode;

    if (!verifyUcCode(ucCode, it)) {
      // checks if ucCode exists
      auto it_uc = ucs.find(ucCode);

      if (it_uc == ucs.end()) {
        std::cout << "-----------------------------------------------"
                  << std::endl;
        std::cout << "UC code not found" << std::endl;
        menuTryAgain(1, it);

      } else {
        std::cout << "-----------------------------------------------"
                  << std::endl;
        std::cout << "Uc. Code: " << it_uc->first << std::endl;

        printFreeClasses(ucCode, count);
        std::cout << "-----------------------------------------------"
                  << std::endl;
        std::cout << "Enter class code to add: " << std::endl;
        std::cin >> classCode;

        check_class = verifyClassCode(classCode, ucCode, count);

        if (check_class) {
          // validates that the class chosen by the student does not conflict
          // with the schedule of other classes
          bool validate = valideNewClass(ucCode, classCode, it, classes);

          if (!validate) {
            addClassStudent(ucCode, classCode, it, stackAlter);
            printStudentClasses(it);
            std::cout << "\nSucessfully added" << std::endl;

            saveOrReturn();
          }
        } else {
          std::cout << "-----------------------------------------------"
                    << std::endl;
          std::cout << "Class code not found" << std::endl;
          menuTryAgain(1, it);
        }
      }
    } else {
      std::cout << "-----------------------------------------------"
                << std::endl;
      std::cout << "You are already enrolled in this UC" << std::endl;
      menuTryAgain(1, it);
    }
  }
}

/**
 * @brief Perform a switch operation for a student's schedule.
 *
 * This function allows the user to perform switching operations for a student's schedule, such as
 * switching UCs or classes within a specific UC. It validates the student's current schedule
 * and class availability for the switch.
 *
 * @param it An iterator referring to a specific student.
 */
void menuSwitch(std::map<std::string, myStudent>::iterator &it) {
  printStudentClasses(it);
  std::string ucCode, classCode;
  int flag;
  auto it_uc = ucs.begin();
  std::list<std::string> free_classes;
  bool validate = false;
  bool check_class = false;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Switch UC                                |" << std::endl;
  std::cout << "| 2) Switch Class                             |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cin >> flag;

  switch (flag) {
  case (1):
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Enter UC code to remove: " << std::endl;
    std::cin >> ucCode;

    if (verifyUcCode(ucCode, it)) {

      std::cout << "-----------------------------------------------"
                << std::endl;
      std::cout << "Enter UC code to add: " << std::endl;
      std::cin >> ucCode;

      it_uc = ucs.find(ucCode);

      if (it_uc != ucs.end()) {

        printFreeClasses(ucCode, count);

        std::cout << "-----------------------------------------------"
                  << std::endl;
        std::cout << "Enter class code to add: " << std::endl;
        std::cin >> classCode;

        check_class = verifyClassCode(classCode, ucCode, count);

        if (check_class) {
          validate = valideNewClass(ucCode, classCode, it, classes);
          if (!validate) {
            removeUcStudent(ucCode, it, stackAlter, count);
            addClassStudent(ucCode, classCode, it, stackAlter);
            printStudentClasses(it);
            std::cout << "\nSuccessfully switched" << std::endl;
            saveOrReturn();
          }
        } else {
          std::cout << "-----------------------------------------------"
                    << std::endl;
          std::cout << "Class code not found" << std::endl;
          menuTryAgain(3, it);
        }
      } else {
        std::cout << "-----------------------------------------------"
                  << std::endl;
        std::cout << "UC code not found" << std::endl;
        menuTryAgain(3, it);
      }
    } else {
      std::cout << "-----------------------------------------------"
                << std::endl;
      std::cout << "You are not enrolled in this UC" << std::endl;
      menuTryAgain(3, it);
    }

    break;
  case (2):
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Enter UC to change class: " << std::endl;
    std::cin >> ucCode;

    if (verifyUcCode(ucCode, it)) {

      printFreeClasses(ucCode, count);
      std::cout << "-----------------------------------------------"
                << std::endl;
      std::cout << "Enter class code to add: " << std::endl;
      std::cin >> classCode;

      check_class = verifyClassCode(classCode, ucCode, count);

      if (check_class) {
        removeUcStudent(ucCode, it, stackAlter, count);
        validate = valideNewClass(ucCode, classCode, it, classes);
        if (!validate) {
          addClassStudent(ucCode, classCode, it, stackAlter);
          printStudentClasses(it);
          std::cout << "\nSuccessfully switched" << std::endl;
          saveOrReturn();
        }
      } else {
        std::cout << "-----------------------------------------------"
                  << std::endl;
        std::cout << "Class code not found" << std::endl;
        menuTryAgain(3, it);
      }
    } else {
      std::cout << "-----------------------------------------------"
                << std::endl;
      std::cout << "You are not enrolled in this UC" << std::endl;
      menuTryAgain(3, it);
    }
    break;
  default:
    errorMessage();
    break;
  }
}

/**
 * @brief Prompt the user to save changes or return to the previous menu.
 *
 * This function displays options for the user to either save their changes or return to the previous menu.
 * Users can select to save their actions, which may include adding or switching classes, or choose to return
 * without saving.
 */
void saveOrReturn() {
  int flag = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Save                                     |" << std::endl;
  std::cout << "| 2) Return                                   |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> flag;

  errorCheck(flag);

  switch (flag) {
  case 1:
    save();
    break;
  case 2:
    menuRequests();
    break;
  default:
    errorMessage();
    break;
  }
}

/**
 * @brief Save all changes to the student data and exit the program.
 *
 * This function saves all the changes made to the student data and exits the program. It uses the "keepAllChanges" function
 * to preserve any modifications, such as adding or switching classes, before exiting.
 */
void save() {
  keepAllChanges(students, stackAlter);
  exit(0);
}

/**
 * @brief Select a backup for viewing or restoration.
 *
 * @param type The type of operation (0 for viewing, 1 for restoration).
 *
 * @return The selected backup code to view or restore changes.
 */
int selectBackupCode(int type) {
  int cdBkp;

  if (type == 0) {
    std::cout << "Choose a backup to view changes: ";
  } else if (type == 1) {
    std::cout << "Choose a backup to restore: ";
  }

  std::cin >> cdBkp;

  return cdBkp;
}

/**
 * @brief Display the backup menu.
 *
 * This function lists all available backups, allows the user to select a backup to view changes,
 * and provides options to navigate between viewing changes and returning to the main menu.
 */
void menuBackup() {
  int flag;
  system("clear");
  listAllBackups();

  bool valide = printAllBackups();
  if (valide == true) {
    printChanges(selectBackupCode(0));
    menuChanges();
  } else {
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "| 1) - Main menu                              |" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cin >> flag;

    if (flag == 1) {
      menu();
    } else {
      errorMessage();
    }
  }
}

/**
 * @brief Restore data from a selected backup.
 *
 * This function allows the user to choose a backup to restore data from and initiates the restoration process.
 * After restoring the data, the user is returned to the main menu.
 */
void restoreBackup() {
  backupFile(selectBackupCode(1));
  menu();
}

/**
 * @brief Display menu options for handling backup changes.
 *
 * This function presents menu options for the user to manage backup changes, including returning to the previous menu,
 * going back to the main menu, or restoring data from a selected backup.
 */
void menuChanges() {

  int flag;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Return                                   |" << std::endl;
  std::cout << "| 2) Main menu                                |" << std::endl;
  std::cout << "| 3) Restore                                  |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;

  std::cin >> flag;

  switch (flag) {
  case (1):
    menuBackup();
    break;
  case (2):
    menu();
    break;
  case (3):
    restoreBackup();
    break;
  default:
    errorMessage();
    break;
  }
}

/**
 * @brief Prompt the user to select the sorting order for students.
 *
 * This function displays a menu to allow the user to choose the sorting order for the list of students.
 *
 * @return An integer representing the selected sorting order (1: ascending by student code, 2: descending by student code,
 * 3: ascending by student name, 4: descending by student name).
 */
int selectOrderStudents() {
  int flag = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Sort by student code asc                 |" << std::endl;
  std::cout << "| 2) Sort by student code desc                |" << std::endl;
  std::cout << "| 3) Sort by student name asc                 |" << std::endl;
  std::cout << "| 4) Sort by student name desc                |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  // add more order like - nº ucs,
  std::cout << "Choose an option: ";
  std::cin >> flag;

  errorCheck(flag);

  return flag;
}

/**
 * @brief Prompt the user to select the sorting order for UCs.
 *
 * This function displays a menu to allow the user to choose the sorting order for the list of UCs.
 *
 * @return An integer representing the selected sorting order (1: ascending by UC code, 2: descending by UC code,
 * 3: ascending by class code, 4: descending by class code).
 */
int selectOrderUcs() {
  int flag = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Sort by uc code asc                      |" << std::endl;
  std::cout << "| 2) Sort by uc code desc                     |" << std::endl;
  std::cout << "| 3) Sort by class code asc                   |" << std::endl;
  std::cout << "| 4) Sort by class code desc                  |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  // add more order like - nº ucs,
  std::cout << "Choose an option: ";
  std::cin >> flag;

  errorCheck(flag);

  return flag;
}

/**
 * @brief Prompt the user to select the viewing type.
 *
 * This function displays a menu to allow the user to choose the type of data viewing.
 *
 * @return An integer representing the selected viewing type (1: See one, 2: See a particular group, 3: See all).
 */
int selectType() {
  int flag = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) See one                                  |" << std::endl;
  std::cout << "| 2) See a particular group                   |" << std::endl;
  std::cout << "| 3) See all                                  |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;

  std::cout << "Choose an option: ";
  std::cin >> flag;
  errorCheck(flag);

  return flag;
}

/**
 * @brief Prompt the user to enter a code for searching.
 *
 * This function displays a prompt to the user and collects a code to use for searching data.
 *
 * @return A string containing the entered code for searching.
 */
std::string selectCode() {
  std::string str;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Search by code                           |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Enter the code: ";
  std::cin >> str;
  // errorcheck (str)

  return str;
}

/**
 * @brief Prompt the user to select a filter for data search.
 *
 * This function displays a menu to the user for selecting a filter to apply during data search.
 *
 * @return An integer representing the selected filter:
 *         - 1: Filter by UC Code
 *         - 2: Filter by Class Code
 */
int selectFilter() {
  int flag = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Uc Code                                  |" << std::endl;
  std::cout << "| 2) Class Code                               |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;

  std::cout << "Choose an option: ";
  std::cin >> flag;
  errorCheck(flag);

  return flag;
}

/**
 * @brief Prompt the user to enter a value for filtering data.
 *
 * This function prompts the user to enter a value to be used as a filter during data search.
 *
 * @return A string representing the user-entered value.
 */
std::string selectValue() {
  std::string str;

  std::cout << "Enter the value: ";
  std::cin >> str;
  // errorcheck (str)

  return str;
}

/**
 * @brief Display student data based on specified criteria.
 *
 * This function displays student data based on specified search criteria, filtering,
 * and ordering.
 *
 * @param str    A string containing the search term or code.
 * @param type   An integer indicating the search type: 1 for one student, 2 for a group, 3 for all students.
 * @param filter An integer specifying the filter type: 1 for UC code, 2 for class code (optional).
 * @param order  An integer indicating the order type (optional).
 */
void menuStudents(std::string str, int type, int filter, int order) {
  std::map<std::string, myStudent> oneStudent = students;
  std::vector<myStudent> data;

  for (const auto &studentPair : students) {
    data.push_back(studentPair.second);
  }

  if (type == 1) {
    oneStudent = selectStudent(str, oneStudent);
    printStudent(oneStudent);
  } else {
    if (type == 2) {
      data = filterInfoStudent(filter, str, data);
    }
    data = orderInfoStudent(order, data);
    printStudents(data);
  }
}


/**
 * @brief Display UC and class data based on specified criteria.
 *
 * This function displays UC and class data based on specified search criteria, filtering,
 * and ordering.
 *
 * @param str    A string containing the search term or code.
 * @param type   An integer indicating the search type: 1 for one UC and its classes, 2 for a group, 3 for all UCs.
 * @param filter An integer specifying the filter type: 1 for UC code, 2 for class code (optional).
 * @param order  An integer indicating the order type (optional).
 */
void menuUcs(std::string str, int type, int filter, int order) {
  std::vector<myUc> data;
  std::vector<myUc> oneUc;

  for (const auto &ucVectorPair : ucs) {
    for (const myUc &ucObj : ucVectorPair.second) {
      data.push_back(ucObj);
    }
  }

  if (type == 1) {
    oneUc = selectUc(str, classes);
    printUcClasses(oneUc);
  } else {
    if (type == 2) {
      data = filterInfoUc(filter, str, data);
    }
    data = orderInfoUc(order, data);
    printUcs(data);
  }
}