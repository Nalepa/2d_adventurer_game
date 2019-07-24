#pragma once
#include "Animation.h"
#include "Enemy_Stats.h"
#include "Main_Character.h"
class Enemy
{
protected:
	const sf::Vector2f shape_size;
	Enemy_Stats enemy_stats;
	sf::RectangleShape shape;
	float x1, x2, movement_speed;
	bool movement_direction;
public:
	Enemy(float x_size, float y_size, float max_health, float strength);
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void movement(float& delta_time) = 0;
	virtual void collision(Main_Character* character) = 0;
	virtual void being_attacked(Main_Character* character) = 0;
	virtual void attacking(Main_Character* character, float& delta_time) = 0;
	virtual void death_animation(float& delta_time) = 0;
	virtual void attack_animation(float& delta_time) = 0;
	void set_strength(unsigned int value);
	void set_current_health(unsigned int value);
	unsigned int get_current_health();
	~Enemy();
};

