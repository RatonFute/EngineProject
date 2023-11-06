#include "pch.h"
using namespace DirectX;
Coordinator gCoordinator;

int main()
{
	gCoordinator.Init();
	float dt = 0.0f;
	bool quit = false;

	auto physicsSystem = gCoordinator.RegisterSystem<PhysicsSystem>();
	{
		Signature signature;
		signature.set(gCoordinator.GetComponentType<RigidBody>());
		signature.set(gCoordinator.GetComponentType<Transform>());
		gCoordinator.SetSystemSignature<PhysicsSystem>(signature);
	}

	physicsSystem->Init();
	std::vector<Entity> entities(MAX_ENTITIES - 1);



	for (auto& entity : entities)
	{
		entity = gCoordinator.CreateEntity();
		RigidBody entityRB;
		entityRB.velocity = XMVectorSet(0, 0, 0, 0);
		Transform entityTransform;
		entityTransform.Position = XMVectorSet(0, 0, 0, 0);
		entityTransform.Rotation = XMVectorSet(0, 0, 0, 0);
		entityTransform.Scale = XMVectorSet(1, 1, 1, 0);
		gCoordinator.AddComponent(entity, entityRB);
		gCoordinator.AddComponent(entity, entityTransform);
	}

}


