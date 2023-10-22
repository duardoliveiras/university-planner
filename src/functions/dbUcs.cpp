#include <iostream>
#include <string>
#include <vector>

#include "dbUcs.h"

void menuUcs(std::string code, int type, int filter, int order) {
  // read Database
  std::vector<myUc> data = readAllUcs();

  if (type == 1) {
    selectUc(code, data);
  } else {
    if (type == 2) {
      filterInfoUc(filter, data);
    }
    orderInfoUc(order, data);
  }

  printUc(data);
}
