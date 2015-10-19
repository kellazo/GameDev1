#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1FileSystem.h"
#include "j1Scene.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
	player_x = player_y = 10;
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake(pugi::xml_node& config)
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{	//EXERCISE 5
	App->map->Load("map.tmx");

	debug_tex = App->tex->Load("textures/path.png");
	
	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	// Save / Load 
	if(App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		App->LoadGame("save_game.xml");

	if(App->input->GetKey(SDL_SCANCODE_K) == KEY_DOWN)
		App->SaveGame("save_game.xml");

	// Move the camera
	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->render->camera.y += 1;

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->render->camera.y -= 1;

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->render->camera.x += 1;

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->render->camera.x -= 1;

	// Move the player

	//Exercise 4
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
		//int width = App->map->data.width;
		//int height = App->map->data.width;
		//int tile_x = App->map->data.tile_width;
		//int tile_y = App->map->data.tile_height;

		//player_y = (((App->map->data.width / 2) * App->map->data.tile_width) - ((App->map->data.width / 2)*App->map->data.tile_height));

		player_y++;

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		player_y--;

	if(App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)
		player_x--;


	if(App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN)
		player_x ++;

	// Map render
	App->map->Draw();

	// Player placeholder
	iPoint p = App->map->MapToWorld(player_x, player_y);
	App->render->Blit(debug_tex, p.x, p.y);

	// Set Title
	int x, y;
	App->input->GetMousePosition(x, y);
	iPoint map_coordinates = App->map->WorldToMap(x - App->render->camera.x, y - App->render->camera.y);
	p2SString title("Map:%dx%d Tiles:%dx%d Tilesets:%d Tile:%d,%d",
					App->map->data.width, App->map->data.height,
					App->map->data.tile_width, App->map->data.tile_height,
					App->map->data.tilesets.count(),
					map_coordinates.x, map_coordinates.y);

	App->win->SetTitle(title.GetString());
	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
