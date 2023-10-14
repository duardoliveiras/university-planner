#include <iostream>

void checkError(int n);
void errorMessage();

int menuInfo(int n) {
  int info = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  // students
  switch (n) {
  case 1:
    std::cout << "1) Insert student code: " << std::endl;
    std::cout << "1) Insert student name: " << std::endl;
    // maybe acrescentar mais funcoes
    break;
  case 2:
  case 3:
    std::cout << "1) Insert uc code" << std::endl;
    std::cout << "1) Insert class code" << std::endl;
    // maybe acrescentar mais funcoes order
    break;
  default:
    errorMessage();
    break;
  }

  std::cin >> info;

  checkError(info);

  return info;
}