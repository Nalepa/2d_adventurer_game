#include "Moving_Object.h"



Moving_Object::Moving_Object(const sf::Vector2f &size, const sf::Vector2f &position, const sf::IntRect &rect1, sf::Texture *texture, bool is_moving_in_x, bool is_moving_in_y, float x1, float x2, float y1, float y2):
	Object{size, position, rect1, texture}, is_moving_in_x(is_moving_in_x), is_moving_in_y(is_moving_in_y),
	x1(x1), x2(x2), y1(y1), y2(y2), speed(5), direction_x(true), direction_y(true)
{
}
void Moving_Object::move_platform()
{
	if (is_moving_in_x == true)
	{
		if (this->getPosition().x <= x1)
		{
   			direction_x = true;
			this->move(speed, 0);
		}
		else if (this->getPosition().x + this->getSize().y >= x2)
		{
			direction_x = false;
			this->move(-1 * speed, 0);
		}
		else
		{
			if (direction_x == true) this->move(speed, 0);
			else this->move(-1 * speed, 0);
		}
	}
	else // is_moving_in_y == true
	{
		if (this->getPosition().y <= y1)
		{
			direction_y = true;
			this->move(0, speed);
		}
		else if (this->getPosition().y + this->getSize().y >= y2)
		{
			direction_y = false;
			this->move(0, -1 * speed);
		}
		else
		{
			if (direction_y == true) this->move(0, speed);
			else this->move(0, -1 * speed);
		}
	}
}
bool Moving_Object::get_direction_x()
{
	return direction_x;
}
bool Moving_Object::get_direction_y()
{
	return direction_y;
}
bool Moving_Object::get_is_moving_in_x()
{
	return is_moving_in_x;
}
bool Moving_Object::get_is_moving_in_y()
{
	return is_moving_in_y;
}
Moving_Object::~Moving_Object()
{
}
