#include "PhysCore.h"

PhysCore::PhysCore(fPoint gravity)
{
}

PhysCore::~PhysCore()
{
	rigidBodies.clearPtr();
}

void PhysCore::Update(float simulationTime)
{
	for (int i = 0; i < rigidBodies.count(); i++)
	{
		printf("RigidBody%d\n", i);
	}
	// Step #0 Reset acceleration and forces
	
	// Step #1 Calculate Forces (TotalForces = GravityForce + AdditionalForce)
	
	// Step #2 Calculate Newton's Second law (acceleration)
	//ball.ax = ball.fx / ball.mass;
	//ball.ay = ball.fy / ball.mass;
	
	// Step #3 Integrate

	/*
	void integrator_velocity_verlet(Ball &ball, double dt)
{
	ball.x += ball.vx * dt + 0.5 * ball.ax * dt * dt;
	ball.y += ball.vy * dt + 0.5 * ball.ay * dt * dt;
	ball.vx += ball.ax * dt;
	ball.vy += ball.ay * dt;
}
	
	*/

	// Step #4: solve collisions
	// CheckCollisions()
}

bool PhysCore::CheckCollision(RigidBody* body)
{
	//Check if body is colliding with any other body on rigidBodies
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
