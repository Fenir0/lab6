cmake_minimum_required(VERSION 3.10.0)
project(lab5 VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCE_FILES main.cpp src/matr.cpp src/sq_matr.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
