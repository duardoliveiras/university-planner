#include <iostream>
#include <vector>

int menuOrder();
int menuPrincipal();
int menuSub();

void dbStudents(int submenu, int order);
void dbUcs(int submenu, int order);
void dbClasses(int submenu, int order);

void menu() {

  int flag = 0;
  int subflag = 0;
  int suborder = 0;

  system("clear");

  flag = menuPrincipal();
  subflag = menuSub();
  suborder = menuOrder();

  switch (flag) {
  case 1:
    dbStudents(subflag, suborder);
    break;
  case 2:
    dbUcs(subflag, suborder);
    break;
  case 3:
    dbClasses(subflag, suborder);
    break;
  default:
    std::cout << "ERROR: Invalid choice." << std::endl;
    break;
  }
}