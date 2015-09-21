#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Physfs.h"
#include "SDL/include/SDL.h"

#include "SDL_image/include/SDL_image.h"
#include "PhysFS\include\physfs.h"
#pragma comment( lib, "PhysFS/libx86/physfs.lib" )
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )

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

bool j1Physfs::OpenFile(const char* file)
{
	if (0 == PHYSFS_exists(file))
	{
		return false; //file doesn't exist
	}

	PHYSFS_file* myfile = PHYSFS_openRead(file);

	// Get the lenght of the file
	file_lenght = PHYSFS_fileLength(myfile);

	// Get the file data.
	file_data = new Uint32[file_lenght];

	int length_read = PHYSFS_read(myfile, file_data, 1, file_lenght);

	if (length_read != (int)file_lenght)
	{
		delete[] file_data;
		file_data = 0;
		return false;
	}

	PHYSFS_close(myfile);


	return true;
}

bool j1Physfs::LoadImagefromBuffer(const char* file)
{
	OpenFile(file);

	SDL_RWops *rw = SDL_RWFromMem(file_data, file_lenght);

	SDL_Surface* surface = IMG_Load_RW(rw, 0);

	SDL_FreeRW(rw);

	return true;
}