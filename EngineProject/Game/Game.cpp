#include "pch.h"


Coordinator coordinator;

int main()
{
	Entity entity = coordinator.CreateEntity();
	Transform transform;
	transform.Position = XMVectorSet(0, 0, 0, 0);
	transform.Position = XMVectorSet(0, 0, 0, 0);
	transform.Scale = XMVectorSet(1, 1, 1, 0);
	coordinator.AddComponent(entity, transform);
}


