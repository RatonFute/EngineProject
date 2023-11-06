#pragma once
#include "EntityManager.h"
#include "SystemManager.h"
#include "Entity.h"

class Coordinator
{
public:
	void Init();
	void CreateEntity();


	template<typename T>
	std::shared_ptr<T>RegisterSystem();

private:
	std::unique_ptr<EntityManager> mEntityManager;
	std::unique_ptr<SystemManager> mSystemManager;
};