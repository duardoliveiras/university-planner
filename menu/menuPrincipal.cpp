#include <iostream>

void checkError(int n);

int menuPrincipal() {
  int flag = 0;

  std::cout << "------------ Welcome to our app :) ------------" << std::endl;
  std::cout << "1) Students" << std::endl;
  std::cout << "2) Classes" << std::endl;
  std::cout << "3) UC's" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> flag;

  checkError(flag);

  return flag;
}