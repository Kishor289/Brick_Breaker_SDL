#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Entity.hpp"



class Text {
public:
	Entity e;
	Text(std::string main_text, int font_size, SDL_Color f_color, std::string font_path);
	void gen_texture(SDL_Renderer* render__, float p_x, float p_y);
	void update_text(std::string new_text);
	void change_f_color(SDL_Color c);
	void change_f_size(int s);

private:
	std::string main_text;
	int font_size;
	SDL_Color font_color;
	TTF_Font* main_font;


};