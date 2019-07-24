#pragma once
#include "Main_Character.h"
#include "Environment.h"
#include <string>
#include <fstream>
#include "Exceptions.h"
class Game_Saving
{
protected:
	Character_Stats* character_stats;
	Main_Character* main_character;
	Environment* environment;
	std::string file_name;
	std::ofstream file;
	sf::Text text;
	sf::Font font;
	bool statement_displaying;
	const float statement_time_period;
	sf::Clock statement_clock;
public:
	Game_Saving(Main_Character* main_character, Character_Stats* character_stats, Environment* environment, std::string file_name);
	void save();
	virtual void statement_support(sf::RenderWindow &window, const float &x,  const float &y);
	bool get_statement_displying();
	~Game_Saving();
};

 std::ostream& operator <<(std::ostream& output, Main_Character* main_character);
 std::ostream& operator <<(std::ostream& output, Character_Stats* character_stats);
 std::ostream& operator <<(std::ostream& output, Environment* environment);

