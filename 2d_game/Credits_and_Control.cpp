#include "Credits_and_Control.h"
#include "Credits_and_Control.h"



Credits_and_Control::Credits_and_Control(std::string control_file_name, std::string credits_file_name):
	control_file_name(control_file_name),
	credits_file_name(credits_file_name),
	display_credits{false},
	display_control{false}
{
	setSize(sf::Vector2f(1600, 885));
	setFillColor(sf::Color{ 25, 44, 59, 255 });
	setPosition(150, 100);
	setOutlineThickness(5);

	font.loadFromFile("RevMiniPixel.ttf");
	try
	{
		load_control();
		load_credits();
	}
	catch (std::string file_name)
	{
		Exceptions exception;
		exception.txt_file_exception(file_name);
	}
}

void Credits_and_Control::load_control()
{
	file.open(control_file_name);
	if (file.good())
	{
		std::string line;
		while (std::getline(file, line))
			control.emplace_back(sf::Text(line, font, 40));
	}
	else throw control_file_name;
	file.close();

	control[0].setPosition(this->getPosition().x + 700, this->getPosition().y + 50);
	control[0].setCharacterSize(50);

	control[1].setPosition(this->getPosition().x + 350, this->getPosition().y + 200);
	control[2].setPosition(this->getPosition().x + 350, this->getPosition().y + 300);
	control[3].setPosition(this->getPosition().x + 350, this->getPosition().y + 400);
	control[4].setPosition(this->getPosition().x + 350, this->getPosition().y + 500);

	control[5].setPosition(this->getPosition().x + 950, this->getPosition().y + 200);
	control[6].setPosition(this->getPosition().x + 950, this->getPosition().y + 300);
	control[7].setPosition(this->getPosition().x + 950, this->getPosition().y + 400);
	control[8].setPosition(this->getPosition().x + 950, this->getPosition().y + 500);

	control[9].setPosition(this->getPosition().x + 600, this->getPosition().y + 800);
}

void Credits_and_Control::load_credits()
{
	file.open(credits_file_name);
	if (file.good())
	{
		std::string line;
		int i = 0;
		while (std::getline(file, line))
		{
			credits.emplace_back(sf::Text(line, font, 30));
			credits[i].setPosition(this->getPosition().x + 300, this->getPosition().y + i * 50 + 100);
			i++;
		}
	}
	else throw credits_file_name;
	file.close();
	credits[0].setPosition(this->getPosition().x + 700, this->getPosition().y + 50);
	credits[0].setCharacterSize(50);

	credits[12].setPosition(this->getPosition().x + 650, this->getPosition().y + 800);

}

bool Credits_and_Control::get_display_credits()
{
	return display_credits;
}

void Credits_and_Control::set_display_credits(bool value)
{
	display_credits = value;
}

bool Credits_and_Control::get_display_control()
{
	return display_control;
}

void Credits_and_Control::set_display_control(bool value)
{
	display_control = value;
}

void Credits_and_Control::draw(sf::RenderWindow& window)
{
	if (display_control == true || display_credits == true)
	{
		window.draw(*this);
		if (display_control == true)
		{
			for(auto i: control) 
				window.draw(i);
		}
		else
		{
			for (auto i : credits) 
				window.draw(i);
		}
	}
}

Credits_and_Control::~Credits_and_Control()
{
	control.clear();
	credits.clear();
}
