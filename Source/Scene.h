#ifndef _SCENE_H_
#define _SCENE_H_

#include "Application.h"

class Scene
{
protected:

	int ID;

	Application* _app;

public:
	// Constructor
	Scene(Application* app);

	// Destructor
	~Scene();

	virtual bool Start();

	virtual bool PreUpdate();

	virtual bool Update();

	virtual bool PostUpdate();

	int getID()
	{
		return ID;
	}

	virtual bool CleanUp();

	int lastID = 0;

};


#endif //_SCENE_H_

