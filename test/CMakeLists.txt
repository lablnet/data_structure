include(FetchContent)
FetchContent_Declare(gtest
        QUIET
        URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
        )
# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)

add_executable(
        unit_tests
        binary_search_test.cpp
        linear_search_test.cpp
        merge_sort_test.cpp
        bubble_sort_test.cpp
        insertion_sort_test.cpp
        stack_test.cpp
        queue_test.cpp
)

target_link_libraries(unit_tests
        PRIVATE
        gtest_main
        )

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(unit_tests
        PROPERTIES
        LABELS "unit"
        DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
        240
        )