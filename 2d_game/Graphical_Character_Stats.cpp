#include "Graphical_Character_Stats.h"

Graphical_Character_Stats::Graphical_Character_Stats()
{
	graphic_stats[0].setOutlineThickness(3);
	graphic_stats[0].setOutlineColor(sf::Color::White);
	graphic_stats[1].setFillColor(sf::Color::Red);
	graphic_stats[2].setOutlineThickness(3);
	graphic_stats[2].setOutlineColor(sf::Color::White);
	graphic_stats[3].setFillColor(sf::Color::Blue);

	font.loadFromFile("RevMiniPixel.ttf");

	text[0].setFont(font);
	text[0].setFillColor(sf::Color::White);
	text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
}

void Graphical_Character_Stats::update_graphic_stats(unsigned int current_health, unsigned int max_health, unsigned int current_adrenalin, unsigned int max_adrenalin, unsigned int money, unsigned int keys, unsigned int required_number_of_keys)
{
	graphic_stats[0].setSize(sf::Vector2f{ static_cast<float>(max_health), stats_width });
	graphic_stats[1].setSize(sf::Vector2f{ static_cast<float>(current_health), stats_width });
	graphic_stats[2].setSize(sf::Vector2f{ static_cast<float>(max_adrenalin), stats_width });
	graphic_stats[3].setSize(sf::Vector2f{ static_cast<float>(current_adrenalin), stats_width });
	text[0].setString("Coins: " + std::to_string(money));
	text[1].setString("Keys: " + std::to_string(keys) + "/" + std::to_string(required_number_of_keys));
}

void Graphical_Character_Stats::draw(sf::RenderWindow& window, const float& view_centre_x, const float& view_centre_y)
{
	graphic_stats[0].setPosition(view_centre_x - 900, view_centre_y - 500);
	graphic_stats[1].setPosition(view_centre_x - 900, view_centre_y - 500);
	graphic_stats[2].setPosition(view_centre_x - 900, view_centre_y - 450);
	graphic_stats[3].setPosition(view_centre_x - 900, view_centre_y - 450);
	text[0].setPosition(view_centre_x - 900, view_centre_y - 400);
	text[1].setPosition(view_centre_x - 900, view_centre_y - 350);

	for (auto i: graphic_stats)
		window.draw(i);

	for (auto i : text)
		window.draw(i);
}

Graphical_Character_Stats::~Graphical_Character_Stats()
{
	text.clear();
	graphic_stats.clear();
}
