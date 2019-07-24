#pragma once
#include "Game_Saving.h"
class Automatic_Game_Saving :
	public Game_Saving
{
	sf::Clock auto_save_clock;
	float auto_save_time_period;
public:
	Automatic_Game_Saving(Main_Character* main_character, Character_Stats* character_stats, Environment* environment, std::string file_name);
	void auto_save();
	virtual void statement_support(sf::RenderWindow& window, const float& x, const float& y);
	~Automatic_Game_Saving();
};

