#include <iostream>

#include "std/std_lab.h"
#include "boost/boost_lab.h"

int main() {
  std::cout << "Hello, World!" << std::endl;

  // TEST BOOST
  BoostLab boostLab;
  boostLab.TestTime();
  boostLab.TestSmartPtr();

  // TEST STD
  StdLab a;
  a.Test1();
  a.TestSmartPtr();

  return 0;
}