cmake_minimum_required(VERSION 3.28)
project(ECSEngine)

add_executable(main main.cpp)

target_link_libraries(main engine)

add_subdirectory(engine)