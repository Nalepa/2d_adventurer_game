#pragma once
#include "Exceptions.h"
class Background
{
	sf::Sprite sprite1, sprite2;
	sf::Texture texture1, texture2;
	sf::IntRect rect1, rect2;
public:
	Background(sf::Vector2u window_size);
	void load_textures();
	void draw(sf::RenderWindow &window);
	~Background();
};

