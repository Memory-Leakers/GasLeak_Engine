#pragma once
#include "Scene.h"
#include "Animation.h"
#include "p2DynArray.h"
#include "Globals.h"

class PhysCore;
class RigidBody;

#define BOUNCER_TIME 200

struct Bouncer
{
	Bouncer() : body(NULL), texture(NULL), hit_timer(0), fx(0)
	{}

	PhysBody* body;
	SDL_Texture* texture;
	Uint32 hit_timer;
	uint fx;
};

enum lightTypes
{
	tiny,
	medium,
	big
};

class ModuleSceneIntro;

//struct Light
//{
//	Light() : body(NULL), texture(NULL), on(false), fx(0)
//	{}
//
//	Light(ModuleSceneIntro* physics, int x, int y, lightTypes type);
//
//	lightTypes type;
//	PhysBody* body;
//	SDL_Texture* texture;
//	bool on;
//	uint fx;
//	int x, y;
//};

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