#include "Text.hpp"

Text::Text(std::string main_text, int font_size, SDL_Color f_color, std::string font_path):main_text(main_text), font_size(font_size), font_color(f_color){
	main_font = TTF_OpenFont(font_path.c_str(), font_size);
	if (main_font == NULL) {
		std::cout << "failed to load font. Error:  " << TTF_GetError() << std::endl;
	}

}


void Text::gen_texture(SDL_Renderer* r, float p_x, float p_y) {
	SDL_Surface* t_surface = TTF_RenderText_Blended(main_font, main_text.c_str(), font_color);
	if (t_surface == NULL) {
		std::cout << "Error in generating surface from font. Error: " << TTF_GetError() << std::endl;

	}
	else {
		SDL_Texture* t_texture = SDL_CreateTextureFromSurface(r, t_surface);
		if (t_texture == NULL) {
			std::cout << "failed to load texture from surface" << std::endl;
		}
		else {
			e = Entity(p_x, p_y, t_texture);
			SDL_Rect temp2;
			temp2.x = 0;
			temp2.y = 0;
			temp2.w = t_surface->w;
			temp2.h = t_surface->h;
			e.set_curr_frame(temp2);

		}
	}

	SDL_FreeSurface(t_surface);

}
void Text::update_text(std::string new_text) {
	main_text = new_text;
}

void Text::change_f_color(SDL_Color c) {
	font_color = c;
}

void Text::change_f_size(int s) {
	font_size = s;
}
