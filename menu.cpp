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

  int flag = 0;
  int subflag = 0;

  system("clear");

  flag = menuPrincipal();

  checkError(flag);

  if (flag == 4) {
    subflag = menuRequests();
  } else {
    subflag = menuSub();
  }

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
  default:
    errorMessage();
    break;
  }
}