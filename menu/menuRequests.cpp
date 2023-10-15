#include <iostream>

void checkError(int n);

int menuRequests() {
  int flag = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << "| 1) Add Class                                |" << std::endl;
  std::cout << "| 2) Remove Class                             |" << std::endl;
  std::cout << "| 3) Switch Class                             |" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;

  std::cout << "Choose an option: ";
  std::cin >> flag;

  checkError(flag);

  return flag;
}