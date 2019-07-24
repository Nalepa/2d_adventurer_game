#pragma once
#include "Object.h"
#include "Animation.h"
enum Item_type{coin, heart, key};
class Item :public Object
{
	Animation animation;
	Item_type type;
	int value;
public:
	Item(Item_type type, const sf::Vector2f &position, sf::Texture *texture);
	Item_type get_type();
	int get_value();
	void Update(float &delta_time);
	~Item();
};

