cmake_minimum_required(VERSION 3.10)
project(CppLabs)

set(CMAKE_CXX_STANDARD 17)

############ BOOST LIB ############
find_package(Boost REQUIRED)
# only contains specific module
#find_package(Boost REQUIRED COMPONENTS locale)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    message("-- Boost found: ${Boost_VERSION_STRING}")
    link_directories( ${Boost_LIBRARY_DIRS} )
    set( Boost_USE_STATIC_LIBS        OFF )
    set( Boost_USE_MULTITHREADED      ON )
    set( Boost_USE_STATIC_RUNTIME     OFF )
    set( BOOST_ALL_DYN_LINK           ON )
else()
    message(FATAL_ERROR "Boost not found!")
endif()

############ GOOGLETEST LIB ############
add_subdirectory(lib/googletest)

add_subdirectory(test)

add_executable(CppLabs main.cpp std/std_lab.cpp std/std_lab.h boost/boost_lab.h boost/boost_lab.cpp common/lab_base.h)