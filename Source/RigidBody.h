#pragma once
#include "Point.h"

enum RigidBodyType
{
	STATIC,
	DYNAMIC,
	KINEMATIC,
};

enum ShapeType
{
	CIRCLE,
	RECT,
};

class RigidBody 
{
private:
	// Position
	fPoint position = { 0.0, 0.0 };

	//Properties
	float restitution = 0.0f;
	float friction = 0.0f;
	float drag = 0.0f;
	float mass = 1.0f;
	fPoint velocity = { 0.0f, 0.0f };
	fPoint acceleration = { 0.0, 0.0 };
	float rotation = 0.0f;
	float gravityScale = 1.0f;

	RigidBodyType type = STATIC;
	ShapeType shape = RECT;

	float maximumVelocity = 1000.0f;

	fPoint totalForce = { 0.0, 0.0 };
	fPoint additionalForce = { 0.0, 0.0 };

public:
	RigidBody();

	RigidBody(fPoint pos, RigidBodyType type, ShapeType shape);

	RigidBody(RigidBody& copy);

	void AddForceToCenter(fPoint force);

	fPoint GetPosition()
	{
		return position;
	}
	void SetPosition(fPoint pos)
	{
		this->position = pos;
	}
	float GetRestitution()
	{
		return restitution;
	}
	void SetRestitution(float res)
	{
		this->restitution = res;
	}

	float GetFriction()
	{
		return friction;
	}
	void SetFriction(float f)
	{
		this->friction = f;
	}

	float GetMass()
	{
		return mass;
	}
	void SetMass(float mass)
	{
		this->mass = mass;
	}

	float GetDrag()
	{
		return drag;
	}
	void SetDrag(float drag)
	{
		this->drag = drag;
	}

	fPoint GetLinearVelocity()
	{
		return velocity;
	}
	void SetLinearVelocity(fPoint velocity)
	{
		velocity.x > maximumVelocity ? maximumVelocity : velocity.x < -maximumVelocity ? -maximumVelocity : velocity.x;
		velocity.y > maximumVelocity ? maximumVelocity : velocity.y < -maximumVelocity ? -maximumVelocity : velocity.y;

		this->velocity = velocity;
	}

	float GetRotation()
	{
		return rotation;
	}
	void SetRotation(float rotation)
	{
		this->rotation = rotation;
	}
private:
	
	void ResetForces();



	friend class PhysCore;

};

