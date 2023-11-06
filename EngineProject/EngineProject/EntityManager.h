#pragma once

#include <string>
#include "Entity.h"

class EntityManager {
public:
	Entity CreatEntity(std::string name)
	{
		Entity entity = Entity(name);
		entity.AddComponent<Transform>();
		return entity;
	}
};