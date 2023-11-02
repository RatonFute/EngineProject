#include "Type.h"
#include <List>
#include <string>
#include <cassert>
#include <unordered_map>
#include "Component.h"
class Entity
{
	std::string name = "";
	template<typename Component>
	void InsertData(Component component)
	{
		mComponentMap.insert(component);
	}
	void RemoveData(Component component)
	{
		mComponentMap.remove(component);
	}
	Component GetData()
	{
		return mComponentMap;
	}
	void EntityDestroyed(Entity entity) override
	{
		if (mEntityToIndexMap.find(entity) != mEntityToIndexMap.end())
		{
			RemoveData(entity);
		}
	}
private:

	std::list<Component> mComponentMap
};
