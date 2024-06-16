#pragma once

#include <SDL_mixer.h>
#include <string>
#include <vector>


class Music
{
public:
	Music();
	void add_music(std::string m_path);
	void add_sound(std::string s_path);


private:
	std::vector<Mix_Music*> music_list;
	std::vector<Mix_Chunk*> sound_list;

};

