// ----------------------------------------------------
// j1Module.h
// Interface for all engine modules
// ----------------------------------------------------

#ifndef __j1MODULE_H__
#define __j1MODULE_H__

#include "p2SString.h"
#include "PugiXml\src\pugixml.hpp"

class j1App;

class j1Module
{
public:

	j1Module() : active(false)
	{}

	void Init()
	{
		active = true;
	}

	// Called before render is available
	virtual bool Awake(pugi::xml_node&)
	{
		return true;
	}

	// Called before the first frame
	virtual bool Start()
	{
		return true;
	}

	// Called each loop iteration
	virtual bool PreUpdate()
	{
		return true;
	}

	// Called each loop iteration
	virtual bool Update(float dt)
	{
		return true;
	}

	// Called each loop iteration
	virtual bool PostUpdate()
	{
		return true;
	}

	// Called before quitting
	virtual bool CleanUp()
	{
		return true;
	}

	// TODO 2: Create new virtual methods to Load and Save
	//virtual methods significa crear a cada modul el metode load and save definirlos com el awake, el render ja esta falta omplir
	virtual bool Load()
	{
		return true;
	}
	virtual bool Save() const
	{
		return true;
	}

public:

	p2SString	name;
	bool		active;

};

#endif // __j1MODULE_H__