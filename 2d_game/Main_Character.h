#pragma once
#include <forward_list>
#include <list>
#include "Moving_Object.h"
#include "Animation.h"
#include "Character_Stats.h"
#include"Exceptions.h"
class Main_Character
{
	const sf::Vector2f shape_size;
	sf::RectangleShape shape, right, left, top, down, sword;
	sf::Texture texture;
	sf::IntRect rect;
	Animation run, stoppage, jump, crouch, attack;
	bool movement_direction, is_jumping, is_gravity, on_the_ground;
	bool left_hurt, right_hurt, hurt, is_attacking, on_the_trampoline, active_adrenalin;
	float jump_speed, max_jump_speed, moving_in_x_speed, movement_speed;
	Character_Stats character_stats;
	sf::Clock adrenalin_clock, hurt_clock;

public:
	Main_Character();
	void movement(float &delta_time, sf::Clock &jump_clock);
	void draw(sf::RenderWindow &window, const float &, const float & );
	void move(const float &x, const float &y);
	void set_position(const float &x, const float &y);
	void add_money(int value);
	void add_health(int value);
	void add_adrenalin(int value);
	void add_key(int value);
	unsigned int get_keys();
	void subtract_health(int value);
	sf::RectangleShape & get_shape();
	sf::RectangleShape & get_right();
	sf::RectangleShape & get_left();
	sf::RectangleShape& get_sword();
	sf::RectangleShape & get_top();
	sf::RectangleShape & get_down();
	bool get_on_the_ground();
	void set_on_the_ground(bool state);
	bool get_on_the_trampoline();
	void set_on_the_trampoline(bool state);
	bool get_is_jumping();
	void set_is_jumping(bool state);
	bool get_is_gravity();
	void set_is_gravity(bool state);
	float get_movement_speed();
	void set_initial_jump_speed();
	float get_moving_in_x_speed();
	bool get_left_hurt();
	void set_left_hurt(bool state);
	bool get_right_hurt();
	void set_right_hurt(bool state);
	void delete_keys();
	sf::Vector2f get_centre();
	bool get_alive();
	bool get_movement_direction();
	Character_Stats* get_character_stats();
	unsigned int get_animation_counter();
	unsigned int get_strenght();
	bool get_active_adrenalin();
	void set_hurt_color();
	void complete_adrenalin();
	Main_Character* get_main_character();
	void set_movement_direction(bool value);
	void set_required_number_of_keys(unsigned int value);
	~Main_Character();
};

		






