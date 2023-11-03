#pragma once
#include "Type.h"
#include <queue>
#include <cassert>
#include <array>
#include "Entity.h"

class EntityManager {
public:
	void CreateEntity()
	{
		size_t newIndex = mSize;
		Entity entity;
		mIndexToEntity[newIndex] = entity;
		mEntityToIndex[entity] = newIndex;
		++mSize;
	}
	void DestroyEntity(Entity entity)
	{
		size_t indexOfRemovedEntity = mEntityToIndex[entity];
		size_t indexOfLastEntity = mSize - 1;

		Entity EntityOfLastElement = mIndexToEntity[indexOfRemovedEntity];
		mEntityToIndex[EntityOfLastElement] = indexOfLastEntity;
		mIndexToEntity[indexOfLastEntity] = EntityOfLastElement;
		mIndexToEntity.erase(mEntityToIndex[entity]);
		mEntityToIndex.erase(entity);
		--mSize;
	}
	std::list<Entity> GetEntityByTag(int tag) 
	{
		std::list<Entity> entities;
		for (int i = 0; i < mIndexToEntity.bucket_count(); i++)
		{
			if (mIndexToEntity[i].tag == tag) entities.push_back(mIndexToEntity[i]);
		}
		return entities;
	}
private:

	std::unordered_map<Entity, size_t> mEntityToIndex;
	std::unordered_map<size_t, Entity> mIndexToEntity;
	size_t mSize{};
};

