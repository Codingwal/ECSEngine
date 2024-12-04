#pragma once

#include "../Core/Structs.hpp"
#include <vector>
#include <map>

// @brief A chunk owned by an archetype that has space for ENTITIES_PER_CHUNK entities
struct ArchetypeChunk
{
    void *data;
    ArchetypeChunk(size_t size);
    ArchetypeChunk(ArchetypeChunk &&other);
    ~ArchetypeChunk();
};

// @brief Internal information about a component. Only used by archetypes
struct ComponentInfo
{
    int startIndex;
    size_t size;
    ComponentInfo(int _startIndex, size_t _size) : startIndex(_startIndex), size(_size) {}
};

// @brief Contains all entities and their component data of a specific ComponentSet (component combination)
class Archetype
{
public:
    Archetype(ComponentType components[], size_t size);
    void AddEntity(Entity entity);
    void CopyEntityData(Archetype &destination, Entity destEntity, Entity srcEntity);
    void RemoveEntity(Entity entity);
    void *GetDataRef(Entity entity, ComponentID component) const;

    bool HasComponent(ComponentID component) const noexcept;
    bool HasComponents(ComponentSet components) const noexcept;
    bool Matches(ComponentSet components) const noexcept;
    ComponentSet GetComponentSet() const noexcept { return componentSet; }
    std::vector<ComponentType> GetComponentTypes() const noexcept;

    size_t EntityCount() const { return entityToRow.size(); }
    std::string ToString() const;

private:
    Entity RowToEntity(size_t row) const;

private:
    ComponentSet componentSet;
    std::map<ComponentID, ComponentInfo> componentInfo;
    std::vector<ArchetypeChunk> chunks;
    std::map<Entity, size_t> entityToRow;
    size_t chunkSize;

    friend class EntityQuery;
};