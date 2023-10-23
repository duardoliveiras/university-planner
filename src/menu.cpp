#include "menu.h"

void menu() {
  int flag = 0;

  std::cout << "------------ Welcome to our app :) ------------" << std::endl;
  std::cout << "| 1) See database                             |" << std::endl;
  std::cout << "| 2) Change database                          |" << std::endl;
  std::cout << "| 3) Exit                                     |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> flag;
  // std::cout << flag;

  errorCheck(flag);

  switch (flag) {
  case 1:
    menuSeeDatabase();
    break;
  case 2:
    menuRequests();
    break;
  case 3:
    exit(0);
  default:
    errorMessage();
    break;
  }
}

void menuSeeDatabase() {
  int flag = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) See students                             |" << std::endl;
  std::cout << "| 2) See classes                              |" << std::endl;
  std::cout << "| 3) See UC's                                 |" << std::endl;
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
      menuClasses(code, type);
      break;
    case 3:
      menuUcs(code, type);
      break;
    default:
      errorMessage();
      break;
    }
  } else {
    int filter;
    std::string value;
    if (type == 2) {
      filter = selectFilter();
      value = selectValue();
    }
    int order = selectOrder();
    switch (flag) {
    case 1:
      menuStudents(value, type, filter, order);
      break;
    case 2:
      menuClasses(value, type, filter, order);
      break;
    case 3:
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
    std::string registrationNumber;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "| 1) Add                                      |" << std::endl;
    std::cout << "| 2) Remove                                   |" << std::endl;
    std::cout << "| 3) Switch                                   |" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cin >> flag;

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Enter your registration number: " << std::endl;
    std::cin >> registrationNumber;

    switch(flag){
        case(1):
            break;
        case(2):
            menuRemove(registrationNumber);
            break;
        case(3):
            break;
        default:
            errorMessage();
    }



}

void menuRemove(std::string registrationNumber){

    std::string ucCode;
    std::string classCode;

    menuStudents(registrationNumber, 1, 1, 1);
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Enter UC code to remove " << std::endl;
    std::cin >> ucCode;
    std::cout << "-----------------------------------------------" << std::endl;

    removeUcStudent(ucCode, registrationNumber);

    

}


int selectOrder() {
  int flag = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Sort by uc code asc                      |" << std::endl;
  std::cout << "| 2) Sort by uc code desc                     |" << std::endl;
  std::cout << "| 3) Sort by class code asc                   |" << std::endl;
  std::cout << "| 4) Sort by class code desc                  |" << std::endl;
  std::cout << "| 5) Sort by year asc                         |" << std::endl;
  std::cout << "| 6) Sort by year desc                        |" << std::endl;
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
  std::cout << "| 3) Year                                     |" << std::endl;
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