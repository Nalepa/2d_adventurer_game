#pragma once
#include "Object.h"
#include "Animation.h"
class Gate :
	public Object
{
	Animation animation;
	const unsigned int required_number_of_keys;
	bool is_open, during_the_opening;
public:
	Gate(unsigned int& required_number_of_keys, const sf::Vector2f& position, sf::Texture* texture);
	bool update_single_animation(float &delta_time);
	unsigned int get_required_number_of_keys();
	void draw(sf::RenderWindow& window);
	bool get_is_open();
	void set_is_open(bool state);
	bool get_during_the_opening();
	void set_during_the_opening(bool state);
	~Gate();
};

