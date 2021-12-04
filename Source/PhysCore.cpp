#include "PhysCore.h"
#include <algorithm>

PhysCore::PhysCore(fPoint gravity)
{
	this->gravity = gravity;
}

PhysCore::~PhysCore()
{
	rigidBodies.clearPtr();
}

void PhysCore::Update(float simulationTime)
{
	for (int i = 0; i < rigidBodies.count(); i++)
	{
		// Step #0 Reset acceleration and forces

		rigidBodies[i]->ResetForces();

		// Step #1 Calculate Forces (TotalForces = GravityForce + AdditionalForce)

		//	gravity
		rigidBodies[i]->AddForceToCenter(gravity * rigidBodies[i]->gravityScale * rigidBodies[i]->GetMass());

		//	Drag	(0.5 * density * relative velocity square * surface * Drag coeficient)
		fPoint dragForce;
		fPoint relativeVelocity;
		float relativeVelocityModule;
		float magnitudDrag;

		// Calcular velocidad relativa entre viento y body
		relativeVelocity.x = wind.x -rigidBodies[i]->GetLinearVelocity().x;
		relativeVelocity.y = wind.y -rigidBodies[i]->GetLinearVelocity().y;

		// Calcular el modulo de la velocidad relativa
		relativeVelocityModule = relativeVelocity.Module();

		// Calcular el magnitud del drag
		magnitudDrag = 0.5f * density * rigidBodies[i]->surface * pow(relativeVelocityModule,2) * rigidBodies[i]->GetDragCoheficient();

		fPoint nor = relativeVelocity.Normalize();

		// Calcular la fuerza de drag
		dragForce = nor * magnitudDrag;

		rigidBodies[i]->AddForceToCenter(dragForce);

		rigidBodies[i]->totalForce = rigidBodies[i]->additionalForce;
		rigidBodies[i]->additionalForce = { 0,0 };

		// Step #2 Calculate Newton's Second law (acceleration)
		rigidBodies[i]->acceleration = rigidBodies[i]->totalForce / rigidBodies[i]->mass;

		// Step #3 Integrate with Verlet
		rigidBodies[i]->position += rigidBodies[i]->velocity * simulationTime + rigidBodies[i]->acceleration * (simulationTime * simulationTime * 0.5f);
		rigidBodies[i]->velocity += rigidBodies[i]->acceleration * simulationTime;
	}

	// Despues de mover todos los objetos comparan la colision.
	for (int i = 0; i < rigidBodies.count(); i++)
	{
		// Step #4: solve collisions
		CheckCollision(rigidBodies[i]);
	}
}

bool PhysCore::CheckCollision(RigidBody* body)
{
	//Check if body is colliding with any other body on rigidBodies
	for (int i = 0; i < rigidBodies.count(); i++)
	{
		if (i != rigidBodies.find(body))
		{
			BoxCOlBox(*body, *rigidBodies[i]);
		}
	}
	// Collision Circle && Rect
	//https://www.cnblogs.com/shadow-lr/p/BoxCircleIntersect.html
	return true;
}

void PhysCore::AddRigidBody(RigidBody* body)
{
	rigidBodies.add(body);
}

void PhysCore::DeleteRigidBody(RigidBody* body)
{
	rigidBodies.del(rigidBodies.At(rigidBodies.find(body)));
}

bool PhysCore::BoxCOlBox(RigidBody& b1, RigidBody& b2)
{
	// Check b1 & b2 is RECT
	if (b1.shape != ShapeType::RECT || b2.shape != ShapeType::RECT) return false;

	// No collision case
	if (b1.position.x > b2.position.x + b2.width ||
		b1.position.x + b1.width < b2.position.x ||
		b1.position.y > b2.position.y + b2.height ||
		b1.position.y + b1.height < b2.position.y)
	{
		for (int i = 0; i < b1.collisionList.count(); i++)
		{
			if (rigidBodies.find(b1.collisionList[i]) == rigidBodies.find(&b2))
			{
				printf("BOX COL BOX EXIT\n");
				b1.collisionList[i] = nullptr;
				b1.collisionList.SubstractSize();
			}
		}

		return false;
	}

	// Collision case
	for (int i = 0; i < b1.collisionList.count(); i++)
	{
		if (rigidBodies.find(b1.collisionList[i]) == rigidBodies.find(&b2))
		{
			printf("BOX COL BOX STAY\n");
			return true;
		}
	}
	b1.collisionList.add(&b2);
	printf("BOX COL BOX ENTER\n");
	return true;
}

bool PhysCore::CircleCOlCircle(RigidBody& b1, RigidBody& b2)
{


	return false;
}

bool PhysCore::BoxCOlCircle(RigidBody& b1, RigidBody& b2)
{
	RigidBody circ;
	RigidBody rect;
	fPoint offset;

	if (b1.shape == RECT)
	{
		rect = b1;
		circ = b2;
	}
	else {
		rect = b2;
		circ = b1;
	}

	offset = circ.GetPosition() - rect.GetPosition();


	offset.x = std::less(offset.x, -2, 2);


	return false;
}


fPoint Clamp(float val, float min, float max)
{
	return MAX(min, MIN(max, val));
}
