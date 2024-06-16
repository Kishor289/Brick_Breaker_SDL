#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


class Entity {
public:
	Entity();
	Entity(float x, float y, SDL_Texture* tex);
	float get_x();
	float get_y();

	void set_x(float x_);
	void set_y(float y_);

	void set_curr_frame(SDL_Rect c_f);
	void set_texture(SDL_Texture* t);

	SDL_Texture* get_texture();
	SDL_Rect get_curr_frame();

private:
	float x, y;
	SDL_Rect curr_frame;
	SDL_Texture* text;

};