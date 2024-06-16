#include "Player.hpp"

Player::Player(float x, float y, SDL_Texture* tex, int s, int h) : Entity(x, y, tex), speed(s), size(h){
}

void Player::move(Direction d, axis a, bool &gameOn) {

	if (this->get_x() + d*speed <= 998 && this->get_x()+d*speed >= 8) {
		if (a == horizontal) {
			this->set_x(static_cast<int>(this->get_x() + d * speed));
			//std::cout << this->get_x() << std::endl;
		}
	}



	
}