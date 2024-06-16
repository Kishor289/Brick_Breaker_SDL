#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"
#include "Map.h"


class RenderWindow {
public:
	RenderWindow(const char* title, int w, int h);
	SDL_Texture* loadTexture(const char* t_filename);
	void clear();
	void render(Entity& p_entity, float scale); 
	void render_map(Map& m);
	void clean_up();
	void display();
	SDL_Renderer* get_renderer();
	 

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

};