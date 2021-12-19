#pragma once
#include "Scene.h"
#include "Animation.h"
#include "p2DynArray.h"
#include "Globals.h"

class PhysCore;
class RigidBody;

#define BOUNCER_TIME 200

class ModuleSceneIntro;

class SceneIntro : public Scene
{
public:
	SceneIntro(Application* app);
	~SceneIntro();

	bool Start();
	bool Update();
	bool PostUpdate();
	bool CleanUp() override;

public:

	SDL_Rect rect = { 10,10,500,500 };
	SDL_Rect rect2 = { 10,10,20,20 };

	RigidBody* body;
	RigidBody* body2;
	RigidBody* body3;
	RigidBody* body4;

	PhysCore* world;
};