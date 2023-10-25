#include "Type.hpp"
#include <queue>
#include <cassert>
#include <array>


class EntityManager {
public:
	EntityManager()
	{
		for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
		{
			AvailableEntities.push(entity);
		}
	}
	Entity CreatEntity()
	{
		assert(LivingEntityCount < MAX_COMPONENTS && "too many entities");
		Entity id = AvailableEntities.front();
		AvailableEntities.pop();
		++LivingEntityCount;
		return id;
	}
	Entity DestroyEntity(Entity entity) 
	{
		mSignatures[entity].reset();
		AvailableEntities.push(entity);
		--LivingEntityCount;
	}
	void SetSignature(Entity entity, Signature signature)
	{
		mSignatures[entity] = signature;
	}
	Signature GetSignature(Entity entity)
	{
		return mSignatures[entity];
	}
private:
	std::queue<Entity> AvailableEntities{};
	std::array<Signature, MAX_ENTITIES> mSignatures{};
	uint32_t LivingEntityCount{};
};

