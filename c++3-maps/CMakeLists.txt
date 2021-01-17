cmake_minimum_required(VERSION 3.0.0)
project(csgrinding-videos VERSION 0.1.0)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(csgrinding-videos maps.cpp)
target_link_libraries(csgrinding-videos ${CONAN_LIBS})
