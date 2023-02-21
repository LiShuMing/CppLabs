//
// Created by 李书明 on 2020/7/25.
//

#include "std_lab.h"

void StdLab::Test1() {
  if (std::is_same<decltype(NULL), decltype(0)>::value) {
    std::cout << "NULL == 0" << std::endl;
  } else {
    std::cout << "NULL != 0" << std::endl;
  }
}

void StdLab::TestSmartPtr() {
  std::unique_ptr<int> v = std::make_unique<int>(10);
  std::cout<< "v = " << *v.get() << ", address:" << v.get() << std::endl;
}
