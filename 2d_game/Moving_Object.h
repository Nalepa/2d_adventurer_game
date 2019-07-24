#pragma once
#include "Object.h"
class Moving_Object : public Object
{
	bool is_moving_in_x, is_moving_in_y, direction_x, direction_y; 
	float x1, x2, y1, y2;
	int speed;
public:
	Moving_Object(const sf::Vector2f &size, const sf::Vector2f &position, const sf::IntRect &rect1, sf::Texture *texture, bool is_moving_in_x, bool is_moving_in_y, float x1, float x2, float y1, float y2);
	void move_platform();
	bool get_direction_x();
	bool get_direction_y();
	bool get_is_moving_in_x();
	bool get_is_moving_in_y();
	~Moving_Object();
};

