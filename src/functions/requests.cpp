#include <iostream>

void workingMessage();
void addClass() { workingMessage(); }
void removeClass() { workingMessage(); }
void switchClass() { workingMessage(); }

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