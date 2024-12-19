include_directories(../lib/include)
include_directories(../include/Engine)

add_library(Engine STATIC 
            ECS/Base/Structs.cpp 
            ECS/Archetype.cpp ECS/ComponentManager.cpp ECS/EntityManager.cpp ECS/SystemManager.cpp
            EntityQuery/EntityQuery.cpp
            Graphics/Renderer.cpp Graphics/glad.c Graphics/stb_image.cpp Graphics/ShaderProgram.cpp Graphics/Texture.cpp
            World/World.cpp
            Math/Float2.cpp  Math/Float3.cpp  Math/Float4.cpp  Math/Float4x4.cpp)

target_link_libraries(Engine C:/Users/flori/Documents/Coding/C++/ECSEngine/lib/src/libglfw3.a)

target_include_directories(Engine
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})