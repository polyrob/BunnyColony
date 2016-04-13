cmake_minimum_required(VERSION 3.3.2)
project(Bunny)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Bunny.cpp Bunny.h BunnyColony.cpp BunnyColony.h BunnyGenerator.cpp BunnyGenerator.h NameGenerator.cpp NameGenerator.h)
add_executable(Bunny ${SOURCE_FILES})