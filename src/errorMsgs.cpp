#include <iostream>
#include <string>

void errorMessage() {
  std::cout << "ERROR: Invalid choice." << std::endl;
  exit(0);
}

void errorCheck(int n) {
  if (n == 0) {
    std::cout << "ERROR: Invalid number" << std::endl;
    exit(0);
  }
}

void errorMessageFile() {
  std::cerr << "Error: Could not open the file." << std::endl;
  exit(0);
}

void errorMessageLine(std::string line) {
  std::cerr << "Error: Invalid data format in line: " << line << std::endl;
  exit(0);
}

void workingMessage() {
  std::cout << "WARNING: Function not done yet." << std::endl;
}