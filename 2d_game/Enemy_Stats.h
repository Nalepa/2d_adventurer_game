#pragma once
#include "Graphical_Enemy_Stats.h"
class Enemy_Stats
{
	unsigned int current_health, max_health, strength;
	bool death_animation, alive, attack_animation;
	Graphical_Enemy_Stats graphical_enemy_stats;
public:
	Enemy_Stats(unsigned int max_health, unsigned int strength);
	void draw(sf::RenderWindow& window, const float& position_x, const float& position_y);
	bool subtrack_health(unsigned int value);
	bool get_alive();
	bool get_death_animation();
	void set_death_animation(bool value);
	bool get_attack_animation();
	void set_attack_animation(bool value);
	void set_strength(unsigned int value);
	unsigned int get_strength();
	unsigned int get_current_health();
	void set_current_health(unsigned int value);
	~Enemy_Stats();
};

