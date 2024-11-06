cmake_minimum_required(VERSION 3.16)

file(GLOB_RECURSE common_cpp_files "common/*.cpp")
file(GLOB_RECURSE common_hpp_files "common/*.hpp")

add_library(CommonFiles STATIC ${common_cpp_files} ${common_hpp_files})
