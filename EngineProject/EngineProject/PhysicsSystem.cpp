#include "PhysicsSystem.h"
#include "RigidBody.h"
#include "Transform.h"
#include "Coordinator.h"


extern Coordinator gCoordinator;


void PhysicsSystem::Init()
{
}

void PhysicsSystem::Update(float dt)
{
	for (auto const& entity : mEntities)
	{
		auto& rigidBody = gCoordinator.GetComponent<RigidBody>(entity);
		auto& transform = gCoordinator.GetComponent<Transform>(entity);

		transform.Position += rigidBody.velocity * dt;
	}
}
