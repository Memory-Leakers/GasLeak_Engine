#pragma once
#include "RigidBody.h"
#include "List.h"
class PhysCore
{
public:
	PhysCore(fPoint gravity);

	~PhysCore();

	void Update(float simulationTime);

	bool CheckCollision(RigidBody* body);

	void AddRigidBody(RigidBody* body);

private:
	fPoint gravity;
	List<RigidBody*> rigidBodies;
};

