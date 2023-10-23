#include "dbUcs.h"

void menuUcs(std::string code, int type, int filter, int order) {
  // read Database
  std::vector<myUc> data = readAllUcs();

  if (type == 1) {
    data = selectUc(code, data);
  } else {
    if (type == 2) {
      data = filterInfoUc(filter, data);
    }
    data = orderInfoUc(order, data);
  }

  printUc(data);
}
std::vector<myUc> filterInfoUc(int n, std::vector<myUc> &myVector) {
  workingMessage();
  return myVector;
}
std::vector<myUc> orderInfoUc(int n, std::vector<myUc> &myVector) {
  std::vector<myUc> orderUc;

  switch (n) {
  case 1:
    // 2) Sort by uc code asc
    break;
  case 2:
    // 2) Sort by uc code desc
    break;
  case 3:
    // 3) Sort by class code asc
    break;
  case 4:
    // 4) Sort by class code desc
    break;
  case 5:
    // 5) Sort by year
    break;
  default:
    errorMessage();
    break;
  }

  return orderUc;
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
