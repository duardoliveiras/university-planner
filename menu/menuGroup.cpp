#include <iostream>

void checkError(int n);

int menuOrder(int flag) {
  int group = 0;

  std::cout << "-----------------------------------------------" << std::endl;

  // students
  switch (flag) {
  case 1:
    std::cout << "1) Sort by name alphabetically ascending" << std::endl;
    // maybe acrescentar mais funcoes order
    break;
  case 2:
    std::cout << "1) Sort by class code" << std::endl;
    // maybe acrescentar mais funcoes order
    break;
  case 3:
    std::cout << "1) Sort by uc code" << std::endl;
    // maybe acrescentar mais funcoes order
  default:
    std::cout << "ERROR: Invalid choice." << std::endl;
    break;
  }

  std::cout << "Choose an option: ";
  std::cin >> group;
  
  checkError(group);

  return group;
}