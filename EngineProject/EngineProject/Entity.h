#include "Type.h"
#include <List>
#include <string>
#include <cassert>
#include <unordered_map>
#include "Component.h"
class Entity
{
	std::string name = "";
	void AddComponent(Component component)
	{
		size_t newIndex = mSize;
		mIndexToComponent[newIndex] = component;
		mComponentToIndex[component] = newIndex;
		++mSize;
	}
	void RemoveComponent(Component component)
	{
		size_t indexOfRemovedComponent = mComponentToIndex[component];
		size_t indexOfLastComponent = mSize - 1;

		Component componentOfLastElement = mIndexToComponent[indexOfLastComponent];
		mComponentToIndex[componentOfLastElement] = indexOfLastComponent;
		mIndexToComponent[indexOfLastComponent] = componentOfLastElement;
		mIndexToComponent.erase(mComponentToIndex[component]);
		mComponentToIndex.erase(component);
		--mSize;
	}
	Component GetComponents(Component component)
	{
		return mIndexToComponent[mComponentToIndex[component]];
	}
	void DestroyedEntity()
	{
		
	}
private:

	std::unordered_map<Component, size_t> mComponentToIndex;
	std::unordered_map<size_t, Component> mIndexToComponent;
	size_t mSize{};
};
