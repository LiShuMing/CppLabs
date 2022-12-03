cmake_minimum_required (VERSION 3.8)

FILE(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
SET(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# add_library(core ${SRC})
# target_include_directories(core PUBLIC ${VEC_HEADER_DIR})

foreach (src ${SRC_FILES})
    get_filename_component(exe ${src} NAME_WE)
    add_executable(${exe} ${src})
    target_link_libraries(${exe} ${link_libs} benchmark pthread)
    list(APPEND benchmarks_deps ${exe})
endforeach ()

add_custom_target(core DEPENDS ${benchmarks_deps})