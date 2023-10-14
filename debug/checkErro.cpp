#include <iostream>

void checkError(int n) {
  if (n == 0) {
    std::cout << "ERROR: Invalid number" << std::endl;
    exit(0);
  }
}