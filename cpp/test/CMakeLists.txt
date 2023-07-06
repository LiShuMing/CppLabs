message(STATUS "link_libs=${link_libs}")
set(TESTS
        allocator_test.cpp
        basic_test.cpp
        lock_problem.cpp
        lock_problem_dining.cpp
        thread_test.cpp
        )

foreach (src ${TESTS})
    get_filename_component(exe ${src} NAME_WE)
    add_executable(${exe} ${src} )
    target_link_libraries(${exe} ${link_libs} pthread gtest)
    list(APPEND unittest_deps ${exe})
endforeach ()
add_custom_target(unittest DEPENDS ${unittest_deps})
