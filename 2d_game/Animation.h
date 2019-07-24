#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Animation
{
	sf::Vector2u current_image;
	sf::Vector2f simple_image_size;
	unsigned int begin_number, end_number;
	sf::IntRect rect;
	float totaltime, change_time;
	unsigned int animation_counter;
public:
	Animation(int row, float change_time, unsigned int begin_number, unsigned int end_number, sf::Vector2f simple_image_size);
	void Upload(float &delta_time, sf::RectangleShape &shape, bool right);
	bool single_animation_upload(float& delta_time, sf::RectangleShape& shape, bool right);
	void single_animtion_restart();
	unsigned int get_animation_counter();
	~Animation();
};

