#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class Exceptions
{
	sf::Text text1, text2;
	sf::Font font;
	sf::RenderWindow exception_window;
	sf::Event event;
public:
	Exceptions();
	void texture_exception(std::string file_name);
	void txt_file_exception(std::string file_name);
	void save_file_exception(std::string file_name);
	void font_file_exception(std::string file_name);
	void display_exception_window();
	~Exceptions();
};

