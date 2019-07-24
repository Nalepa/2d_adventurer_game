#include "Game_Saving.h"



Game_Saving::Game_Saving(Main_Character* main_character, Character_Stats* character_stats, Environment* environment, std::string file_name):
	main_character(main_character), character_stats(character_stats), environment(environment),
	statement_displaying(false), file_name(file_name),
	statement_time_period(3.0f)
{
	font.loadFromFile("RevMiniPixel.ttf");
	text.setFont(font);
	text.setString("Manual Save");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(30);
}

void Game_Saving::save()
{
	statement_displaying = true;
	statement_clock.restart();
	try
	{
		file.open(file_name);
		if (file.good())
		{
			file << main_character;
			file << character_stats;
			file << environment;
		}
		else throw file_name;
		file.close();
	}
	catch (std::string file_name)
	{
		Exceptions exception;
		exception.save_file_exception(file_name);
	}
}

void Game_Saving::statement_support(sf::RenderWindow& window, const float& x, const float& y)
{
	if (statement_clock.getElapsedTime().asSeconds() <= statement_time_period)
	{
		text.setPosition(x - 900, y - 200);
		window.draw(text);
	}
	else statement_displaying = false;
}

bool Game_Saving::get_statement_displying()
{
	return statement_displaying;
}

Game_Saving::~Game_Saving()
{
}

std::ostream& operator <<(std::ostream& output, Main_Character *main_character)
{
	output << main_character->get_shape().getPosition().x << std::endl;
	output << main_character->get_shape().getPosition().y << std::endl;
	output << main_character->get_movement_direction() << std::endl;
	output << main_character->get_is_gravity() << std::endl;
	output << main_character->get_on_the_ground() << std::endl;
	output << main_character->get_is_jumping() << std::endl;
	return output;
}

std::ostream& operator<<(std::ostream& output, Character_Stats* character_stats)
{
	output << character_stats->get_current_health() << std::endl;
	output << character_stats->get_max_health() << std::endl;
	output << character_stats->get_current_adrenalin() << std::endl;
	output << character_stats->get_max_adrenalin() << std::endl;
	output << character_stats->get_strenght() << std::endl;
	output << character_stats->get_armor() << std::endl;
	output << character_stats->get_money() << std::endl;
	output << character_stats->get_keys() << std::endl;

	return output;
}

std::ostream& operator<<(std::ostream& output, Environment *environment)
{
	output << environment->get_level_number() << std::endl;
	output << environment->get_difficulty_level() << std::endl;
	output << environment->get_gate_is_open() << std::endl;
	for (auto i : environment->get_items())
	{
		output << i.get_type() << std::endl;
		output << i.getPosition().x << std::endl;
		output << i.getPosition().y << std::endl;
	}
	output << -1 << std::endl;
	output << environment->get_enemy_current_health() << std::endl;
	return output;
}
