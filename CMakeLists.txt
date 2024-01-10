cmake_minimum_required(VERSION 3.8.0)
project(lottie)

file(GLOB_RECURSE SOURCE src/*.cc src/*.h)
add_library(lottie STATIC ${SOURCE})
target_include_directories(lottie PUBLIC include)
target_include_directories(lottie PRIVATE src)
