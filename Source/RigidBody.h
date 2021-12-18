#pragma once
#include "Point.h"
#include "List.h"

enum class RigidBodyType
{
	STATIC,
	DYNAMIC,
	KINEMATIC,
	WATER
};

enum class ShapeType
{
	CIRCLE,
	RECT
};	

enum class COL_TYPE
{
	NONE = 0,
	COLLISION,
	TRIGGER
};

class RigidBody 
{
private:
	// Position
	fPoint position = { 0.0, 0.0 };
	fPoint lastPosition = { 0.0,0.0 };

	// Properties
	float restitution = 0.0f;
	float friction = 0.0f;
	float coefficientDrag = 0.0f;
	float hydrodynamicDrag = 0.3f;
	float mass = 1.0f;
	fPoint velocity = { 0.0f, 0.0f };
	fPoint acceleration = { 0.0, 0.0 };
	float rotation = 0.0f;
	float gravityScale = 1.0f;
	float surface = 1.0f;
	float width = 1.0f;
	float height = 1.0f;
	float radius = 1.0f;

	// Tags
	RigidBodyType type = RigidBodyType::STATIC;
	ShapeType shape = ShapeType::RECT;
	COL_TYPE colType = COL_TYPE::COLLISION;

	float maximumVelocity = 1000.0f;

	fPoint totalForce = { 0.0, 0.0 };
	fPoint additionalForce = { 0.0, 0.0 };

	List<RigidBody*> collisionList;
public:
	RigidBody();

	~RigidBody();

	RigidBody(fPoint pos, RigidBodyType type,float width,float height, COL_TYPE colType = COL_TYPE::COLLISION);

	RigidBody(fPoint pos, RigidBodyType type, float radius, COL_TYPE colType = COL_TYPE::COLLISION);

	RigidBody(RigidBody& copy);

	void OnCollisionEnter(RigidBody* col);

	void OnCollisionStay(RigidBody* col);

	void OnCollisionExit(RigidBody* col);

	void OnTriggerEnter(RigidBody* col);

	void OnTriggerStay(RigidBody* col);

	void OnTriggerExit(RigidBody* col);

	void AddForceToCenter(fPoint force);

	// Check if point is contain in this body shape
	bool Contains(fPoint pos)
	{
		if (shape == ShapeType::RECT)
		{
			if (pos.x >= position.x - width / 2 && pos.x <= position.x + width / 2 &&
				pos.y >= position.y - height / 2 && pos.y <= position.y + height / 2)
			{
				return true;
			}
		}
		else
		{
			if (sqrt(pow(position.x - pos.x, 2) + pow(position.y - pos.y, 2)) <= radius)
			{
				return true;
			}
		}

		return false;
	}

	// Get & Set
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

	float GetDragCoeficient()
	{
		return coefficientDrag;
	}
	void SetDragCoeficient(float drag)
	{
		this->coefficientDrag = drag;
	}

	float GetHydrodynamicDragCoeficient()
	{
		return hydrodynamicDrag;
	}
	void SetHydrodynamicDragCoeficient(float hydrodrag)
	{
		this->hydrodynamicDrag = hydrodrag;
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

	void SetGravityScale(float gravityScale)
	{
		this->gravityScale = gravityScale;
	}
	float GetGravityScale()
	{
		return gravityScale;
	}

	float GetRotation()
	{
		return rotation;
	}
	void SetRotation(float rotation)
	{
		this->rotation = rotation;
	}

	float GetRadius()
	{
		return radius;
	}
private:
	
	void ResetForces();

	friend class PhysCore;
};