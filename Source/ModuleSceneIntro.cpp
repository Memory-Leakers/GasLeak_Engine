#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"

iPoint position;

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	graphics = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

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
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
UpdateStatus ModuleSceneIntro::Update()
{
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) 
	{
		player.x-= 4;
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
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

	


	return UPDATE_CONTINUE;
}

UpdateStatus ModuleSceneIntro::PostUpdate() 
{

	App->renderer->CameraMove(playerCenter);
	App->renderer->DrawQuad(ground, 125, 0, 255, 255);
	App->renderer->DrawQuad(player, 125, 0, 125, 125);
	App->renderer->DrawQuad(plant, 255, 0, 255, 255);
	App->renderer->DrawLine(1250, 510, 1250, 300, 255, 0, 0);
	App->renderer->DrawLine(-50, 510, -50, 300, 0, 255, 0);
	

	return UPDATE_CONTINUE;
}
