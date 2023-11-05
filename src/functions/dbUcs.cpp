#include "dbUcs.h"

bool compareClassesCodeAsc(const myUc &uc1, const myUc &uc2) {
  return uc1.getClassCode() < uc2.getClassCode();
}
bool compareUcsCodeASC(const myUc &uc1, const myUc &uc2) {
  return uc1.getUcCode() < uc2.getUcCode();
}
bool compareClassesCodeDesc(const myUc &uc1, const myUc &uc2) {
  return uc1.getClassCode() > uc2.getClassCode();
}
bool compareUcsCodeDesc(const myUc &uc1, const myUc &uc2) {
  return uc1.getUcCode() > uc2.getUcCode();
}

std::vector<myUc> filterInfoUc(int n, std::string str, std::vector<myUc> &ucs) {
  std::vector<myUc> filterUc;
  switch (n) {
  case 1:
    // Filter by Uc Code
    for (const auto &uc : ucs) {
      if (uc.getUcCode() == str) {
        filterUc.push_back(uc);
      }
    }
    break;
  case 2:
    // Filter by Class Code
    for (const auto &uc : ucs) {
      for (const auto &classInfo : uc.getClassInfoVec()) {
        if (classInfo.code == str) {
          filterUc.push_back(uc);
          break;
        }
      }
    }
    break;
  default:
    errorMessage();
    break;
  }
  return filterUc;
}

std::vector<myUc> orderInfoUc(int n, std::vector<myUc> &ucs) {

  switch (n) {
  case 1:
    // Order by Uc Code Asc
    std::sort(ucs.begin(), ucs.end(), compareUcsCodeASC);
    break;
  case 2:
    // Order by Uc Code Desc
    std::sort(ucs.begin(), ucs.end(), compareUcsCodeDesc);
    break;
  case 3:
    // Order by Class Code Asc
    std::sort(ucs.begin(), ucs.end(), compareClassesCodeAsc);
    break;
  case 4:
    // Order by Class Code Desc
    std::sort(ucs.begin(), ucs.end(), compareClassesCodeDesc);
    break;
  default:
    errorMessage();
    break;
  }
  return ucs;
}

std::vector<myUc>
selectUc(const std::string &str,
         const std::map<std::string, std::vector<myUc>> &ucs) {

  auto it = ucs.find(str);
  if (it != ucs.end()) {
    return it->second;
  }
  return std::vector<myUc>();
}
