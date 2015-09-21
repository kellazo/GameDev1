#ifndef __j1PHYSFS_H__
#define __j1PHYSFS_H__

#include "j1Module.h"



class j1Physfs : public j1Module
{
public:

	j1Physfs();

	// Destructor
	virtual ~j1Physfs();

	// Called before render is available
	bool Awake();

	// Called before quitting
	bool CleanUp();

	//OpenFile
	bool OpenFile(const char* file);
	bool LoadImagefromBuffer(const char* file);

private:
	//var calculate size
	Sint64  file_lenght;
	void* file_data;

	

};

#endif // __j1PHYSFS_H__