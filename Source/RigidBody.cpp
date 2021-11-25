#include "RigidBody.h"

RigidBody::RigidBody()
{

}

RigidBody::RigidBody(fPoint pos, RigidBodyType type)
{
	this->position = pos;
	this->type = type;
	//this->shape = shape;
}

RigidBody::RigidBody(RigidBody& copy)
{
	this->position = copy.position;
	this->acceleration = copy.acceleration;
	this->velocity = copy.velocity;
	this->friction = copy.friction;
	this->drag = copy.drag;
	this->mass = copy.mass;
	this->restitution = copy.restitution;
	this->rotation = copy.rotation;
	this->type = copy.type;
}

void RigidBody::AddForceToCenter(fPoint force)
{
	additionalForce += force;
}

void RigidBody::ResetForces()
{
	acceleration = totalForce = { 0,0 };
}
