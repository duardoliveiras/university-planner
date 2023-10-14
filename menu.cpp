#include <iostream>
#include <vector>

void dbStudents(int submenu, int order);
void dbUcs(int submenu, int order);
void dbClasses(int submenu, int order);

void menu() {

  int flag = 0;
  int subflag = 0;
  int suborder = 0;

  system("clear");

  // principal menu
  std::cout << "------------ Welcome to our app :) ------------" << std::endl;

  std::cout << "1) Students" << std::endl;
  std::cout << "2) Classes" << std::endl;
  std::cout << "3) UC's" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> flag;

  // When user inserts an invalid integer or a not integer.
  if(flag==0) {
    std::cout << "ERROR: Invalid number" << std::endl;
    exit(0);
  }


  // submenu menu
  std::cout << "-----------------------------------------------" <<std::endl; 

  std::cout << "1) See all" << std::endl;
  std::cout << "2) See a particular group" <<std::endl;
  std::cout << "3) See one" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> subflag;

  // When user inserts an invalid integer or a not integer.
  if(subflag==0) {
    std::cout << "ERROR: Invalid number" << std::endl;
    exit(0);
  }
  

  // suborder menu
  std::cout << "-----------------------------------------------" << std::endl; 

  std::cout << "1) Sort alphabetically" << std::endl; 
  std::cout << "2) Sort by year" << std::endl;
  //cout << "3) Sort by number" <<std::endl;
  std::cout << "Choose an option: ";
  
  std::cin >> suborder;

  // When user inserts an invalid integer or a not integer.
  if(suborder==0) {
    std::cout << "ERROR: Invalid number" << std::endl;
    exit(0);
  }

  std::cout << "-----------------------------------------------" << std::endl; 


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
     std::cout << "ERROR: Invalid choice." <<std::endl;
      break;
  }
 }