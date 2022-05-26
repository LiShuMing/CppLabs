//
// Created by lishuming on 2020/7/25.
//
#include "boost_lab.h"

void BoostLab::TestSmartPtr() {
  START_FUNCTION

  boost::shared_ptr<A> pA(new A);

  std::cout << pA.get() << std::endl;

  boost::shared_ptr<A> pB(pA);

  std::cout << pA.get() << std::endl;
  std::cout << pB.get() << std::endl;
  END_FUNCTION
}

void BoostLab::TestTime() {
  START_FUNCTION

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
  END_FUNCTION
}
