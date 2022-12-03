message(STATUS "link_libs=${link_libs}")

set(BENCHMARKS
        benchmark_basic.cpp
        )

foreach (src ${BENCHMARKS})
    get_filename_component(exe ${src} NAME_WE)
    add_executable(${exe} ${src})
    target_link_libraries(${exe} ${link_libs} benchmark pthread)
    list(APPEND benchmarks_deps ${exe})
endforeach ()

add_custom_target(bench DEPENDS ${benchmarks_deps})
