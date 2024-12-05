add_library(engine STATIC Components/ComponentManager.cpp Core/Structs.cpp Entities/EntityManager.cpp Entities/Archetype.cpp World.cpp Entities/EntityQuery/EntityQuery.cpp)

target_include_directories(engine
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})