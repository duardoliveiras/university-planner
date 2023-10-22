#include <iostream>

void workingMessage();
void addClass();
void removeClass();
void switchClass();

void requests(int n) {
  switch (n) {
  case 1:
    addClass();
  case 2:
    removeClass();
  case 3:
    switchClass();
  }
}