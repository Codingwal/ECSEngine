#include "Archetype.hpp"
#include "../Core/Constants.hpp"
#include <iostream>
#include <cassert>

// ArchetypeChunk

ArchetypeChunk::ArchetypeChunk(size_t size)
{
    data = calloc(size, sizeof(char));
}

ArchetypeChunk::ArchetypeChunk(ArchetypeChunk &&other)
{
    data = other.data;
    other.data = nullptr;
}

ArchetypeChunk::~ArchetypeChunk()
{
    if (data)
        free(data);
}

// Archetype

Archetype::Archetype(ComponentType components[], int count)
{
    componentSet = ComponentSet(components, count);

    componentInfo.insert(std::pair(0, ComponentInfo(0, sizeof(Entity)))); // All entities must have the "Entity" component

    size_t pos = sizeof(Entity) * ENTITIES_PER_CHUNK; // Start behind the "Entity" components
    for (int i = 0; i < count; i++)
    {
        auto &component = components[i];
        componentInfo.insert(std::pair(component.id, ComponentInfo(pos, component.size)));
        pos += component.size * ENTITIES_PER_CHUNK;
    }
    chunkSize = pos;

    chunks.push_back(ArchetypeChunk(chunkSize));
}

void Archetype::AddEntity(Entity entity)
{
    int row = entityToRow.size();
    int chunkIndex = row / ENTITIES_PER_CHUNK;
    int indexInChunk = row % ENTITIES_PER_CHUNK;

    // Create a new chunk if necessary
    if (chunkIndex >= chunks.size())
    {
        chunks.push_back(ArchetypeChunk(chunkSize));
    }
    ArchetypeChunk &chunk = chunks[chunkIndex];

    entityToRow.insert(std::pair(entity, row));
    *(Entity *)GetDataRef(entity, 0) = entity;
}

void Archetype::CopyEntityData(Archetype &destination, Entity destEntity, Entity srcEntity)
{
    for (const auto &pair : componentInfo)
    {
        if (destination.HasComponent(pair.first))
        {
            void *src = GetDataRef(srcEntity, pair.first);
            void *dest = destination.GetDataRef(destEntity, pair.first);
            memcpy(dest, src, pair.second.size);
        }
    }
}

void Archetype::RemoveEntity(Entity entity)
{
    if (!(entityToRow.at(entity) == EntityCount() - 1)) // If this is not the last entity
    {
        size_t posInChunk = (EntityCount() - 1) % ENTITIES_PER_CHUNK * sizeof(Entity); // lastEntityIndex % ENTITIES_PER_CHUNK * sizeof(Entity)
        void *otherPtr = (char *)chunks[chunks.size() - 1].data + posInChunk;          // ptrToLastChunk + posInChunk
        Entity other = *(Entity *)otherPtr;
        CopyEntityData(*this, entity, other);        // Copy other's data into entity's memory
        entityToRow[other] = entityToRow.at(entity); // Update other's location in memory
    }
    entityToRow.erase(entity); // Remove this entity (this also decrements the entity count)
}

void *Archetype::GetDataRef(Entity entity, ComponentID component) const
{
    assert(entityToRow.count(entity) && "The archetype does not contain the entity");
    assert(componentInfo.count(component) && "The archetype does not contain the component");
    int row = entityToRow.at(entity);
    int chunkIndex = row / ENTITIES_PER_CHUNK;
    int indexInChunk = row % ENTITIES_PER_CHUNK;
    auto &info = componentInfo.at(component);
    size_t posInChunk = info.startIndex + indexInChunk * info.size;
    return (char *)chunks.at(chunkIndex).data + posInChunk; // chunkPtr + posInChunk
}

bool Archetype::HasComponent(ComponentID component) const noexcept
{
    return componentInfo.count(component);
}

bool Archetype::HasComponents(ComponentSet components) const noexcept
{
    return componentSet.HasComponents(components);
}

bool Archetype::Matches(ComponentSet components) const noexcept
{
    return components == componentSet;
}

std::vector<ComponentType> Archetype::GetComponentTypes() const noexcept
{
    std::vector<ComponentType> components;
    for (auto &pair : componentInfo)
    {
        components.push_back(ComponentType(pair.first, pair.second.size));
    }
    return components;
}

Entity Archetype::RowToEntity(int row) const
{
    int chunkIndex = row / ENTITIES_PER_CHUNK;
    int indexInChunk = row % ENTITIES_PER_CHUNK;
    size_t posInChunk = indexInChunk * sizeof(Entity);
    void *ptr = (char *)chunks[chunkIndex].data + posInChunk;
    return *(Entity *)ptr;
}

std::string Archetype::ToString() const
{
    return "Archetype: {chunkSize: " + std::to_string(chunkSize) + ", chunkCount: " + std::to_string(chunks.size()) + ", entityCount: " + std::to_string(EntityCount()) + ", componentSet: " + componentSet.ToString() + "}";
}
