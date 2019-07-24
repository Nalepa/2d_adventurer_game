#include "Gate.h"



Gate::Gate(unsigned int& required_number_of_keys, const sf::Vector2f& position, sf::Texture* texture) :
	Object{ sf::Vector2f{ 350, 350 }, position, sf::IntRect{0, 0, 62, 67}, texture },
	required_number_of_keys(required_number_of_keys),
	animation(0, 0.2f, 0, 3, sf::Vector2f{ 62, 67 }),
	is_open{false}, during_the_opening{false}
{
}

bool Gate::update_single_animation(float& delta_time)
{
	if (animation.single_animation_upload(delta_time, *this, true) == true) return true;
	else return false;
}

unsigned int Gate::get_required_number_of_keys()
{
	return required_number_of_keys;
}

void Gate::draw(sf::RenderWindow& window)
{
	window.draw(*this);
}

bool Gate::get_is_open()
{
	return is_open;
}

void Gate::set_is_open(bool state)
{
	is_open = state;
}

bool Gate::get_during_the_opening()
{
	return during_the_opening;
}

void Gate::set_during_the_opening(bool state)
{
	during_the_opening = state;
}

Gate::~Gate()
{
}
