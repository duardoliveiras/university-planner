#include <iostream>
#include <vector>

using namespace std;

void dbStudents(int submenu, int order);
void dbUcs(int submenu, int order);
void dbClasses(int submenu, int order);

void menu() {

  int flag = 0;
  int subflag = 0;
  int suborder = 0;

  system("clear");

  // principal menu
  cout << "------------ Welcome to our app :) ------------" << endl;

  cout << "1) Students" << endl;
  cout << "2) Classes" << endl;
  cout << "3) UC's" << endl;
  cout << "Choose an option: ";
  cin >> flag;

  // When user inserts an invalid integer or a not integer.
  if(flag==0) {
    cout << "ERROR: Invalid number" << endl;
    exit(0);
  }


  // submenu menu
  cout << "-----------------------------------------------" << endl; 

  cout << "1) See all" << endl;
  cout << "2) See a particular group" << endl;
  cout << "3) See one" << endl;
  cout << "Choose an option: ";
  cin >> subflag;

  // When user inserts an invalid integer or a not integer.
  if(subflag==0) {
    cout << "ERROR: Invalid number" << endl;
    exit(0);
  }
  

  // suborder menu
  cout << "-----------------------------------------------" << endl; 

  cout << "g1) Sort alphabetically" << endl; 
  cout << "2) Sort by year" << endl;
  //cout << "3) Sort by number" << endl;
  cout << "Choose an option: ";
  
  cin >> suborder;

  // When user inserts an invalid integer or a not integer.
  if(suborder==0) {
    cout << "ERROR: Invalid number" << endl;
    exit(0);
  }

  cout << "-----------------------------------------------" << endl; 


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
      cout << "ERROR: Invalid choice." << endl;
      break;
  }
 }