#include <iostream>

void checkError(int n);
void errorMessage();

int menuGroup(int n) {
  int group = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  switch (n) {
  case 1: // students
          // fix posterior
    std::cout << "| 1) See all student with x year              |" << std::endl;
    // maybe acrescentar mais funcoes order
    break;
  case 2: // classes
    // fix posterior
    std::cout << "| 1) See all classes of x uc                  |" << std::endl;
    // maybe acrescentar mais funcoes order
    break;
  case 3: // ucs
    std::cout << "| 1) See all ucs of 1year                     |" << std::endl;
    std::cout << "| 2) See all ucs of 2year                     |" << std::endl;
    std::cout << "| 3) See all ucs of 3year                     |" << std::endl;
    std::cout << "| 4) See number of students of x uc           |" << std::endl;

    // maybe acrescentar mais funcoes order
  default:
    errorMessage();
    break;
  }

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "Choose an option: ";
  std::cin >> group;

  checkError(group);

  return group;
}