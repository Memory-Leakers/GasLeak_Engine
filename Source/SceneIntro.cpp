#include "Globals.h"
#include "Application.h"
#include "SceneIntro.h"

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

	return ret;
}

// Load assets
bool SceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
bool SceneIntro::Update()
{
	if (_app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) 
	{
		player.x-= 4;
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

	_app->renderer->CameraMove(playerCenter);
	_app->renderer->DrawQuad(ground, 125, 0, 255, 255);
	_app->renderer->DrawQuad(player, 125, 0, 125, 125);
	_app->renderer->DrawQuad(plant, 255, 0, 255, 255);
	_app->renderer->DrawLine(1250, 510, 1250, 300, 255, 0, 0);
	_app->renderer->DrawLine(-50, 510, -50, 300, 0, 255, 0);
	

	return true;
}
