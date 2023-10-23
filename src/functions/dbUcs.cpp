#include "dbUcs.h"

void menuUcs(std::string code, int type, int filter, int order) {
  // read Database
  std::vector<myUc> data = readAllUcs();

  if (type == 1) {
    data = selectUc(code, data);
  } else {
    if (type == 2) {
      // filterInfoUc(filter, data);
    }
    // orderInfoUc(order, data);
  }

  printUc(data);
}
std::vector<myUc> filterInfoUc(int n, std::vector<myUc> &myVector) {
  workingMessage();
  return myVector;
}
std::vector<myUc> orderInfoUc(int n, std::vector<myUc> &myVector) {
  workingMessage();
  return myVector;
}
std::vector<myUc> selectUc(std::string str, std::vector<myUc> &ucs) {
  std::vector<myUc> selectUc;

  for (const auto &myuc : ucs) {
    if (str == myuc.getUcCode()) {
      selectUc.push_back(myuc);
    }
  }

  return selectUc;
}
