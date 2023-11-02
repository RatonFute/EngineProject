#pragma once
#include <DirectXMath.h>
#include "Component.h"
using namespace DirectX;

class RigidBody : public Component
{
public:
	XMVECTOR velocity;
	float mass;
};
