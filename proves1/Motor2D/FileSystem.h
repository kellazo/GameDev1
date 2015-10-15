#ifndef __fileSYSTEM_H__
#define __fileSYSTEM_H__

#include "j1Module.h"

class FileSystem : public j1Module
{
public:

	FileSystem();

	// Destructor
	virtual ~FileSystem();

	// Called before render is available
	bool Awake();

	// Called before quitting
	bool CleanUp();

	

private:


};

#endif // __fileSYSTEM_H__