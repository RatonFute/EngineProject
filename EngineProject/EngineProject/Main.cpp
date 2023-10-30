#include "Coordinator.hpp"
#include "RigidBody.hpp"
#include "Transform.hpp"
#include "PhysicsSystem.hpp"
#include <chrono>
#include <random>
#include <DirectXMath.h>
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

	std::default_random_engine generator;
	std::uniform_real_distribution<float> randPosition(-100.0f, 100.0f);
	std::uniform_real_distribution<float> randRotation(0.0f, 3.0f);


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
	while (!quit)
	{
		gCoordinator.RegisterComponent<RigidBody>();
		gCoordinator.RegisterComponent<Transform>();

		auto startTime = std::chrono::high_resolution_clock::now();


		physicsSystem->Update(dt);



		auto stopTime = std::chrono::high_resolution_clock::now();

		dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
	}
}