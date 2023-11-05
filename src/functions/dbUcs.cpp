#include "dbUcs.h"

/**
 * @brief Compare two myUc objects by their class codes in ascending order.
 * @param uc1 The first myUc object to compare.
 * @param uc2 The second myUc object to compare.
 * @return True if 'uc1' class code is less than 'uc2' class code, otherwise
 * false.
 */
bool compareClassesCodeAsc(const myUc &uc1, const myUc &uc2) {
  return uc1.getClassCode() < uc2.getClassCode();
}

/**
 * @brief Compare two myUc objects by their UC codes in ascending order.
 * @param uc1 The first myUc object to compare.
 * @param uc2 The second myUc object to compare.
 * @return True if 'uc1' UC code is less than 'uc2' UC code, otherwise false.
 */
bool compareUcsCodeASC(const myUc &uc1, const myUc &uc2) {
  return uc1.getUcCode() < uc2.getUcCode();
}

/**
 * @brief Compare two myUc objects by their UC codes in descending order.
 * @param uc1 The first myUc object to compare.
 * @param uc2 The second myUc object to compare.
 * @return True if 'uc1' UC code is greater than 'uc2' UC code, otherwise false.
 */
bool compareClassesCodeDesc(const myUc &uc1, const myUc &uc2) {
  return uc1.getClassCode() > uc2.getClassCode();
}

/**
 * @brief Compare two myUc objects by their UC codes in descending order.
 * @param uc1 The first myUc object to compare.
 * @param uc2 The second myUc object to compare.
 * @return True if 'uc1' UC code is greater than 'uc2' UC code, otherwise false.
 */
bool compareUcsCodeDesc(const myUc &uc1, const myUc &uc2) {
  return uc1.getUcCode() > uc2.getUcCode();
}

/**
 * @brief Filters UC information.
 * @param n Number representing the filter.
 * @param str Search string.
 * @param ucs Vector of UCs to be filtered.
 * @return std::vector<myUc> Vector of filtered UCs.
 */
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

/**
 * @brief Sorts UC information.
 * @param n Number representing the sorting criterion.
 * @param ucs Vector of UCs to be sorted.
 * @return std::vector<myUc> Vector of sorted UCs.
 */
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

/**
 * @brief Selects UCs on the provided code.
 * @param str Code of the UC to be selected.
 * @param ucs Vector of UCs to be filtered.
 * @return std::vector<myUc> Vector of selected UCs.
 */
std::vector<myUc> selectUc(const std::string &str,
                           const std::map<std::string, myUc> &classes) {
  std::vector<myUc> selectedUcs;

  for (const auto &pair : classes) {
    auto ucObj = pair.second;

    if (ucObj.getUcCode() == str) {
      selectedUcs.push_back(ucObj);
    }

    return selectedUcs;
  }
}