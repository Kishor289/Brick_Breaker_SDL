#pragma once

#include "Entity.hpp"
#include "Utils.hpp"
#include <iostream>

class Player :public Entity {
public:
	Player(float x, float y, SDL_Texture* tex, int s, int h);

	void move(Direction d, axis a, bool& gameOn);

private:
	int size;
	int speed;
};
