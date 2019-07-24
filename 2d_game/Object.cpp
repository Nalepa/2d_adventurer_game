#include "Object.h"



Object::Object(const sf::Vector2f &size, const sf::Vector2f &position, const sf::IntRect &rect1 , sf::Texture *texture) : RectangleShape{ size }, rect(rect1)
{
	setTexture(texture);
	setTextureRect(rect1);
	setPosition(position);
	//setOutlineThickness(2);
}
Object::Object(const sf::Vector2f &size, const sf::Vector2f &position) : RectangleShape{ size }
{
	setPosition(position);
	setFillColor(sf::Color{ 25, 44, 59, 255 });
	//setOutlineThickness(2);
}

Object::~Object()
{
}