cmake_minimum_required(VERSION 3.28)
project(ECSEngine)

include_directories(include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# add_subdirectory(test/AccelerationSimulation)
add_subdirectory(test/Rendering)

add_subdirectory(src)

target_link_libraries(main Engine)