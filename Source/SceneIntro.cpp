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

	// Test
	plant.x = 500;
	plant.y = 410;
	plant.w = 50;
	plant.h = 70;

	ground.x = -1000;
	ground.y = 510;
	ground.h = 250;
	ground.w = 3400;

	position.x = 50;
	position.y = 459;

	player.x = position.x;
	player.y = position.y;
	player.w = 50;
	player.h = 50;

	world = new PhysCore({ 0, 10});

	body = new RigidBody({ 300, 300 }, RigidBodyType::DYNAMIC, rect.w, rect.h);

	body2 = new RigidBody({ 300, 200 }, RigidBodyType::DYNAMIC, rect2.w, rect2.h);

	body3 = new RigidBody({ 500, 300 }, RigidBodyType::DYNAMIC, 10);

	body4 = new RigidBody({ 500, 200 }, RigidBodyType::DYNAMIC, 10);

	body2->SetGravityScale(2.0f);

	body4->SetGravityScale(2.0f);

	world->AddRigidBody(body);

	world->AddRigidBody(body2);

	world->AddRigidBody(body3);

	world->AddRigidBody(body4);
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
	if(_app->input->GetKey(SDL_SCANCODE_C) == KEY_REPEAT)
	{
		world->Update(1.0 / 60);
	}
	if (_app->input->GetKey(SDL_SCANCODE_V) == KEY_DOWN)
	{
		world->Update(1.0 / 60);
	}

	//printf_s("Position: %f\t %f\n", body->GetPosition().x, body->GetPosition().y);

	if (_app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		player.x-= 4;
	}

	if (_app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
	{
		body->AddForceToCenter({ 0, -20 });
	}

	if (_app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		player.x+= 4;
	}

	int playerCenterX = (player.w / 2) + player.x;
	int plantCenter = (plant.w / 2) + plant.x;
	int distance = abs(playerCenterX - plantCenter);
	if(distance < 35)
	{
		plant.y = 375 + distance;

	}

	//1250 , -50
	if (player.x >= 1250) {
		player.x = -49;
	}
	else if (player.x <= -50)
	{
		player.x = 1249;
	}

	playerCenter = { -playerCenterX,0 };

	return true;
}

bool SceneIntro::PostUpdate()
{

	rect.x = body->GetPosition().x;
	rect.y = body->GetPosition().y;

	_app->renderer->DrawQuad(rect, 255, 0,0, 255);

	rect2.x = body2->GetPosition().x;
	rect2.y = body2->GetPosition().y;

	_app->renderer->DrawQuad(rect2, 255, 255, 0, 255);

	_app->renderer->DrawCircle(body3->GetPosition().x, body3->GetPosition().y, body3->GetRadius(), 255, 0, 0);
	_app->renderer->DrawCircle(body4->GetPosition().x, body4->GetPosition().y, body4->GetRadius(), 0, 255, 0);

	return true;
}
