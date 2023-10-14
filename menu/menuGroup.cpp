#include <iostream>

void checkError(int n);
void errorMessage();

int menuOrder(int n) {
  int group = 0;

  std::cout << "-----------------------------------------------" << std::endl;

  // students
  switch (n) {
  case 1:
    // fix posterior
    std::cout << "1) See all student with x year" << std::endl;
    // maybe acrescentar mais funcoes order
    break;
  case 2:
    // fix posterior
    std::cout << "1) See all all calsses of x uc" << std::endl;
    // maybe acrescentar mais funcoes order
    break;
  case 3:
    std::cout << "1) See all 1year ucs" << std::endl;
    std::cout << "2) See all 2year ucs" << std::endl;
    std::cout << "3) See all 3year ucs" << std::endl;

    // maybe acrescentar mais funcoes order
  default:
    errorMessage();
    break;
  }

  std::cout << "Choose an option: ";
  std::cin >> group;

  checkError(group);

  return group;
}