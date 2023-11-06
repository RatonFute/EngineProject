#pragma once
#include <DirectXMath.h>
#include "IComponent.h"
#include <unordered_map>
using namespace DirectX;

struct RigidBody : public IComponent
{
	XMVECTOR velocity;
	float mass;
	void AddEntity(int entityid, RigidBody* transform);
	int _entityId;
	std::unordered_map<int, RigidBody*> _entitiesRB;
};
