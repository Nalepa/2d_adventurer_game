#pragma once
#include"Graphical_Character_Stats.h"
class Character_Stats
{
	unsigned int current_health, max_health, current_adrenalin, max_adrenalin, strength, armor, money, keys, required_number_of_keys;
	bool alive;
	Graphical_Character_Stats graphical_character_stats;
public:
	Character_Stats();

	// current_health
	unsigned int get_current_health();
	void set_current_health(unsigned int value);
	void add_health(int value);
	void subtract_health(int value);

	//max_health
	unsigned int get_max_health(); 
	void set_max_health(unsigned int value);
	bool improve_health(unsigned int health_price);
	
	//current_adrenalin
	unsigned int get_current_adrenalin();
	void set_current_adrenalin(unsigned int value);
	void add_adrenalin(int value);
	bool improve_adrenalin(unsigned int adrenalin_price);
	bool use_adrenalin();
	void complete_adrenalin();

	//max_adrenalin
	unsigned int get_max_adrenalin();
	void set_max_adrenalin(unsigned int value);

	//strength
	unsigned int get_strenght();
	void set_strength(unsigned int value);
	bool improve_strength(unsigned int strenght_price);

	//armor
	unsigned int get_armor();
	void set_armor(unsigned int value);
	bool improve_armor(unsigned int armor_price);

	//money
	unsigned int get_money();
	void set_money(unsigned int value);
	void add_money(int value);

	//keys
	unsigned int get_keys();
	void set_keys(unsigned int value);
	void add_key(int value);
	void delete_keys();

	unsigned int get_required_number_of_keys();
	void set_required_number_of_keys(unsigned int value);

	void set_initial_values();
	bool get_alive();
	void update_graphic_stats();
	void draw(sf::RenderWindow &window, const float &x, const float &y);
	Character_Stats* get_character_stats();
	~Character_Stats();
};
