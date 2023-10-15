#include <iostream>
#include <vector>

int menuPrincipal();
int menuSub();
int menuRequests();

void errorMessage();
void checkError(int n);

void dbStudents(int submenu);
void dbUcs(int submenu);
void dbClasses(int submenu);

void requests(int n);

void menu() {
  int menu = 0;
  int flag = 0;
  int subflag = 0;

  system("clear");
  std::cout << "------------ Welcome to our app :) ------------" << std::endl;
  std::cout << "| 1) See database                             |" << std::endl;
  std::cout << "| 2) Change database                          |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> menu;

  checkError(menu);

  if (menu == 1) {
    flag = menuPrincipal();
    subflag = menuSub();
  } else {
    flag = 4;
    subflag = menuRequests();
  }

  checkError(flag);
  checkError(subflag);

  switch (flag) {
  case 1:
    dbStudents(subflag);
    break;
  case 2:
    dbUcs(subflag);
    break;
  case 3:
    dbClasses(subflag);
    break;
  case 4:
    requests(subflag);
    break;
  default:
    errorMessage();
    break;
  }
}