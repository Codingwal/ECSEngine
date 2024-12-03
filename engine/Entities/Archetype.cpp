#include "Archetype.hpp"
#include "../Core/Constants.hpp"
#include <iostream>

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
    int entityCount = entityToRow.size();
    int chunkIndex = entityCount / ENTITIES_PER_CHUNK;
    int indexInChunk = entityCount % ENTITIES_PER_CHUNK;

    // Create a new chunk if necessary
    if (chunkIndex >= chunks.size())
    {
        chunks.push_back(ArchetypeChunk(chunkSize));
    }
    ArchetypeChunk &chunk = chunks[chunkIndex];

    entityToRow.insert(std::pair(entity, entityCount));
}

void Archetype::RemoveEntity(Entity entity)
{
}

std::string Archetype::ToString() const
{
    return "Archetype: {chunkSize: " + std::to_string(chunkSize) + ", chunkCount: " + std::to_string(chunks.size()) + ", entityCount: " + std::to_string(entityToRow.size()) + ", componentSet: " + componentSet.ToString() + "}";
}
