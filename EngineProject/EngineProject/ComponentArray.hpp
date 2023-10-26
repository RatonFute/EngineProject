#include "Type.hpp"
#include <array>
#include <cassert>
#include <unordered_map>

class IComponentArray
{
public:
	virtual ~IComponentArray() = default;
	virtual void EntityDestroyed(Entity entity) = 0;
};


template<typename T>
class ComponentArray : public IComponentArray
{
public:
	void InsertData(Entity entity, T component)
	{
		assert(mEntityToIndexMap.find(entity) == mEntityToIndexMap.end() && "Component added to same entity more than once.");

		size_t newIndex = mSize;
		mEntityToIndexMap[newIndex] = entity;
		mIndexToEntityMap[entity] = newIndex;
		mComponentArray[newIndex] = component;
		++mSize;
	}
	void RemoveData(Entity entity)
	{
		assert(mEntityToIndexMap.find(entity) != mEntityToIndexMap.end() && "data's entity does not exist");
		size_t indexOfRemovedEntity = mEntityToIndexMap[entity];
		size_t indexOfLastEntity = mSize - 1;

		Entity entityOfLastElement = mIndexToEntityMap[indexOfLastEntity];
		mEntityToIndexMap[entityOfLastElement] = indexOfLastEntity;
		mIndexToEntityMap[indexOfLastEntity] = entityOfLastElement;

		mEntityToIndexMap.erase(entity);
		mIndexToEntityMap.erase(indexOfRemovedEntity);
		--mSize;
	}
	T& GetData(Entity entity)
	{
		assert(mEntityToIndexMap.find(entity) != mEntityToIndexMap.end() && "data's entity does not exist");
		return mComponentArray[mEntityToIndexMap[entity]];
	}
	void EntityDestroyed(Entity entity) override
	{
		if (mEntityToIndexMap.find(entity) != mEntityToIndexMap.end())
		{
			RemoveData(entity);
		}
	}
private:
	std::array<T, MAX_ENTITIES> mComponentArray{};
	std::unordered_map<Entity, size_t> mEntityToIndexMap{};
	std::unordered_map<size_t, Entity> mIndexToEntityMap{};
	size_t mSize{};
};