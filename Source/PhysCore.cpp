#include "PhysCore.h"

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
		rigidBodies[i]->AddForceToCenter({ gravity.x * rigidBodies[i]->GetMass(), gravity.y * rigidBodies[i]->GetMass() });

		//	Drag	(0.5 * density * relative velocity square * surface * Drag coeficient)
		fPoint dragForce;
		dragForce.x = wind.x -rigidBodies[i]->GetLinearVelocity().x;
		dragForce.y = wind.y -rigidBodies[i]->GetLinearVelocity().y;
		dragForce *= dragForce;
		dragForce *= 0.5f * 1.0f * 1.0f * rigidBodies[i]->GetDrag();
		rigidBodies[i]->AddForceToCenter(dragForce);

		rigidBodies[i]->totalForce = rigidBodies[i]->additionalForce;
		rigidBodies[i]->additionalForce = { 0,0 };

		// Step #2 Calculate Newton's Second law (acceleration)
		rigidBodies[i]->acceleration = rigidBodies[i]->totalForce / rigidBodies[i]->mass;

		// Step #3 Integrate with Verlet

		fPoint test = rigidBodies[i]->acceleration * (simulationTime * simulationTime * 0.5f);

		rigidBodies[i]->position += rigidBodies[i]->velocity * simulationTime + test;
		rigidBodies[i]->velocity += rigidBodies[i]->acceleration * simulationTime;

		// Step #4: solve collisions
		// CheckCollisions()
	}
}

bool PhysCore::CheckCollision(RigidBody* body)
{
	//Check if body is colliding with any other body on rigidBodies

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
	return false;
}

bool PhysCore::CircleCOlCircle(RigidBody& b1, RigidBody& b2)
{
	return false;
}

bool PhysCore::BoxCOlCircle(RigidBody& b1, RigidBody& b2)
{
	return false;
}
