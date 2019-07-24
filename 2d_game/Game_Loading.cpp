#include "Game_Loading.h"
#pragma warning( disable : 6001)

Game_Loading::Game_Loading(Main_Character* main_character, Character_Stats* character_stats, Environment* environment, std::string file_name):
	main_character(main_character), character_stats(character_stats), environment(environment), file_name(file_name)
{
}

void Game_Loading::load_game()
{
	try
	{
		file.open(file_name);
		if (file.good())
		{
			file >> main_character;
			file >> character_stats;
			file >> environment;
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

Game_Loading::~Game_Loading()
{
}

std::istream& operator >>(std::istream& input, Main_Character* main_character)
{
	float x, y;
	input >> x;
	input >> y;
	main_character->set_position(x, y);
	bool value;
	input >> value;
	main_character->set_movement_direction(value);
	input >> value;
	main_character->set_on_the_ground(value);
	input >> value;
	main_character->set_is_gravity(value);
	input >> value;
	main_character->set_is_jumping(value);
	return input;
}
std::istream& operator >>(std::istream& input, Character_Stats* character_stats)
{
	unsigned int value;
	input >> value;
	character_stats->set_current_health(value);
	input >> value;
	character_stats->set_max_health(value);
	input >> value;
	character_stats->set_current_adrenalin(value);
	input >> value;
	character_stats->set_max_adrenalin(value);
	input >> value;
	character_stats->set_strength(value);
	input >> value;
	character_stats->set_armor(value);
	input >> value;
	character_stats->set_money(value);
	input >> value;
	character_stats->set_keys(value);

	return input;
}
std::istream& operator >>(std::istream& input, Environment* environment)
{
	int value;
	input >> value;
	environment->set_level_number(value);
	if (value == 1) environment->create_level_1();
	else if  (value == 2) environment->create_level_2();
	input >> value;
	environment->set_difficulty_level(value);
	input >> value;
	environment->set_gate_during_the_opening(value);

	int type;
	float x, y;
	input >> type;

	while (type != -1 )
	{
		input >> x;
		input >> y;
		environment->add_item(x, y, static_cast<Item_type>(type));
		input >> type;
	}
	input >> value;
	environment->set_enemy_current_health(value);

	return input;
}
