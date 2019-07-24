#include "Submenu.h"



Submenu::Submenu(Character_Stats* character_stats):
	character_stats(character_stats)
{
	setSize(sf::Vector2f(1600, 885));
	setFillColor(sf::Color{ 25, 44, 59, 255 });
	setPosition(50, 50);
	setOutlineThickness(5);

	for (int i = 0; i < 3; i++)
	{
		buttons.emplace_back(sf::RectangleShape{ sf::Vector2f{ 300, 100 } });
		buttons[i].setFillColor(sf::Color::Transparent);
		buttons[i].setOutlineThickness(2);
	}
	for (int i = 3; i < 7; i++)
	{
		buttons.emplace_back(sf::RectangleShape{ sf::Vector2f{ 100, 100 } });
		buttons[i].setFillColor(sf::Color::Transparent);
		buttons[i].setOutlineThickness(2);
	}


	font.loadFromFile("RevMiniPixel.ttf");

	for (int i = 0; i < 7; i++)
	{
		captions.emplace_back(sf::Text{ "", font, 40 });
		captions[i].setFillColor(sf::Color::White);
	}
	captions[0].setString("Resume game");
	captions[1].setString("Save game");
	captions[2].setString("Back to menu");
	captions[3].setString(" + ");
	captions[3].setCharacterSize(90);
	captions[4].setString(" + ");
	captions[4].setCharacterSize(90);
	captions[5].setString(" + ");
	captions[5].setCharacterSize(90);
	captions[6].setString(" + ");
	captions[6].setCharacterSize(90);

	for (int i = 0; i < 12; i++)
	{
		texts.emplace_back(sf::Text{ "", font, 40 });
		texts[i].setFillColor(sf::Color::White);
	}

	texts[0].setString("Statistics & Equipment");

	iterator = buttons.begin();
	iterator->setFillColor(sf::Color::Black);
	iterator_clock.restart();
	enter_clock.restart();
	statement_clock.restart();
}

void Submenu::draw(sf::RenderWindow& window, const float& view_centre_x, const float& view_centre_y)
{
	update(view_centre_x, view_centre_y);
	window.draw(*this);
	for (auto& i : buttons)
		window.draw(i);
	
	for (auto& i : captions)
		window.draw(i);
	
	for (auto& i : texts)
		window.draw(i);
	
}

void Submenu::update(const float& view_centre_x, const float& view_centre_y)
{
	setPosition(view_centre_x - 800, view_centre_y - 430);

	buttons[0].setPosition(this->getPosition().x + 50, this->getPosition().y + 75);
	buttons[1].setPosition(this->getPosition().x + 50, this->getPosition().y + 225);
	buttons[2].setPosition(this->getPosition().x + 50, this->getPosition().y + 375);

	buttons[3].setPosition(this->getPosition().x + 920, this->getPosition().y + 75);
	buttons[4].setPosition(this->getPosition().x + 920, this->getPosition().y + 225);
	buttons[5].setPosition(this->getPosition().x + 920, this->getPosition().y + 375);
	buttons[6].setPosition(this->getPosition().x + 920, this->getPosition().y + 525);

	captions[0].setPosition(buttons[0].getPosition().x + 20, buttons[0].getPosition().y + 20);
	captions[1].setPosition(buttons[1].getPosition().x + 45, buttons[1].getPosition().y + 20);
	captions[2].setPosition(buttons[2].getPosition().x + 20, buttons[2].getPosition().y + 20);

	captions[3].setPosition(buttons[3].getPosition().x + 10, buttons[3].getPosition().y - 10);
	captions[4].setPosition(buttons[4].getPosition().x + 10, buttons[4].getPosition().y - 10);
	captions[5].setPosition(buttons[5].getPosition().x + 10, buttons[5].getPosition().y - 10);
	captions[6].setPosition(buttons[6].getPosition().x + 10, buttons[6].getPosition().y - 10);

	texts[0].setPosition(this->getPosition().x + 100, this->getPosition().y );

	texts[1].setPosition(this->getPosition().x + 500, this->getPosition().y + 100);
	texts[1].setString("Health: " + std::to_string(character_stats->get_current_health()) + " / " + std::to_string(character_stats->get_max_health()));

	texts[2].setPosition(this->getPosition().x + 500, this->getPosition().y + 250);
	texts[2].setString("Adrenalin: " + std::to_string(character_stats->get_current_adrenalin()) + " / " + std::to_string(character_stats->get_max_adrenalin()));

	texts[3].setPosition(this->getPosition().x + 500, this->getPosition().y + 400);
	texts[3].setString("Strength: " + std::to_string(character_stats->get_strenght()));

	texts[4].setPosition(this->getPosition().x + 500, this->getPosition().y + 550);
	texts[4].setString("Armor: " + std::to_string(character_stats->get_armor()));

	texts[5].setPosition(this->getPosition().x + 500, this->getPosition().y + 700);
	texts[5].setString("Coins: " + std::to_string(character_stats->get_money()));

	texts[6].setPosition(this->getPosition().x + 500, this->getPosition().y + 800);
	texts[6].setString("Keys: " + std::to_string(character_stats->get_keys())+ " / " + std::to_string(character_stats->get_required_number_of_keys()));


	texts[7].setPosition(this->getPosition().x + 1100, this->getPosition().y + 100);
	texts[7].setString("10 points for " + std::to_string(improvment_prices.get_health_price()) + " coin");

	texts[8].setPosition(this->getPosition().x + 1100, this->getPosition().y + 250);
	texts[8].setString("10 points for " + std::to_string(improvment_prices.get_adrenalin_price()) + " coin");

	texts[9].setPosition(this->getPosition().x + 1100, this->getPosition().y + 400);
	texts[9].setString("1 point for " + std::to_string(improvment_prices.get_strenght_price()) + " coins");

	texts[10].setPosition(this->getPosition().x + 1100, this->getPosition().y + 550);
	texts[10].setString("1 point for " + std::to_string(improvment_prices.get_armor_price()) + " coin");

	texts[11].setPosition(this->getPosition().x + 1100, this->getPosition().y + 700);
}

void Submenu::iterator_support()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (iterator_clock.getElapsedTime().asSeconds() > 0.15f)
		{
			if (iterator != buttons.begin())
			{
				iterator->setFillColor(sf::Color::Transparent);
				--iterator;
				iterator->setFillColor(sf::Color::Black);
				iterator_clock.restart();
			}
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (iterator_clock.getElapsedTime().asSeconds() > iterator_period_time)
		{
			if (iterator != --buttons.end())
			{
				iterator->setFillColor(sf::Color::Transparent);
				++iterator;
				iterator->setFillColor(sf::Color::Black);
				iterator_clock.restart();
			}
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (iterator_clock.getElapsedTime().asSeconds() > iterator_period_time)
		{
			if (iterator  == buttons.begin() || iterator == buttons.begin() + 1 || iterator == buttons.begin() + 2)
			{
				iterator->setFillColor(sf::Color::Transparent);
				iterator += 3;
				iterator->setFillColor(sf::Color::Black);
				iterator_clock.restart();
			}
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (iterator_clock.getElapsedTime().asSeconds() > iterator_period_time)
		{
			if (iterator == buttons.begin() + 3 || iterator == buttons.begin() + 4 || iterator == buttons.begin() + 5)
			{
				iterator->setFillColor(sf::Color::Transparent);
				iterator -= 3;
				iterator->setFillColor(sf::Color::Black);
				iterator_clock.restart();
			}
		}
	}
}

void Submenu::set_statement(bool state)
{
	if (state == true)
	{
		texts[11].setString("Improved succesfully");
		statement_clock.restart();
	}
	else
	{
		texts[11].setString("Not enaught coins");
		statement_clock.restart();
	}
}

void Submenu::statement_support()
{
	if (statement_clock.getElapsedTime().asSeconds() <= 2.0f) texts[11].setFillColor(sf::Color::White);
	else texts[11].setFillColor(sf::Color::Transparent);
}

int Submenu::enter_support()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && enter_clock.getElapsedTime().asSeconds() > 0.15f)
	{
		enter_clock.restart();
		if (iterator == buttons.begin()) return 1;
		else if (iterator == buttons.begin() + 1) return 2;
		else if (iterator == buttons.begin() + 2) return 3;
		else if (iterator == buttons.begin() + 3)
		{
			set_statement(character_stats->improve_health(improvment_prices.get_health_price()));
			return 0;
		}
		else if (iterator == buttons.begin() + 4)
		{
			set_statement(character_stats->improve_adrenalin(improvment_prices.get_adrenalin_price()));
			return 0;
		}
		else if (iterator == buttons.begin() + 5)
		{
			set_statement(character_stats->improve_strength(improvment_prices.get_strenght_price()));
			return 0;
		}
		else if (iterator == buttons.begin() + 6)
		{
			set_statement(character_stats->improve_armor(improvment_prices.get_armor_price()));
			return 0;
		}
		else return 0;
	}
	return 0;
}

Submenu::~Submenu()
{
	texts.clear();
	buttons.clear();
}
