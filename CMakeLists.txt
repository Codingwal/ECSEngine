cmake_minimum_required(VERSION 3.28)
project(ECSEngine)

include_directories(include)

add_executable(main test/main.cpp)

target_link_libraries(main Engine)

add_subdirectory(src)