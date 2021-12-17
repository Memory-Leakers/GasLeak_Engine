#include "RigidBody.h"

RigidBody::RigidBody()
{

}

RigidBody::~RigidBody()
{
}

RigidBody::RigidBody(fPoint pos, RigidBodyType type, float width, float height, COL_TYPE colType)
{
	this->position = pos;
	this->type = type;
	this->shape = ShapeType::RECT;
	this->width = width;
	this->height = height;
	this->colType = colType;
}

RigidBody::RigidBody(fPoint pos, RigidBodyType type, float radius, COL_TYPE colType)
{
	this->position = pos;
	this->type = type;
	this->shape = ShapeType::CIRCLE;
	this->radius = radius;
	this->colType = colType;
}

RigidBody::RigidBody(RigidBody& copy)
{
	this->position = copy.position;
	this->acceleration = copy.acceleration;
	this->velocity = copy.velocity;
	this->friction = copy.friction;
	this->coefficientDrag = copy.coefficientDrag;
	this->mass = copy.mass;
	this->restitution = copy.restitution;
	this->rotation = copy.rotation;
	this->type = copy.type;
	this->width = copy.width;
	this->height = copy.height;
	this->radius = copy.radius;
	this->shape = copy.shape;
	this->gravityScale = copy.gravityScale;
}

void RigidBody::OnCollisionEnter(RigidBody* col)
{
	printf("Col enter\n");
}

void RigidBody::OnCollisionStay(RigidBody* col)
{
	printf("Col stay\n");
}

void RigidBody::OnCollisionExit(RigidBody* col)
{
	printf("Col exit\n");
}

void RigidBody::AddForceToCenter(fPoint force)
{
	additionalForce += force;
}

void RigidBody::ResetForces()
{
	acceleration = totalForce = { 0,0 };
}
