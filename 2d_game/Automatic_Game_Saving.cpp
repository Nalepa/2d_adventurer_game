#include "Automatic_Game_Saving.h"


Automatic_Game_Saving::Automatic_Game_Saving(Main_Character* main_character, Character_Stats* character_stats, Environment* environment, std::string file_name):
	Game_Saving(main_character, character_stats, environment, file_name),
	auto_save_time_period(10.0f)
{
	text.setString("Auto Save");
}

void Automatic_Game_Saving::auto_save()
{
	if (auto_save_clock.getElapsedTime().asSeconds() >= auto_save_time_period)
	{
		save();
		auto_save_clock.restart();
	}
}

void Automatic_Game_Saving::statement_support(sf::RenderWindow& window, const float& x, const float& y)
{
	if (statement_clock.getElapsedTime().asSeconds() <= statement_time_period)
	{
		text.setPosition(x - 900, y - 100);
		window.draw(text);
	}
	else statement_displaying = false;
}

Automatic_Game_Saving::~Automatic_Game_Saving()
{
}
