#include "PhysicsSystem.h"
#include "RigidBody.h"
#include "Transform.h"



void PhysicsSystem::Init()
{
}

void PhysicsSystem::Update(float dt)
{
	for (Entity entity : mEntities)
	{
		RigidBody* rb = entity.GetComponent<RigidBody>();
		Transform* transform = entity.GetComponent<Transform>();
		transform->Position += rb->velocity * dt;
	}
}
