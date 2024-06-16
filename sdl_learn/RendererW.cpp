#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RendererW.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const char* title, int w, int h): window(NULL), renderer(NULL) {

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		std::cout << "window failed to load" << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


}

void RenderWindow::clean_up() {
	SDL_DestroyWindow(window);

}

SDL_Texture* RenderWindow::loadTexture(const char* t_filename) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, t_filename);

	if (texture == NULL) {
		std::cout << "failed to load texture " << SDL_GetError() << std::endl;

	}

	return texture;
}

void RenderWindow::clear() {
	SDL_RenderClear(renderer);

}
void RenderWindow::render(Entity& p_entity, float scale) {

	SDL_Rect src;
	src.x = p_entity.get_curr_frame().x;
	src.y= p_entity.get_curr_frame().y;
	src.w = p_entity.get_curr_frame().w;
	src.h = p_entity.get_curr_frame().h;
	
	SDL_Rect dst;
	dst.x = p_entity.get_x();
	dst.y = p_entity.get_y();
	dst.w = p_entity.get_curr_frame().w *scale;
	dst.h = p_entity.get_curr_frame().h*scale;

	//std::cout << dst.x << std::endl;
	SDL_SetTextureBlendMode(p_entity.get_texture(), SDL_BLENDMODE_BLEND);
	SDL_RenderCopy(renderer, p_entity.get_texture(), &src, &dst);

}



void RenderWindow::display() {
	SDL_RenderPresent(renderer);

}

SDL_Renderer* RenderWindow::get_renderer() {
	return renderer;
}

void RenderWindow::render_map(Map& m) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 16; j++) {

			if (m.data[i][j] == 0) {
				continue;
			}

			SDL_Rect temp;
			temp.w = 32;
			temp.h = 8;
			temp.x = 0;
			temp.y = 0;

			Entity tile(23+(66*j), 40+(18*i), m.b1);
			tile.set_curr_frame(temp);

			switch (m.data[i][j]) {

			case 1:
				//fwerff
				tile.set_texture(m.b1);
				
				break;
			case 2:
				tile.set_texture(m.b2);
				
				break;
			case 3:
				tile.set_texture(m.b3);
				
				break;
			case 4:
				tile.set_texture(m.b4);
				
				break;
			case 5:
				tile.set_texture(m.b5);
				break;
			}

			render(tile, 2);
		}
	}
}
