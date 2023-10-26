#include "PhysicsSystem.hpp"


#include "RigidBody.hpp"
#include "Transform.hpp"
#include "Coordinator.hpp"


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

		transform.position += rigidBody.velocity * dt;
	}
}
