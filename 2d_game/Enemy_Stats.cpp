#include "Enemy_Stats.h"



Enemy_Stats::Enemy_Stats(unsigned int max_health, unsigned int strength):
	max_health(max_health), strength(strength), current_health(max_health),
	alive(true), death_animation(false),
	attack_animation(false),
	graphical_enemy_stats(max_health)
{
}

void Enemy_Stats::draw(sf::RenderWindow& window, const float& position_x, const float& position_y)
{
	graphical_enemy_stats.draw(window, position_x, position_y);
}

bool Enemy_Stats::subtrack_health(unsigned int value)
{
	if (current_health <= value)
	{
		alive = false;
		death_animation = true;
		current_health = 0;
	}
	else current_health -= value;
	graphical_enemy_stats.update_graphics_stats(current_health);
	return true;
}

bool Enemy_Stats::get_alive()
{
	return alive;
}

bool Enemy_Stats::get_death_animation()
{
	return death_animation;
}

void Enemy_Stats::set_death_animation(bool value)
{
	death_animation = value;
}

bool Enemy_Stats::get_attack_animation()
{
	return attack_animation;
}

void Enemy_Stats::set_attack_animation(bool value)
{
	attack_animation = value;
}

void Enemy_Stats::set_strength(unsigned int value)
{
	strength = value;
}

unsigned int Enemy_Stats::get_strength()
{
	return strength;
}

unsigned int Enemy_Stats::get_current_health()
{
	return current_health;
}

void Enemy_Stats::set_current_health(unsigned int value)
{
	current_health = value;
	if (current_health == 0)
	{
		alive = false;
		death_animation = true;
		current_health = 0;
	}
	graphical_enemy_stats.update_graphics_stats(current_health);
}

Enemy_Stats::~Enemy_Stats()
{
}
