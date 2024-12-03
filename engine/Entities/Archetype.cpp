#include "Archetype.hpp"
#include "../Core/Constants.hpp"
#include <iostream>
#include <cassert>

struct EntityInfo
{
    int chunkIndex;
    int indexInChunk;
};
EntityInfo GetEntityInfo(const std::map<Entity, int> &entityToRow, Entity entity)
{
    EntityInfo info;

    return info;
}
Archetype::Archetype(ComponentType components[], int count)
{
    componentSet = ComponentSet(components, count);

    size_t pos = 0;
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
}

void *Archetype::GetDataRef(Entity entity, ComponentID component) const
{
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

std::string Archetype::ToString() const
{
    return "Archetype: {chunkSize: " + std::to_string(chunkSize) + ", chunkCount: " + std::to_string(chunks.size()) + ", entityCount: " + std::to_string(entityToRow.size()) + ", componentSet: " + componentSet.ToString() + "}";
}
