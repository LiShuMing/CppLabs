#include <iostream>

#include <boost/algorithm/minmax.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

#include "std/std_lab.h"

namespace pt = boost::posix_time;

int main() {
  std::cout << "Hello, World!" << std::endl;

  // TEST BOOST
  pt::ptime now = pt::second_clock::local_time();
  printf("%s\t->\t%4d-%2d-%2d %2d:%2d:%2d\n",
         "date '+%Y-%m-%d %H:%M:%S'",
         (int)now.date().year(),
         (int)now.date().month(),
         (int)now.date().day(),
         (int)now.time_of_day().hours(),
         (int)now.time_of_day().minutes(),
         (int)now.time_of_day().seconds()
  );


  // TEST STD
  StdLab a;
  a.Test();

  return 0;
}