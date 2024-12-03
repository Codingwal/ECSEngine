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

    chunks.push_back(ArchetypeChunk(pos));

    chunkSize = pos;
}

void Archetype::AddEntity(Entity entity)
{
}

void Archetype::RemoveEntity(Entity entity)
{
}

std::string Archetype::ToString() const
{
    return "Archetype: {chunkSize: " + std::to_string(chunkSize) + ", entityCount: " + std::to_string(entityToRow.size()) + ", componentSet: " + componentSet.ToString() + "}";
}
