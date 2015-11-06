// ----------------------------------------------------
// j1Timer.cpp
// Fast timer with milisecons precision
// ----------------------------------------------------

#include "j1Timer.h"
#include "SDL\include\SDL_timer.h"

// ---------------------------------------------
j1Timer::j1Timer()
{
	Start();
}

// ---------------------------------------------
void j1Timer::Start()
{
	// TODO 1: Fill Start(), Read(), ReadSec() methods
	// they are simple, one line each!
	//demana que et digui  els ticks quan crides la funcio start
	started_at = SDL_GetTicks();
	
}

// ---------------------------------------------
uint32 j1Timer::Read() const
{

	//vols saber els ticks en aquell moment d la execucio i es els tiques que tnes ara - els inicials
		return SDL_GetTicks() - started_at;
}

// ---------------------------------------------
float j1Timer::ReadSec() const
{
	//convertir els milisegons a segons, et retorna un valor float
	return Read()/1000.0f;
}