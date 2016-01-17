cmake_minimum_required(VERSION 3.2)

project("anitomy-cli")

# add_subdirectory(external/json)
include_directories(external/json/src)
include_directories(external/anitomy)
file (GLOB anitomy_sources external/anitomy/anitomy/*.cpp)

add_executable(anitomy-cli ${anitomy_sources} src/main.cc)
target_compile_features(anitomy-cli PUBLIC cxx_auto_type)
