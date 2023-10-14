#include <iostream>
#include <string>

void checkError(int n);
void errorMessage();
std::string menuSelectInfo(int n);

std::string menuInfo(int n) {
  int info = 0;

  std::cout << "-----------------------------------------------" << std::endl;
  switch (n) {
  case 1: // students
    std::cout << "1) Insert student code" << std::endl;
    std::cout << "2) Insert student name" << std::endl;
    // maybe acrescentar mais funcoes
    break;
  case 2: // classes
  case 3: // ucs
    std::cout << "1) Insert uc code" << std::endl;
    std::cout << "2) Insert class code" << std::endl;
    // maybe acrescentar mais funcoes order
    break;
  default:
    errorMessage();
    break;
  }

  std::cout << "Choose an option: ";
  std::cin >> info;

  checkError(info);

  std::string selectInfo = menuSelectInfo(info);

  // should return info and the info that the user show and inputed
  return selectInfo;
}