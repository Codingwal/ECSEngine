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
    ArchetypeChunk(ArchetypeChunk &&other)
    {
        data = other.data;
        other.data = nullptr;
    }
    ~ArchetypeChunk()
    {
        if (data)
            free(data);
    }
};
struct ComponentInfo
{
    int startIndex;
    size_t size;
    ComponentInfo(int _startIndex, size_t _size)
    {
        startIndex = _startIndex;
        size = _size;
    }
};
class Archetype
{
public:
    Archetype(ComponentType components[], int size);
    void AddEntity(Entity entity);
    void RemoveEntity(Entity entity);

    std::string ToString() const;

public:
    ComponentSet componentSet;

private:
    std::vector<ArchetypeChunk> chunks;
    std::map<ComponentID, ComponentInfo> componentInfo;
    std::map<Entity, int> entityToRow;
    size_t chunkSize;
};