#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Physfs.h"
#include "SDL/include/SDL.h"

#include "PhysFS\include\physfs.h"
#pragma comment( lib, "PhysFS/libx86/physfs.lib" )

j1Physfs::j1Physfs() : j1Module()
{
	
}

// Destructor
j1Physfs::~j1Physfs()
{}

// Called before render is available
bool j1Physfs::Awake()
{
	LOG("Loading init Physfs lib");
	bool ret = true;
	// load Physfs lib

	int init = PHYSFS_init(0);

	if (init == 0)
	{
		LOG("j1Physfs could not initialize! Physfs ERROR: %s\n", PHYSFS_getLastError());
		ret = false;
	}

	LOG("Init Physfs lib success");
	return ret;
}

// Called before quitting
bool j1Physfs::CleanUp()
{
	LOG("Destroying Physfs lib");
	PHYSFS_init(0);

	return true;

	
}