include_directories(../lib/include)
include_directories(../include/Engine)

add_library(Engine STATIC 
            Core/Base/Structs.cpp 
            Core/Archetype.cpp Core/ComponentManager.cpp Core/EntityManager.cpp Core/SystemManager.cpp
            EntityQuery/EntityQuery.cpp
            Interface/World.cpp
            Graphics/glad.c Graphics/stb_image.cpp Graphics/ShaderProgram.cpp Graphics/Texture.cpp)

target_include_directories(Engine
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})