#include <iostream>

int menuSub() {
  int subflag = 0;

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
  
  return subflag;
}