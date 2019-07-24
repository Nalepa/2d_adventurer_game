#include "Character_Stats.h"
#pragma warning( disable : 26495)


Character_Stats::Character_Stats() :
	alive{ true }
{
	set_initial_values();
	update_graphic_stats();
}

void Character_Stats::set_initial_values()
{
	max_health = 100;
	current_health = max_health;
	max_adrenalin = 100;
	current_adrenalin = max_adrenalin;
	strength = 2;
	armor = 1;
	money = keys = 0;
}
void Character_Stats::add_money(int value)
{
	money += value;
	update_graphic_stats();
}

unsigned int Character_Stats::get_money()
{
	return money;
}

void Character_Stats::add_health(int value)
{
	current_health += value;
	if (current_health > max_health) current_health = max_health;
	update_graphic_stats();
}

void Character_Stats::subtract_health(int value)
{
	if (alive == true)
	{
		if (current_health <= value)
		{
			//game over
			current_health = 0;
			alive = false;
		}
		else current_health -= value;
		update_graphic_stats();
	}
}

unsigned int Character_Stats::get_current_health()
{
	return current_health;
}

unsigned int Character_Stats::get_max_health()
{
	return max_health;
}

void Character_Stats::add_adrenalin(int value)
{
	current_adrenalin += value;
	if (current_adrenalin > max_adrenalin) current_adrenalin = max_adrenalin;
	update_graphic_stats();
}

unsigned int Character_Stats::get_current_adrenalin()
{
	return current_adrenalin;
}

unsigned int Character_Stats::get_max_adrenalin()
{
	return max_adrenalin;
}

unsigned int Character_Stats::get_strenght()
{
	return strength;
}

unsigned int Character_Stats::get_armor()
{
	return armor;
}

void Character_Stats::add_key(int value)
{
	keys += value;
	update_graphic_stats();
}

void Character_Stats::delete_keys()
{
	keys -= required_number_of_keys;
	update_graphic_stats();
}

unsigned int Character_Stats::get_keys()
{
	return keys;
}

unsigned int Character_Stats::get_required_number_of_keys()
{
	return required_number_of_keys;
}

bool Character_Stats::improve_health(unsigned int health_price)
{
	if (money >= health_price)
	{
		money -= health_price;
		max_health += 10;
		update_graphic_stats();
		return true;
	}
	else return false;
}

bool Character_Stats::improve_adrenalin(unsigned int adrenalin_price)
{
	if (money >= adrenalin_price)
	{
		money -= adrenalin_price;
		max_adrenalin += 10;
		update_graphic_stats();
		return true;
	}
	else return false;
}

bool Character_Stats::improve_strength(unsigned int strength_price)
{
	if (money >= strength_price)
	{
		money -= strength_price;
		++strength;
		update_graphic_stats();
		return true;
	}
	else return false;
}

bool Character_Stats::improve_armor(unsigned int armor_price)
{
	if (money >= armor_price)
	{
		money -= armor_price;
		++armor;
		update_graphic_stats();
		return true;
	}
	else return false;
}

bool Character_Stats::get_alive()
{
	return alive;
}
void Character_Stats::update_graphic_stats()
{
	graphical_character_stats.update_graphic_stats(current_health, max_health, current_adrenalin, max_adrenalin, money, keys, required_number_of_keys);
}

void Character_Stats::draw(sf::RenderWindow &window, const float &view_centre_x, const float &view_centre_y)
{
	graphical_character_stats.draw(window, view_centre_x, view_centre_y);
}
Character_Stats* Character_Stats::get_character_stats()
{
	return this;
}

bool Character_Stats::use_adrenalin()
{
	int adrenalin_cost = 50;
	if (current_adrenalin >= adrenalin_cost)
	{
		current_adrenalin -= adrenalin_cost;
		update_graphic_stats();
		return true;
	}
	else return false;
}

void Character_Stats::complete_adrenalin()
{
	current_adrenalin = max_adrenalin;
	update_graphic_stats();
}

void Character_Stats::set_current_health(unsigned int value)
{
	current_health = value;
	update_graphic_stats();
}

void Character_Stats::set_max_health(unsigned int value)
{
	max_health = value;
	update_graphic_stats();
}

void Character_Stats::set_current_adrenalin(unsigned int value)
{
	current_adrenalin = value;
	update_graphic_stats();
}

void Character_Stats::set_max_adrenalin(unsigned int value)
{
	max_adrenalin = value;
	update_graphic_stats();
}

void Character_Stats::set_strength(unsigned int value)
{
	strength = value;
}

void Character_Stats::set_armor(unsigned int value)
{
	armor = value;
}

void Character_Stats::set_money(unsigned int value)
{
	money = value;
	update_graphic_stats();
}

void Character_Stats::set_keys(unsigned int value)
{
	keys = value;
	update_graphic_stats();
}

void Character_Stats::set_required_number_of_keys(unsigned int value)
{
	required_number_of_keys = value;
	update_graphic_stats();
}

Character_Stats::~Character_Stats()
{
}
