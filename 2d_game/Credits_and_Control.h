#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <fstream>
#include <vector>
#include "Exceptions.h"
class Credits_and_Control : public sf::RectangleShape
{
	std::vector<sf::Text> credits, control;
	bool display_credits, display_control;
	sf::Font font;
	std::ifstream file;
	std::string control_file_name, credits_file_name;
	
public:
	Credits_and_Control(std::string control_file_name, std::string credits_file_name);
	void load_control();
	void load_credits();
	bool get_display_credits();
	void set_display_credits(bool value);
	bool get_display_control();
	void set_display_control(bool value);
	void draw(sf::RenderWindow& window);
	~Credits_and_Control();
};

