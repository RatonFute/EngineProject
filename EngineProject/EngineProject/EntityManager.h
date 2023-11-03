#pragma once
#include "Type.h"
#include <queue>
#include <cassert>
#include <array>
#include "Entity.h"

class EntityManager {
public:
	Entity CreatEntity()
	{
		assert(LivingEntityCount < MAX_COMPONENTS && "too many entities");
		Entity entity;
		Entities.push(entity);
		LivingEntityCount++;
		return entity;
	}
	Entity DestroyEntity(Entity entity) 
	{

		Entities.
			--LivingEntityCount;
	}
private:

	array<Entity> Entities{};
	uint32_t LivingEntityCount{};
};

