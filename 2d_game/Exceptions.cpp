#include "Exceptions.h"



Exceptions::Exceptions():
	exception_window{ sf::VideoMode{800, 400, 32 }, "Exception" }
{
	font.loadFromFile("RevMiniPixel.ttf");
	text1.setFont(font);
	text1.setPosition(10, 10);
	text2.setFont(font);
	text2.setString("press any button to close");
	text2.setPosition(200, 300);
}

void Exceptions::texture_exception(std::string file_name)
{
	text1.setString("Texture exception: missing '" + file_name + "' file");
	display_exception_window();
}
void Exceptions::txt_file_exception(std::string file_name)
{
	text1.setString("Txt file exception: missing '" + file_name + "' file");
	display_exception_window();
}
void Exceptions::save_file_exception(std::string file_name)
{
	text1.setString("Save file exception: missing '" + file_name + "' file");
	display_exception_window();
}
void Exceptions::font_file_exception(std::string file_name)
{
	text1.setString("Font file exception: missing '" + file_name + "' file");
	display_exception_window();
}
void Exceptions::display_exception_window()
{
	while (exception_window.isOpen())
	{
		while (exception_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) exception_window.close();
			else if (event.type == sf::Event::KeyPressed) exception_window.close();
		}
		exception_window.clear(sf::Color{ 100, 172, 164, 255 });
		exception_window.draw(text1);
		exception_window.draw(text2);
		exception_window.display();
	}
	exit(1);
}
Exceptions::~Exceptions()
{
}
