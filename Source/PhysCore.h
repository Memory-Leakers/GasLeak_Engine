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

	bool BoxColBox(RigidBody& b1, RigidBody& b2);

	bool CircleColCircle(RigidBody& b1, RigidBody& b2);

	bool BoxColCircle(RigidBody& b1, RigidBody& b2);

	void ResolveColForce(RigidBody& b1, RigidBody& b2, fPoint colPoint);

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

	fPoint CollisionPoint(RigidBody& b1, RigidBody& b2);

	fPoint CollisionDir(RigidBody& b1, fPoint colPoint);

private:

	fPoint gravity;

	float density = 1.0f;

	fPoint wind = { 0,0 };

	int resolveColForce = 5;

public:

	List<RigidBody*> rigidBodies;
};