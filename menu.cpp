#include <iostream>
#include <utility>
#include <vector>

void errorMessage();
void errorCheck(int n);
void workingMessage();

void dbStudents(int submenu);
void dbUcs(int submenu);
void dbClasses(int submenu);

// menus inicialization
void menuSeeDatabase();
void menuRequests();
void menuStudents(int type, int order = 0);
void menuClasses(int type, int order = 0);
void menuUcs(int type, int order = 0);
void requests(int flag, int code);
int selectOrder();
int selectType();
int menuCode();

void requests(int n);

std::string menuSelectInfo(int n);

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
    switch (flag) {
    case 1:
      menuStudents(type);
      break;
    case 2:
      menuClasses(type);
      break;
    case 3:
      menuUcs(type);
      break;
    default:
      errorMessage();
      break;
    }
  } else {
    int order = selectOrder();

    switch (flag) {
    case 1:
      menuStudents(type, order);
      break;
    case 2:
      menuClasses(type, order);
      break;
    case 3:
      menuUcs(type, order);
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
