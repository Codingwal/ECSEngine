#pragma once

#include "../Core/Structs.hpp"
#include <vector>
#include <map>
#include <malloc.h>

struct ArchetypeChunk
{
    void *data;
    ArchetypeChunk(size_t size)
    {
        data = malloc(size);
    }
    ~ArchetypeChunk()
    {
        free(data);
    }
};
struct ComponentInfo
{
    size_t size;
    int startIndex;
};
class Archetype
{
public:
    Archetype(ComponentSet components);
    void AddEntity(Entity entity);
    void RemoveEntity(Entity entity);

public:
    ComponentSet components;
    std::vector<ArchetypeChunk> chunks;
    std::map<ComponentType, ComponentInfo> componentInfo;
    std::map<Entity, int> entityToRow;
};