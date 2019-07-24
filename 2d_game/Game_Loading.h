#pragma once
#include <fstream>
#include "Main_Character.h"
#include "Environment.h"
#include "Exceptions.h"
class Game_Loading
{
	Character_Stats* character_stats;
	Main_Character* main_character;
	Environment* environment;
	std::ifstream file;
	std::string file_name;
public:
	Game_Loading(Main_Character* main_character, Character_Stats* character_stats, Environment* environment, std::string file_name);
	void load_game();
	~Game_Loading();
};

std::istream& operator >>(std::istream& input, Main_Character* main_character);
std::istream& operator >>(std::istream& input, Character_Stats* character_stats);
std::istream& operator >>(std::istream& input, Environment* environment);


