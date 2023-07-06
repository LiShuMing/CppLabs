#pragma once

#include "Hash.h"
#include <boost/unordered_map.hpp>
#include <boost/version.hpp>

static const char* MapName = "boost::unordered_map " BOOST_LIB_VERSION;

template <class Key, class Val>
using Map = boost::unordered_map<Key, Val, Hash<Key>>;
