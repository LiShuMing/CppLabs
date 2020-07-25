//
// Created by 李书明 on 2020/7/25.
//

#include "std_lab.h"

void StdLab::Test() {
  if (std::is_same<decltype(NULL), decltype(0)>::value) {
    std::cout << "NULL == 0" << std::endl;
  } else {
    std::cout << "NULL != 0" << std::endl;
  }
}
