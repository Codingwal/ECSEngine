#pragma once

#include "../Core/Structs.hpp"
#include <vector>
#include <map>

struct ArchetypeChunk
{
    void *data;
    ArchetypeChunk(size_t size)
    {
        data = calloc(size, sizeof(char));
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
    void CopyEntityData(Archetype &destination, Entity destEntity, Entity srcEntity);
    void RemoveEntity(Entity entity);
    void *GetDataRef(Entity entity, ComponentID component) const;

    bool HasComponent(ComponentID component) const noexcept;
    bool HasComponents(ComponentSet components) const noexcept;
    bool Matches(ComponentSet components) const noexcept;
    ComponentSet GetComponentSet() const noexcept { return componentSet; }
    std::vector<ComponentType> GetComponentTypes() const noexcept;

    int EntityCount() const { return entityToRow.size(); }
    std::string ToString() const;

private:
    ComponentSet componentSet;
    std::map<ComponentID, ComponentInfo> componentInfo;
    std::vector<ArchetypeChunk> chunks;
    std::map<Entity, int> entityToRow;
    size_t chunkSize;
};