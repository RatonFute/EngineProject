#pragma once

#include "Entity.h"
#include <set>

namespace Engine {

	class System
	{
	public:
		std::set<Entity> mEntities;
	};
}

