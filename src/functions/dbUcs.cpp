#include "dbUcs.h"

// std::vector<myUc> filterInfoUc(int n, std::string str, std::vector<myUc>
// &ucs) {
//   std::vector<myUc> filterUc;
//   switch (n) {
//   case 1:
//     // 1) Uc Code
//     for (const auto &myuc : ucs) {
//       if (str == myuc.getUcCode()) {
//         filterUc.push_back(myuc);
//       }
//     }
//     break;
//   case 2:
//     // 2) Class Code
//     // for (const auto &myuc : ucs) {
//     //   auto myuc.getClassCode();
//     //   // if (str == myuc.getClassCode()) {
//     //   //   filterUc.push_back(myuc);
//     //   // }(str ==
//     // }
//     break;
//   case 3:
//     // 3) Year
//     break;
//   default:
//     errorMessage();
//     break;
//   }
//   return filterUc;
// }

// bool compareClassesCode(const myUc &uc1, const myUc &uc2) {
//   return uc1.getClassCode() < uc2.getClassCode();
// }
// bool compareUcsCode(const myUc &uc1, const myUc &uc2) {
//   return uc1.getUcCode() < uc2.getUcCode();
// }

// std::vector<myUc> orderInfoUc(int n, std::vector<myUc> &ucs) {
//   std::vector<myUc> orderUc = ucs;

//   switch (n) {
//   case 1:
//     // 2) Sort by uc code asc
//     std::sort(orderUc.begin(), orderUc.end(), compareUcsCode);
//     break;
//   case 2:
//     // 2) Sort by uc code desc
//     std::sort(orderUc.begin(), orderUc.end(), compareUcsCode);
//     std::reverse(orderUc.begin(), orderUc.end());
//     break;
//   case 3:
//     // 3) Sort by class code asc
//     std::sort(orderUc.begin(), orderUc.end(), compareClassesCode);
//     break;
//   case 4:
//     // 4) Sort by class code desc
//     std::sort(orderUc.begin(), orderUc.end(), compareClassesCode);
//     std::reverse(orderUc.begin(), orderUc.end());
//     break;
//   case 5:
//     // 5) Sort by year asc
//     std::sort(orderUc.begin(), orderUc.end(), compareUcsCode);
//     break;
//   case 6:
//     // 6) Sort by year desc
//     std::sort(orderUc.begin(), orderUc.end(), compareUcsCode);
//     std::reverse(orderUc.begin(), orderUc.end());
//     break;
//   default:
//     errorMessage();
//     break;
//   }

//   return orderUc;
// }

// std::vector<myUc> selectUc(std::string str, std::vector<myUc> &ucs) {
//   std::vector<myUc> selectUc;

//   for (const auto &myuc : ucs) {
//     if (str == myuc.getUcCode()) {
//       selectUc.push_back(myuc);
//     }
//   }

//   return selectUc;
// }
