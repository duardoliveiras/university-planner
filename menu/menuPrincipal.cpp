#include <iostream>

void checkError(int n);

int menuPrincipal() {
  int flag = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) See students                             |" << std::endl;
  std::cout << "| 2) See classes                              |" << std::endl;
  std::cout << "| 3) See UC's                                 |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;

  std::cout << "Choose an option: ";
  std::cin >> flag;

  checkError(flag);

  return flag;
}