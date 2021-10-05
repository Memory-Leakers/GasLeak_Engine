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

	ground.x = 0;
	ground.y = 510;
	ground.h = 250;
	ground.w = 1200;


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
	

	return UPDATE_CONTINUE;
}

UpdateStatus ModuleSceneIntro::PostUpdate() 
{
	App->renderer->DrawQuad(ground, 125, 0, 255, 255);
	App->renderer->DrawQuad(player, 125, 0, 125, 125);
	App->renderer->DrawQuad(plant, 255, 0, 255, 255);

	return UPDATE_CONTINUE;
}
