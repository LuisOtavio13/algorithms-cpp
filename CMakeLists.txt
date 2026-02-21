cmake_minimum_required(VERSION 3.20)

project(algorithms-cpp)

set(PROJECT_NAME algorithms-cpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------
# Biblioteca principal (sem testes)
# -----------------------------
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Remover arquivos de teste da lista de fontes
list(FILTER SRC_FILES EXCLUDE REGEX "src/test/.*\\.cpp$")

add_library(${PROJECT_NAME}_lib ${SRC_FILES})
target_include_directories(${PROJECT_NAME}_lib PUBLIC src)

# -----------------------------
# GoogleTest
# -----------------------------
add_subdirectory(lib/googletest)
enable_testing()

# -----------------------------
# Executável de teste
# -----------------------------
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