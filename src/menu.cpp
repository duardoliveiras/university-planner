#include <iostream>
#include <utility>
#include <vector>

#include "menu.h"

void menu() {
  int flag = 0;

  system("clear");

  std::cout << "------------ Welcome to our app :) ------------" << std::endl;
  std::cout << "| 1) See database                             |" << std::endl;
  std::cout << "| 2) Change database                          |" << std::endl;
  std::cout << "| 3) Exit                                     |" << std::endl;
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

  if (type == 1) {
    std::string code = selectCode();
    switch (flag) {
    case 1:
      menuStudents(code);
      break;
    case 2:
      menuClasses(code);
      break;
    case 3:
      menuUcs(code);
      break;
    default:
      errorMessage();
      break;
    }
  } else {
    if (type == 2) {
      int filter = selectFilter();
    }
    int order = selectOrder();
    switch (flag) {
    case 1:
      menuStudents(type, filter, order);
      break;
    case 2:
      menuClasses(type, filter, order);
      break;
    case 3:
      menuUcs(type, filter, order);
      break;
    default:
      errorMessage();
      break;
    }
  }
}

void menuRequests() {
  int flag = 0;

  std::cout << flag;
  // // necessary if user wants to change the classes by usercode
  // int code = 0;
  // std::vector<std::pair<int, int>> codes = {{0, 0}};

  // std::cout << "-----------------------------------------------" <<
  // std::endl; std::cout << "| 1) Enrollment                               |"
  // << std::endl; std::cout << "| 2) Removal |" << std::endl; std::cout << "|
  // 3) Changing                                 |" << std::endl; std::cout <<
  // "-----------------------------------------------" << std::endl; std::cout
  // << "Choose an option: "; std::cin >> flag;

  // errorCheck(flag);

  // code = menuCode();

  // errorCheck(code);

  // requests(flag, code);
}

int selectOrder() {
  int flag = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Sort alphabetic asc                      |" << std::endl;
  std::cout << "| 2) Sort alphabetic desc                     |" << std::endl;
  std::cout << "| 3) Sort by code                             |" << std::endl;
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
  // add error check
  return str;
}

int SelectFilter() {
  int flag = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Year 2019                                |" << std::endl;
  std::cout << "| 2) Year 2020                                |" << std::endl;
  // add more filter
  std::cout << "-----------------------------------------------" << std::endl;

  std::cout << "Choose an option: ";
  std::cin >> flag;
  errorCheck(flag);

  return flag;
}