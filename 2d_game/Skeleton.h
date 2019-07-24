#pragma once
#include "Enemy.h"
class Skeleton : public Enemy
{
	Animation run, attack, death;
	sf::RectangleShape body;
public:
	Skeleton(float x1, float x2, sf::Vector2f position, sf::Texture *texture);
	virtual void movement(float& delta_time);
	virtual void collision(Main_Character* character);
	virtual void being_attacked(Main_Character* character);
	virtual void attacking(Main_Character* character, float& delta_time);
	virtual void draw(sf::RenderWindow &window);
	virtual void death_animation(float& delta_time);
	virtual void attack_animation(float& delta_time);
	void move(const float& x, const float& y);
	~Skeleton();
};

