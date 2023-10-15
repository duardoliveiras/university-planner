#include <iostream>

void checkError(int n);
void errorMessage();

int menuOrder(int n) {
  int suborder = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  switch (n) {
  case 1: // students
    std::cout << "| 1) Sort by name alphabetically ascending    |" << std::endl;
    std::cout << "| 2) Sort by name alphabetically descending   |" << std::endl;
    std::cout << "| 3) Sort by student code                     |" << std::endl;
    std::cout << "| 4) Sort by number of ucs                    |" << std::endl;
    // maybe acrescentar mais funcoes order
    break;
  case 2: // classes
    std::cout << "| 1) Sort by class code                       |" << std::endl;
    std::cout << "| 2) Sort by day of week                      |" << std::endl;
    std::cout << "| 3) Sort by time of day                      |" << std::endl;
    // maybe acrescentar mais funcoes order
    break;
  case 3: // ucs
    std::cout << "| 1) Sort by uc code                          |" << std::endl;
    std::cout << "| 2) Sort by class code                       |" << std::endl;
    // maybe acrescentar mais funcoes order
  default:
    errorMessage();
    break;
  }
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> suborder;

  checkError(suborder);

  return suborder;
}