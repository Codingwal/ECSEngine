#include "World/Systems.hpp"
#include "ECS/Components.hpp"
#include "World/World.hpp"

void ECSEngine::UpdateTransformMatrix::Update(World &world, float deltaTime)
{
    auto &query = world.GetEntityQuery<TransformMatrix, Transform>();
    for (Entity entity : query.GetEntities())
    {
        auto &transMat = world.GetComponentDataRef<TransformMatrix>(entity);
        auto &trans = world.GetComponentData<Transform>(entity);

        transMat.matrix = Float4x4::Identity();
        transMat.matrix = Float4x4::Translate(transMat.matrix, trans.position);
        transMat.matrix = Float4x4::Scale(transMat.matrix, trans.scale);
        transMat.matrix = Float4x4::Rotate(transMat.matrix, Math::ToRadians(trans.rotation.x), Float3(1, 0, 0));
        transMat.matrix = Float4x4::Rotate(transMat.matrix, Math::ToRadians(trans.rotation.y), Float3(0, 1, 0));
        transMat.matrix = Float4x4::Rotate(transMat.matrix, Math::ToRadians(trans.rotation.z), Float3(0, 0, 1));
    }
}

void ECSEngine::GraphicsSystem::Update(World &world, float deltaTime)
{
    world.renderer.objects.clear();
    world.renderer.objects.reserve(world.entityManager.GetEntityCount());

    auto &query = world.GetEntityQuery<TransformMatrix>();
    for (Entity entity : query.GetEntities())
    {
        Object obj;
        obj.transformMatrix = world.GetComponentData<TransformMatrix>(entity).matrix;
        world.renderer.objects.push_back(obj);
    }
}
void ECSEngine::PhysicsSystem::Update(World &world, float deltaTime)
{
    auto &query = world.GetEntityQuery<Transform, PhysicsObject>();
    for (Entity entity : query.GetEntities())
    {
        const auto &obj = world.GetComponentData<PhysicsObject>(entity);
        auto &transform = world.GetComponentDataRef<Transform>(entity);
        transform.position += obj.velocity * deltaTime;
    }
}
