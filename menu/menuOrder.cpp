#include <iostream>

int menuOrder() {
  int suborder = 0;

  std::cout << "-----------------------------------------------" << std::endl;

  std::cout << "1) Sort alphabetically" << std::endl;
  std::cout << "2) Sort by year" << std::endl;
  // cout << "3) Sort by number" <<std::endl;
  std::cout << "Choose an option: ";

  std::cin >> suborder;

  // When user inserts an invalid integer or a not integer.
  if (suborder == 0) {
    std::cout << "ERROR: Invalid number" << std::endl;
    exit(0);
  }

  std::cout << "-----------------------------------------------" << std::endl;

  return suborder;
}