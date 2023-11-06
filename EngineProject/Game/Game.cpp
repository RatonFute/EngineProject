#include "pch.h"
using namespace DirectX;
EntityManager entityManager;
int main()
{
	Entity entity = entityManager.CreatEntity("wui");
	entity.AddComponent<RigidBody>();
	RigidBody* rb = entity.GetComponent<RigidBody>();
	rb->velocity = XMVectorSet(1, 0, 0, 0);



}


