#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <vector>

#include "RendererW.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Map.h"
#include "Text.hpp"
#include "Music.hpp"




int main(int argc, char* argv[]) {
	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) > 0) {
		std::cout << "SDL_Init has failed . Error: " << SDL_GetError() << std::endl;
		return -1;
	}

	if (SDL_Init(IMG_INIT_PNG)) {
		std::cout << "SDL_Init has failed . Error: " << SDL_GetError() << std::endl;
		return -1;
	}

	if (TTF_Init() == -1) {
		std::cout << "SDL_ttf failed to launch. Error : " << TTF_GetError() << std::endl;
		return -1;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout<<"SDL_mixer could not initialize! Error:" << Mix_GetError()<<std::endl;
	}
	

	RenderWindow Window("GAME", 1100, 640);


	SDL_Texture* bottombar = Window.loadTexture("extras/kai2.png");
	SDL_Texture* bg = Window.loadTexture("extras/123.jpg");
	SDL_Texture* b1 = Window.loadTexture("extras/b1.png");
	SDL_Texture* b2 = Window.loadTexture("extras/b2.png");
	SDL_Texture* b3 = Window.loadTexture("extras/b3.png");
	SDL_Texture* b4 = Window.loadTexture("extras/b4.png");
	SDL_Texture* b5 = Window.loadTexture("extras/b5.png");

	SDL_Texture* ball = Window.loadTexture("extras/ball.png");

	Music music_;
	music_.add_music("extras/music.wav");


	Entity ball_e(500, 0, ball);
	SDL_Rect temp_;
	temp_.w = 10;
	temp_.h = 10;
	temp_.x = 0;
	temp_.y = 0;
	ball_e.set_curr_frame(temp_);

	Entity bg_entity(0, 0, bg);
	SDL_Rect temp;
	temp.w = 284;
	temp.h = 177;
	temp.x = 0;
	temp.y = 0;
	bg_entity.set_curr_frame(temp);


	Map level0(b1, b2, b3, b4, b5);

	SDL_Color c;
	c.r = 255;
	c.g = 255;
	c.b = 255;
	c.a = 255;


	Text t1("SCORE : 100", 25, c,"extras/f.ttf");

	t1.gen_texture(Window.get_renderer(), 500, 8);


	//use padding of 2 pixels between blocks
	std::vector<Entity> entities {};


	Player player1(23, 600, bottombar, 15, 1000);

	bool gameOn = true;
	SDL_Event event;


	while (gameOn) {
		

		while (SDL_PollEvent(&event)) {
			//checking if exit button was pressed
			if (event.type == SDL_QUIT) {
				gameOn = false;
			}

			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_RIGHT) {
					//move player
					player1.move(Right, horizontal, gameOn);
				}
				else if (event.key.keysym.sym == SDLK_LEFT) {
					player1.move(Left, horizontal, gameOn);
				}
				else if (event.key.keysym.sym == SDLK_DOWN) {
					player1.move(Down, vertical, gameOn);
				}
				else if (event.key.keysym.sym == SDLK_UP) {
					player1.move(Up, vertical, gameOn);
				}
				else {
				}
			}


		}

		ball_e.set_y(ball_e.get_y()+3);

		Window.clear();
		Window.render(bg_entity, 6);

		Window.render_map(level0);
		//looping over and rendering all textures in entities
		for (Entity& i : entities) {
			Window.render(i, 2);
		}

		Window.render(player1, 3);
		Window.render(ball_e, 1.6);
		Window.render(t1.e, 1);


		Window.display();

	}

	Window.clean_up();

	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
	Mix_Quit();

	return 0;

}
