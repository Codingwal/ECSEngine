#pragma once

#include "../Core/Structs.hpp"

class Archetype
{
public:
    Archetype(ComponentSet components);
    void AddEntity(Entity entity);
    void RemoveEntity(Entity entity);

public:
    ComponentSet components;
};