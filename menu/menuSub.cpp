#include <iostream>

void checkError(int n);

int menuSub() {
  int subflag = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "1) See one" << std::endl;
  std::cout << "2) See a particular group" << std::endl;
  std::cout << "3) See all" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> subflag;
  checkError(subflag);

  return subflag;
}