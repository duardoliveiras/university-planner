#include <iostream>

using namespace std;

void dbStudents();
void dbUcs();
void dbClasses();
void dbOneUc();
void dbOneStudent();


void menu() {

  int flag;
  int idUc;
  char idStudent;

  cout << "--- Welcome to app :) ---" << endl;
  cout << "What would you like to do?" << endl;
  cout << "Press 0: See all the students" << endl;
  cout << "Press 1: See all the ucs" << endl;
  cout << "Press 2: See all the classes" << endl;
  cout << "Press 3: See the schedule of a particular uc" << endl;
  cout << "Press 4: See the schedule of a particular student" << endl;

  cin >> flag;
  system("clear");

  if(flag<0 && flag>4) cout << "ERROR: You insert an invalid number." << endl;
  else {
    switch (flag) {
      case 0:
        cout << "You pressed 0: to see all the students." << endl;
        dbStudents();
        break;
      case 1:
        cout << "You pressed 1: to see all the ucs." << endl;
        dbUcs();
        break;
      case 2:
        cout << "You pressed 2: to see all the classes." << endl;
        dbClasses();
        break;    
      case 3:
        cout << "You pressed 3: to see a particular uc." << endl;
        dbOneUc();
        break;
      case 4:
        cout << "You pressed 4: to see a particular student." << endl;
        dbOneStudent();
        break;
      default:
        cout << "ERROR: Invalid choice." << endl;
        break;
    }
  }
  

} 