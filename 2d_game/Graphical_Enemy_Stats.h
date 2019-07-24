#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class Graphical_Enemy_Stats
{
	const float graphics_stats_width = 10.0f;
	std::vector<sf::RectangleShape>graphics_stats;
public:
	Graphical_Enemy_Stats(float max_health);
	void draw(sf::RenderWindow& window, const float& position_x, const float& position_y);
	void update_graphics_stats(float current_health);
	~Graphical_Enemy_Stats();
};

