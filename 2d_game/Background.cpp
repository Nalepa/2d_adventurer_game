#include "Background.h"

										
Background::Background(sf::Vector2u window_size) : rect1{ 0, 0, window_size.x, 200 }, rect2{ 0, 0,  window_size.x, 200 }
{
	try
	{
		load_textures();
	}
	catch (std::string file_name)
	{
		Exceptions exception;
		exception.texture_exception(file_name);
	}

	texture1.setRepeated(true);
	sprite1.setPosition(0, 200);
	sprite1.setScale(5, 5);
	sprite1.setTexture(texture1);
	sprite1.setTextureRect(rect1);

	texture2.setRepeated(true);
	sprite2.setPosition(0, -500);
	sprite2.setScale(10, 10);
	sprite2.setTexture(texture2);
	sprite2.setTextureRect(rect2);

}
void Background::load_textures()
{
	if (!texture1.loadFromFile("background1.png"))
	{
		std::string exception = "background1.png";
		throw exception;
	}
	if (!texture2.loadFromFile("background2.png"))
	{
		std::string exception = "background2.png";
		throw exception;
	}
}
void Background::draw(sf::RenderWindow &window)
{
	window.draw(sprite1);
	window.draw(sprite2);
}

Background::~Background()
{
}
