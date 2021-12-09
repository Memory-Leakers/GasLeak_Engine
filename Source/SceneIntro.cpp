#include "Globals.h"
#include "Application.h"
#include "SceneIntro.h"
#include "PhysCore.h"

iPoint position;

SceneIntro::SceneIntro(Application* app) : Scene(app)
{}

SceneIntro::~SceneIntro()
{}

// Load assets
bool SceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	_app->renderer->camera.x = _app->renderer->camera.y = 0;

	world = new PhysCore({ 0, 10});

	body = new RigidBody({ 200, 600 }, RigidBodyType::WATER, rect.w, rect.h);
	
	body2 = new RigidBody({ 300, 240 }, RigidBodyType::STATIC, rect2.w, rect2.h);

	body3 = new RigidBody({ 300, 200 }, RigidBodyType::DYNAMIC, 20);
	//body3->SetMass(20);
	body3->SetRestitution(0.7f);
	body3->SetDragCoeficient(0);
	body3->SetGravityScale(4);
	body3->SetHydrodynamicDragCoeficient(0.3f);

	//body4 = new RigidBody({ 445, 500 }, RigidBodyType::STATIC, 10);

	//body4->SetGravityScale(2.0f);

	world->AddRigidBody(body);

	world->AddRigidBody(body2);

	world->AddRigidBody(body3);

	//world->AddRigidBody(body4);
	return ret;
}

// Load assets
bool SceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	RELEASE(world);

	return true;
}

// Update: draw background
bool SceneIntro::Update()
{
	world->Update(1.0 / 60);

	if(_app->input->GetKey(SDL_SCANCODE_C) == KEY_REPEAT)
	{
		world->Update(1.0 / 60);
	}
	if (_app->input->GetKey(SDL_SCANCODE_V) == KEY_DOWN)
	{
		world->Update(1.0 / 60);
	}

	if (_app->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		body3->AddForceToCenter({ 0, -200 });
		//body3->SetLinearVelocity({ body3->GetLinearVelocity().x,-200 });
	}

	if (_app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		body3->AddForceToCenter({ -200, 0 });
		//body3->SetLinearVelocity({ -200,0 });
	}

	if (_app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		body3->AddForceToCenter({ 200, 0 });
		//body3->SetLinearVelocity({ 200,0 });
	}

	if (_app->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		body3->AddForceToCenter({ 0, 200 });
		//body3->SetLinearVelocity({ 0,200 });
	}

	return true;
}

bool SceneIntro::PostUpdate()
{
	rect.x = body->GetPosition().x;
	rect.y = body->GetPosition().y;

	_app->renderer->DrawQuad(rect, 0, 255,0, 155);

	rect2.x = body2->GetPosition().x;
	rect2.y = body2->GetPosition().y;

	_app->renderer->DrawQuad(rect2, 255, 255, 0, 255);

	_app->renderer->DrawCircle(body3->GetPosition().x, body3->GetPosition().y, body3->GetRadius(), 255, 0, 0);

	//_app->renderer->DrawCircle(body4->GetPosition().x, body4->GetPosition().y, body4->GetRadius(), 0, 255, 0);

	return true;
}