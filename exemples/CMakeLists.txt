cmake_minimum_required(VERSION 3.20)
project(meu-projeto)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(
	../
	r_build
)

add_executable(app Main.cpp)

target_link_libraries(app
    PRIVATE
        algorithms-cpp_lib
)