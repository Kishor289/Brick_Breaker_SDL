#include "Music.hpp"

Music::Music() {
}

void Music::add_music(std::string m_path) {
	Mix_Music* temp = Mix_LoadMUS(m_path.c_str());
	music_list.push_back(temp);
}

void Music::add_sound(std::string s_path) {
	Mix_Chunk* temp = Mix_LoadWAV(s_path.c_str());
	sound_list.push_back(temp);
}




