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
	Read();
	
}

// ---------------------------------------------
uint32 j1Timer::Read() const
{
	
	uint32 lastTime = 0, currentTime;
	
		currentTime = SDL_GetTicks();
		if (currentTime > lastTime + 1000) {
			printf("Report: %d\n", currentTime);
			lastTime = currentTime;
		}

	return lastTime;
}

// ---------------------------------------------
float j1Timer::ReadSec() const
{

	return 0.0f;
}