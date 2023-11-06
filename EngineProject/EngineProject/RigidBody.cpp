#include "RigidBody.h"

void RigidBody::AddEntity(int entityid, RigidBody* rigidBody)
{
	_entityId = entityid;
	_entitiesRB[_entityId] = rigidBody;
}