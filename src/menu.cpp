#include "menu.h"
#include "inputoutput/read.h"

std::map<std::string, std::vector<classQtd>> count;
std::map<std::string, myStudent> students = readStudents(count);
std::map<std::string, myUc> ucs = readUcs(count);
std::map<std::string, myUc> classes = readSchedules();
std::stack<alter> stackAlter;

void menu() {
  
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

void menuSeeDatabase() {
  int flag = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) See Students                             |" << std::endl;
  std::cout << "| 2) See Classes and UC's                     |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> flag;

  errorCheck(flag);

  int type = selectType();
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
    default:
      errorMessage();
      break;
    }
  }
}

void menuRequests() {
  int flag = 0;

  system("clear");
  std::cout << "Change database" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Add                                      |" << std::endl;
  std::cout << "| 2) Remove                                   |" << std::endl;
  std::cout << "| 3) Switch                                   |" << std::endl;
  std::cout << "| 4) View schedules                           |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cin >> flag;

  if (flag > 4 || flag == 0) {
    errorMessage();
  } else {
    menuStudentCode(flag);
  }
}

void menuStudentCode(int flag) {
  system("clear");
  std::string registrationNumber;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Enter your registration number: " << std::endl;
  std::cin >> registrationNumber;

  auto it = students.find(registrationNumber);

  if (it == students.end()) {
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Registration number not found" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    std::cout << "1 - Try again" << std::endl;
    std::cout << "2 - Exit" << std::endl;

    int flag2;

    std::cin >> flag2;

    switch (flag2) {
    case 1:
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
    std::cout << "-----------------------------------------------" << std::endl;
    printStudentClasses(it);
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
    showStudentClasses(it, classes);
    break;
  default:
    errorMessage();
  }
}

void menuRemove(std::map<std::string, myStudent>::iterator &it) {

    std::string ucCode;

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Enter UC code to remove " << std::endl;
    std::cin >> ucCode;
    std::cout << "-----------------------------------------------" << std::endl;

    bool remove = removeUcStudent(ucCode, it, stackAlter, count); 

    if(remove){
      printStudentClasses(it);
      std::cout<< "\nRemovido com sucesso" << std::endl;
      saveOrReturn();
    }else{
      std::cout << "-----------------------------------------------" << std::endl;
      std::cout << "Error in remove class" << std::endl;
    }
}

void menuAdd(std::map<std::string, myStudent>::iterator &it) {

  std::string ucCode;
  std::string classCode;
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

        menuRequests();
      } else {
        std::cout << "-----------------------------------------------"
                  << std::endl;
        std::cout << "Uc. Code: " << it_uc->second.getUcCode() << std::endl;

        printFreeClasses(ucCode, count);

        std::cout << "-----------------------------------------------"
                  << std::endl;
        std::cout << "Enter class code to add: " << std::endl;

        std::cin >> classCode;

        // validates that the class chosen by the student does not conflict with
        // the schedule of other classes
        bool validate = valideNewClass(ucCode, classCode, it, classes);

        if (!validate) {
          addClassStudent(ucCode, classCode, it, stackAlter);
          printStudentClasses(it);
          std::cout << "\nSucessfully added" << std::endl;

          saveOrReturn();
        }
      }
    } else {
      std::cout << "-----------------------------------------------"
                << std::endl;
      std::cout << "You are already enrolled in this UC" << std::endl;

      int flag;
      std::cout << "-----------------------------------------------"
                << std::endl;
      std::cout << "1 - Add another class" << std::endl;
      std::cout << "2 - Exit" << std::endl;
      std::cin >> flag;

      switch (flag) {
      case (1):
        system("clear");
        menuAdd(it);
        break;
      case (2):
        exit(0);
      default:
        errorMessage();
        break;
      }
    }
  }
}

void menuSwitch(std::map<std::string, myStudent>::iterator &it) {

  std::string ucCode, classCode;
  int flag;
  bool validate = false;

  printStudentClasses(it);

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
    removeUcStudent(ucCode, it, stackAlter, count);
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Enter UC code to add: " << std::endl;
    std::cin >> ucCode;

    printFreeClasses(ucCode, count);

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Enter class code to add: " << std::endl;

    std::cin >> classCode;

    validate = valideNewClass(ucCode, classCode, it, classes);

    if (!validate) {
      addClassStudent(ucCode, classCode, it, stackAlter);
      printStudentClasses(it);
      std::cout << "\nSuccessfully switched" << std::endl;

      saveOrReturn();
    }
    break;

  case (2):
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Enter UC to change class: " << std::endl;
    std::cin >> ucCode;
    printFreeClasses(ucCode, count);

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Enter class code to add: " << std::endl;
    std::cin >> classCode;

    removeUcStudent(ucCode, it, stackAlter, count);

    validate = valideNewClass(ucCode, classCode, it, classes);

    if (!validate) {
      addClassStudent(ucCode, classCode, it, stackAlter);
      printStudentClasses(it);
      std::cout << "\nSuccessfully switched" << std::endl;

      saveOrReturn();
    }
    break;

  default:
    errorMessage();
    break;
  }
}

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

void save() {
  keepAllChanges(students, stackAlter);
  exit(0);
}

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

void menuBackup() {
  system("clear");
  listAllBackups();
  printAllBackups();

  listChanges(selectBackupCode(0));
  menuChanges();
}

void restoreBackup() {
  backupFile(selectBackupCode(1));
  menu();
}

void menuChanges() {

  int flag;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "|1 - Return                                   |" << std::endl;
  std::cout << "|2 - Main menu                                |" << std::endl;
  std::cout << "|3 - Restore                                  |" << std::endl;
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

int selectFilter() {
  int flag = 0;

  // add more filter
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Uc Code                                  |" << std::endl;
  std::cout << "| 2) Class Code                               |" << std::endl;
  // 3) Year
  std::cout << "-----------------------------------------------" << std::endl;

  std::cout << "Choose an option: ";
  std::cin >> flag;
  errorCheck(flag);

  return flag;
}

std::string selectValue() {
  std::string str;

  std::cout << "Enter the value: ";
  std::cin >> str;
  // errorcheck (str)

  return str;
}

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
      str = selectValue();
      data = filterInfoStudent(filter, str, data);
    }
    data = orderInfoStudent(order, data);
    printStudents(data);
  }
}

void menuUcs(std::string str, int type, int filter, int order) {
  std::map<std::string, myUc> oneUc = ucs;
  std::vector<myUc> data;

  for (const auto &ucPair : ucs) {
    data.push_back(ucPair.second);
  }

  if (type == 1) {
    oneUc = selectUc(str, oneUc);
    printUc(oneUc);
  } else {
    if (type == 2) {
      str = selectValue();
      data = filterInfoUc(filter, str, data);
    }
    data = orderInfoUc(order, data);
    printUcs(data);
  }
}