#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
class Graphical_Character_Stats
{
	const float stats_width = 20.0f;
	std::vector<sf::RectangleShape>graphic_stats{ 4 };
	std::vector<sf::Text>text{ 2 };
	sf::Font font;
public:
	Graphical_Character_Stats();
	void update_graphic_stats(unsigned int current_health, unsigned int max_health, unsigned int current_adrenalin, unsigned int max_adrenalin, unsigned int money, unsigned int keys, unsigned int required_number_of_keys);
	void draw(sf::RenderWindow& window, const float& view_centre_x, const float& view_centre_y);
	~Graphical_Character_Stats();
};

