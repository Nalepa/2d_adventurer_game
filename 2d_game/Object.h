#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <utility>
class Object: public sf::RectangleShape
{
protected:
	sf::IntRect rect;
public:
	Object(const sf::Vector2f &size, const sf::Vector2f &position, const sf::IntRect &rect1, sf::Texture *texture);
	Object(const sf::Vector2f &, const sf::Vector2f &);
	~Object();
};

