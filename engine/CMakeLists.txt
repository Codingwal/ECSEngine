add_library(engine STATIC Entities/EntityManager.cpp Components/ComponentManager.cpp Entities/Archetype.cpp)

target_include_directories(engine
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})