# find_package(GTest CONFIG REQUIRED)

#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        # Specify the commit you depend on and update it regularly.
#        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
#)
## For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)


# 'lib' is the folder with Google Test sources
#add_subdirectory(lib)
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(${PROJECT_NAME}.tests
        tests.cpp
        binary_search_test.cpp)
target_link_libraries(${PROJECT_NAME}.tests
        ${PROJECT_NAME} gtest pthread)
target_compile_definitions(${PROJECT_NAME}.tests
        PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}/tests")

install(TARGETS ${PROJECT_NAME}.tests
        DESTINATION "${tool_dest}")
