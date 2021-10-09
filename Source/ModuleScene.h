#ifndef __MODULESCENE_H__
#define __MODULESCENE_H__

#include "Module.h"
#include "Globals.h"
#include "Scene.h"


#define SCENES_NUM 9


enum SCENE_NUM
{
// Escenas totales
};

class ModuleScene : public Module
{
public:

	// Constructor
	ModuleScene(Application* app, bool start_enabled = true);

	// Destructor
	~ModuleScene();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start();

	UpdateStatus PreUpdate();

	// Called at the middle of the application loop
	// Updates the scene's background animations
	UpdateStatus Update();

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	UpdateStatus PostUpdate();


	bool ChangeCurrentScene(uint index, int frames);


	bool CleanUp();

public:

	int lastSceneID;

private:

	int newScene;


};

#endif // __MODULESCENE_H__

