#pragma once
#include "Game.h"
#include "Credits_and_Control.h"
#include "Exceptions.h"
#include <vector>
class Menu
{
	sf::RenderWindow window;
	sf::Font font;
	sf::Event event1;
	std::vector<sf::Text>texts;
	std::vector<sf::RectangleShape>buttons;
	std::vector<sf::RectangleShape>::iterator iterator;
	bool iterator_blockade;
	sf::Clock iterator_clock, enter_clock;
	const float iterator_period_time = 0.15f;
	Credits_and_Control credits_and_control;
public:
	Menu();
	void main_menu();
	void iterator_support();
	void enter_support();
	void transform_to_difficulty_menu();
	void transform_to_loading_menu();
	void set_iterator_blockade();
	~Menu();
};