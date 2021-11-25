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

	void DeleteRigidBody(RigidBody* body);

	void SetWind(fPoint windforce) 
	{
		wind = windforce;
	}

	void SetGravity(fPoint gravityforce)
	{
		gravity = gravityforce;
	}

	fPoint GetWind() 
	{
		return wind;
	}

	fPoint GetGravity()
	{
		return gravity;
	}

private:

	fPoint gravity;
	List<RigidBody*> rigidBodies;
	fPoint wind = { 0,0 };
};

