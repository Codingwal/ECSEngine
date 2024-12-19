#include "ECS/Archetype.hpp"
#include "ECS/Base/Constants.hpp"
#include <iostream>
#include <cassert>

namespace ECSEngine
{
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

    Archetype::Archetype(ComponentType components[], size_t count)
    {
        componentSet = ComponentSet(components, count);

        componentInfo.emplace(std::pair(0, ComponentInfo(0, sizeof(Entity)))); // All entities must have the "Entity" component

        size_t pos = sizeof(Entity) * ENTITIES_PER_CHUNK; // Start behind the "Entity" components
        for (size_t i = 0; i < count; i++)
        {
            auto &component = components[i];
            componentInfo.emplace(component.id, ComponentInfo(pos, component.size));
            pos += component.size * ENTITIES_PER_CHUNK;
        }
        chunkSize = pos;

        chunks.emplace_back(chunkSize);
    }

    void Archetype::AddEntity(Entity entity)
    {
        size_t row = entityToRow.size();
        size_t chunkIndex = row / ENTITIES_PER_CHUNK;
        size_t indexInChunk = row % ENTITIES_PER_CHUNK;

        // Create a new chunk if necessary
        if (chunkIndex >= chunks.size())
        {
            chunks.emplace_back(chunkSize);
        }
        ArchetypeChunk &chunk = chunks[chunkIndex];

        entityToRow.emplace(entity, row);
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
        size_t row = entityToRow.at(entity);
        size_t chunkIndex = row / ENTITIES_PER_CHUNK;
        size_t indexInChunk = row % ENTITIES_PER_CHUNK;
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
            components.emplace_back(pair.first, pair.second.size);
        }
        return components;
    }

    Entity Archetype::RowToEntity(size_t row) const
    {
        size_t chunkIndex = row / ENTITIES_PER_CHUNK;
        size_t indexInChunk = row % ENTITIES_PER_CHUNK;
        size_t posInChunk = indexInChunk * sizeof(Entity);
        void *ptr = (char *)chunks[chunkIndex].data + posInChunk;
        return *(Entity *)ptr;
    }

    std::string Archetype::ToString() const
    {
        return "Archetype: {chunkSize: " + std::to_string(chunkSize) + ", chunkCount: " + std::to_string(chunks.size()) + ", entityCount: " + std::to_string(EntityCount()) + ", componentSet: " + componentSet.ToString() + "}";
    }
}