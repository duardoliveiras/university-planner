#include <iostream>

void checkError(int n);

int menuOrder(int flag) {
  int info = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  // students
  switch (flag) {
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
    std::cout << "ERROR: Invalid choice." << std::endl;
    break;
  }

  std::cin >> info;
  
  checkError(info);

  return info;
}