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

bool compareClassesCode(const myUc &uc1, const myUc &uc2) {
  return uc1.getClassCode() < uc2.getClassCode();
}
bool compareUcsCode(const myUc &uc1, const myUc &uc2) {
  return uc1.getUcCode() < uc2.getUcCode();
}

std::vector<myUc> orderInfoUc(int n, std::vector<myUc> &ucs) {
  std::vector<myUc> orderUc = ucs;

  switch (n) {
  case 1:
    // 2) Sort by uc code asc
    std::sort(orderUc.begin(), orderUc.end(), compareUcsCode);
    break;
  case 2:
    // 2) Sort by uc code desc
    std::sort(orderUc.begin(), orderUc.end(), compareUcsCode);
    std::reverse(orderUc.begin(), orderUc.end());
    break;
  case 3:
    // 3) Sort by class code asc
    std::sort(orderUc.begin(), orderUc.end(), compareClassesCode);
    break;
  case 4:
    // 4) Sort by class code desc
    std::sort(orderUc.begin(), orderUc.end(), compareClassesCode);
    std::reverse(orderUc.begin(), orderUc.end());
    break;
  case 5:
    // 5) Sort by year asc
    std::sort(orderUc.begin(), orderUc.end(), compareUcsCode);
    break;
  case 6:
    // 6) Sort by year desc
    std::sort(orderUc.begin(), orderUc.end(), compareUcsCode);
    std::reverse(orderUc.begin(), orderUc.end());
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
