#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Map {

public:
	Map(SDL_Texture* b1, SDL_Texture* b2, SDL_Texture* b3, SDL_Texture* b4, SDL_Texture* b5);
	void load(int arr[10][16]);


public:
	int data[16][10];
	SDL_Texture* b1;
	SDL_Texture* b2;
	SDL_Texture* b3;
	SDL_Texture* b4;
	SDL_Texture* b5;


};
