#pragma once
#include <vector>
#include <list>
#include <forward_list>
#include <memory>
#include "Moving_Object.h"
#include "Main_Character.h"
#include "Gate.h"
#include "Item.h"
#include "Skeleton.h"
#include "Exceptions.h"
enum Difficulty_Level { easy, normal, hard };

class Environment
{
	std::forward_list<Object>collison_objects;
	std::forward_list<Moving_Object>moving_platforms;
	std::forward_list<Object>spikes;
	std::forward_list<Object>decorative_objects;
	std::list<Item>items;
	std::unique_ptr<Gate>gate;
	std::vector<sf::Texture> textures;
	unsigned int required_number_of_keys;
	std::unique_ptr<Enemy>enemy;
	Difficulty_Level difficulty_level;
	int spikes_hurt, level_number;
public:
	Environment();
	void load_textures();
	void create_level_1();
	void create_level_1_items();
	void create_level_2();
	void delete_enviroment();
	void draw(sf::RenderWindow &window, float &delta_time);
	void move_platform();
	inline int rect_ground(float);
	inline int rect_spikes(float);
	inline int rect_stones(float);
	void collision(Main_Character *character);
	void item_collision(Main_Character *character);
	void moving_platforms_collision(Main_Character *character);
	void gate_collision(Main_Character* character);
	void hurtful_collision(Main_Character *character, sf::Clock &jump_clock, sf::Clock &hurt_clock);
	void gravity(Main_Character *character);
	void enemy_support(Main_Character* character, float &delta_time);
	unsigned int get_required_number_of_keys();
	void set_difficulty_level(int value);
	Difficulty_Level get_difficulty_level();
	void set_difficulty_values();
	Environment* get_environment();
	int get_level_number();
	void set_level_number(int value);
	std::list<Item>& get_items();
	unsigned int get_enemy_current_health();
	void set_enemy_current_health(unsigned int value);
	void add_item(const float& x, const float& y, Item_type item_type);
	void set_gate_during_the_opening(bool value);
	bool get_gate_is_open();
	~Environment();
};

