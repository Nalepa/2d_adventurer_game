#include "Graphical_Enemy_Stats.h"



Graphical_Enemy_Stats::Graphical_Enemy_Stats(float max_health)
{
	graphics_stats.emplace_back(sf::RectangleShape{ sf::Vector2f{static_cast<float>(max_health), graphics_stats_width} });
	graphics_stats[0].setOutlineThickness(3);
	graphics_stats[0].setFillColor(sf::Color::White);
	graphics_stats.emplace_back(sf::RectangleShape{ sf::Vector2f{static_cast<float>(max_health), graphics_stats_width} });
	graphics_stats[1].setOutlineThickness(3);
	graphics_stats[1].setFillColor(sf::Color::Red);
}

void Graphical_Enemy_Stats::draw(sf::RenderWindow& window, const float& position_x, const float& position_y)
{
	graphics_stats[0].setPosition(position_x, position_y - 30);
	graphics_stats[1].setPosition(position_x, position_y - 30);
	window.draw(graphics_stats[0]);
	window.draw(graphics_stats[1]);
}

void Graphical_Enemy_Stats::update_graphics_stats(float current_health)
{
	graphics_stats[1].setSize(sf::Vector2f{ static_cast<float>(current_health), graphics_stats_width });
}

Graphical_Enemy_Stats::~Graphical_Enemy_Stats()
{
	graphics_stats.clear();
}
