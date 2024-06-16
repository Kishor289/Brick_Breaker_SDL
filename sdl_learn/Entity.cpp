#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Entity.hpp"

Entity::Entity() {
	text = NULL;
	x = 0;
	y = 0;
	curr_frame.x = 0;
	curr_frame.y = 0;
	curr_frame.w = 0;
	curr_frame.h = 0;
}
Entity::Entity(float x, float y, SDL_Texture* tex) : x(x), y(y) {
	text = tex;
	curr_frame.x = 0;
	curr_frame.y = 0;
	curr_frame.w = 32;
	curr_frame.h = 8;
}

float Entity::get_x() {
	return x;

}
float Entity::get_y() {
	return y;

}
SDL_Texture* Entity::get_texture() {
	return text;

}

SDL_Rect Entity::get_curr_frame() {
	return curr_frame;
}

void Entity::set_x(float x_) {
	x = x_;
}

void Entity::set_y(float y_) {
	y = y_;
}

void Entity::set_curr_frame(SDL_Rect c_f) {
	curr_frame = c_f;
}

void Entity::set_texture(SDL_Texture* t) {
	text = t;
}