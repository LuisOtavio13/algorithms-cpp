cmake_minimum_required(VERSION 3.20)

project(algorithms-cpp)

set(PROJECT_NAME algorithms-cpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE HEDERFILES src/*.hpp)

list(FILTER SRC_FILES EXCLUDE REGEX "src/test/.*\\.cpp$")
list(FILTER HEDERFILES EXCLUDE REGEX "src/test/.*\\.hpp$")

add_library(${PROJECT_NAME}_lib ${SRC_FILES} ${HEDERFILES})
target_include_directories(algorithms-cpp_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)


add_subdirectory(lib/googletest)
enable_testing()


set(TEST_FILES src/test/Main.cpp)

add_executable(${PROJECT_NAME}_tests ${TEST_FILES})

target_link_libraries(${PROJECT_NAME}_tests
    ${PROJECT_NAME}_lib
    gtest
    gtest_main
)

add_test(
    NAME ${PROJECT_NAME}_tests
    COMMAND ${PROJECT_NAME}_tests
)