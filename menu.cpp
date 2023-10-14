#include <iostream>
#include <vector>

int menuPrincipal();
int menuSub();

void dbStudents(int submenu);
void dbUcs(int submenu);
void dbClasses(int submenu);

void menu() {

  int flag = 0;
  int subflag = 0;

  system("clear");

  flag = menuPrincipal();
  subflag = menuSub();

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
  default:
    std::cout << "ERROR: Invalid choice." << std::endl;
    break;
  }
}