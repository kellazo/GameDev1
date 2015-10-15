#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "FileSystem.h"

#include "SDL/include/SDL.h"


#include "SDL_image/include/SDL_image.h"
#include "PhysFS/include/physfs.h"

#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )
#pragma comment( lib, "PhysFS/libx86/physfs.lib" )


FileSystem::FileSystem() : j1Module()
{
	name.create("FileSystem");
}

// Destructor
FileSystem::~FileSystem()
{}

// Called before render is available
bool FileSystem::Awake()
{
	LOG("Loading FileSystem");
	bool ret = true;
	PHYSFS_init(0);
	if (PHYSFS_init(0) != NULL)
	{
		LOG("Could not create FileSystem! PhysFS_Error: %s\n", PHYSFS_getLastError());
		ret = false;
	}

	return ret;
}

// Called before quitting
bool FileSystem::CleanUp()
{
	LOG("Freeing PhysFS, closing FileSystem");
	PHYSFS_deinit();

	
	return true;
}

