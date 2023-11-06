#pragma once
#include <iostream>
#include <unordered_map>
#include "System.h"

class SystemManager
{
public:
	template<typename T>
	std::shared_ptr<T> RegisterSystem()
	{
		const char* typeName = typeid(T).name();
		assert(mSystems.find(typeName) == mSystems.end() && "Registering system more than once.");

		auto system = std::make_shared<T>();
		mSystems.insert({ typeName,system });
		return system;

	}
	
private:
	// Map from system type string pointer to a system pointer
	std::unordered_map<const char*, std::shared_ptr<Engine::System>> mSystems{};
};