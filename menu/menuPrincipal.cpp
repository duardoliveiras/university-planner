#include <iostream>

int menuPrincipal() {
  int flag = 0;

  std::cout << "------------ Welcome to our app :) ------------" << std::endl;

  std::cout << "1) Students" << std::endl;
  std::cout << "2) Classes" << std::endl;
  std::cout << "3) UC's" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> flag;

  // When user inserts an invalid integer or a not integer.
  if (flag == 0) {
    std::cout << "ERROR: Invalid number" << std::endl;
    exit(0);
  }

  return flag;
}