#include <iostream>

using namespace std;

void dbStudents();
void dbUcs();
void dbClasses();
void dbOneUc();
void dbOneStudent();


void menu() {

  int flag;

  system("clear");

  cout << "------------ Welcome to our app :) ------------" << endl;

  cout << " 1) See all the students" << endl;
  cout << " 2) See all the ucs" << endl;
  cout << " 3) See all the classes" << endl;
  cout << " 4) See the schedule of a particular uc" << endl;
  cout << " 5) See the schedule of a particular student" << endl;
  cout << "-----------------------------------------------" << endl; 

  cout << "Choose an option: ";

  cin >> flag;
  if(flag==0) {
    cout << "ERROR: Invalid number" << endl;
    exit(0);
  }
  else {
    switch (flag) {
      case 1:
        dbStudents();
        break;
      case 2:
        dbUcs();
        break;
      case 3:
        dbClasses();
        break;    
      case 4:
        dbOneUc();
        break;
      case 5:
        dbOneStudent();
        break;
      default:
        cout << "ERROR: Invalid choice." << endl;
        break;
    }
  }
} 