//
// Created by lishuming on 2020/7/25.
//

#ifndef CPPLABS_BOOST_LAB_H
#define CPPLABS_BOOST_LAB_H

#include <iostream>
#include <memory>

#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>

#include "../common/lab_base.h"

namespace pt = boost::posix_time;

class A{};

class BoostLab {
public:
    void TestSmartPtr();
    void TestTime();
};
#endif //CPPLABS_BOOST_LAB_H
