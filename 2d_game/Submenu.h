#pragma once
#include "Character_Stats.h"
#include "Improvment_Prices.h"
#include <memory>

class Submenu : public sf::RectangleShape
{
	sf::Font font;
	std::vector<sf::Text>captions, texts;
	std::vector<sf::RectangleShape>buttons;
	std::vector<sf::RectangleShape>::iterator iterator;
	sf::Clock iterator_clock, enter_clock, statement_clock;
	const float iterator_period_time = 0.15f;
	Character_Stats* character_stats;
	Improvment_Prices improvment_prices;
public:
	Submenu(Character_Stats* character_stats);
	void draw(sf::RenderWindow &window, const float&, const float&);
	void update(const float& view_centre_x, const float& view_centre_y);
	void iterator_support();
	void set_statement(bool state);
	void statement_support();
	int enter_support();
	~Submenu();
};

