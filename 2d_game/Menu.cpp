#include "Menu.h"
#pragma warning( disable : 26495)
Menu::Menu(): window{ sf::VideoMode{ 1920, 1080, 32 }, "2d adventurer game", sf::Style::Fullscreen},
iterator_blockade{false},
credits_and_control("control.txt", "credits.txt")
{
	for (int i = 0; i < 5; i++)
	{
		buttons.emplace_back(sf::RectangleShape{ sf::Vector2f{ 400, 100 } });
		buttons[i].setFillColor(sf::Color::Transparent);
		buttons[i].setOutlineThickness(2);
	}

	buttons[0].setPosition(750, 150);
	buttons[1].setPosition(750, 300);
	buttons[2].setPosition(750, 450);
	buttons[3].setPosition(750, 600);
	buttons[4].setPosition(750, 750);

	try
	{
		if (!font.loadFromFile("RevMiniPixel.ttf"))
		{
			std::string exception = "RevMiniPixel.ttf";
			throw exception;
		}
	}
	catch (std::string file_name)
	{
		Exceptions exception;
		exception.font_file_exception(file_name);
	}

	for (int i = 0; i < 7; i++)
	{
		texts.emplace_back(sf::Text{ "", font, 50 });
		texts[i].setFillColor(sf::Color::White);
	}
	window.setVerticalSyncEnabled(true);

	texts[0].setString("2d adventurer game");
	texts[0].setPosition(800, 0);
	texts[0].setCharacterSize(30);

	texts[1].setString("Menu");
	texts[1].setPosition(50, 25);

	texts[2].setString("New Game");
	texts[2].setPosition(buttons[0].getPosition().x + 80, buttons[0].getPosition().y + 20);

	texts[3].setString("Load Game");
	texts[3].setPosition(buttons[1].getPosition().x + 70, buttons[1].getPosition().y + 20);

	texts[4].setString("Control");
	texts[4].setPosition(buttons[2].getPosition().x + 110, buttons[2].getPosition().y + 20);

	texts[5].setString("Credits");
	texts[5].setPosition(buttons[3].getPosition().x + 100, buttons[3].getPosition().y + 20);

	texts[6].setString("End");
	texts[6].setPosition(buttons[4].getPosition().x + 150, buttons[4].getPosition().y + 20);

	iterator = buttons.begin();
	iterator->setFillColor(sf::Color::Black);
	iterator_clock.restart();
	enter_clock.restart();

}
void Menu::main_menu()
{
	while (window.isOpen())
	{
		while (window.pollEvent(event1))
			if (event1.type == sf::Event::Closed) window.close();
		
		window.clear(sf::Color{ 100, 172, 164, 255 });
		iterator_support();
		enter_support();
		for (auto &i : buttons) 
			window.draw(i);
		for (auto &i : texts) 
			window.draw(i);
		credits_and_control.draw(window);
		window.display();
	}
}
void Menu::iterator_support()
{
	if (iterator_blockade == false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (iterator_clock.getElapsedTime().asSeconds() > iterator_period_time)
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
	}
}

void Menu::enter_support()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && enter_clock.getElapsedTime().asSeconds() > iterator_period_time)
	{
		enter_clock.restart();
		if (buttons.size() == 5)
		{
			if (iterator == buttons.begin())
			{
				// new game
				transform_to_difficulty_menu();
			}
			else if (iterator == buttons.begin() + 1)
			{
				// load game
				transform_to_loading_menu();
			}
			else if (iterator == buttons.begin() + 2)
			{
				//control
				set_iterator_blockade();
				if (credits_and_control.get_display_control() == false) credits_and_control.set_display_control(true);
				else credits_and_control.set_display_control(false);

			}
			else if (iterator == buttons.begin() + 3)
			{
				//credits
				set_iterator_blockade();
				if(credits_and_control.get_display_credits() == false) credits_and_control.set_display_credits(true);
				else credits_and_control.set_display_credits(false);
			}
			else if (iterator == buttons.end() - 1)
			{
				//end
				window.close();
			}
		}
		else if (buttons.size() == 2)
		{
			if (iterator == buttons.begin())
			{
				// odczyt z manualnego zapisu
				Game game{ 1920, 1080, easy, manual_save };
				window.close();
				game.play();
			}
			else if (iterator == buttons.begin() + 1)
			{
				// odczyt z auto zapisu
				Game game{ 1920, 1080, easy, auto_save };
				window.close();
				game.play();
			}

		}
		else if (buttons.size() == 3)
		{
			if (iterator == buttons.begin())
			{
				// easy
				Game game{1920, 1080, easy, new_game};
				window.close();
				game.play();
			}
			else if (iterator == buttons.begin() + 1)
			{
				//medium
				Game game{ 1920, 1080, normal, new_game };
				window.close();
				game.play();

			}
			else if (iterator == buttons.end() - 1)
			{
				//hard
				Game game{ 1920, 1080, hard, new_game };
				window.close();
				game.play();
			}
		}
	}
}
void Menu::transform_to_difficulty_menu()
{
	texts.erase(texts.end() - 3, texts.end());
	buttons.erase(buttons.end() - 2, buttons.end());

	buttons[0].setPosition(750, 200);
	buttons[1].setPosition(750, 350);
	buttons[2].setPosition(750, 500);

	texts[0].setString("Select a difficulty level");
	texts[0].setPosition(650, 75);
	texts[0].setCharacterSize(50);

	texts[1].setString("Easy");
	texts[1].setPosition(buttons[0].getPosition().x + 130, buttons[0].getPosition().y + 20);

	texts[2].setString("Normal");
	texts[2].setPosition(buttons[1].getPosition().x + 100, buttons[1].getPosition().y + 20);

	texts[3].setString("Hard");
	texts[3].setPosition(buttons[2].getPosition().x + 130, buttons[2].getPosition().y + 20);

}
void Menu::transform_to_loading_menu()
{
	texts.erase(texts.end() - 4, texts.end());
	buttons.erase(buttons.end() - 3, buttons.end());

	buttons[0].setPosition(750, 300);
	buttons[1].setPosition(750, 450);

	texts[0].setString("Select the loading source");
	texts[0].setPosition(650, 75);
	texts[0].setCharacterSize(50);

	texts[1].setString("Manual Save");
	texts[1].setPosition(buttons[0].getPosition().x + 50, buttons[0].getPosition().y + 20);

	texts[2].setString("Auto Save");
	texts[2].setPosition(buttons[1].getPosition().x + 80, buttons[1].getPosition().y + 20);

	iterator->setFillColor(sf::Color::Transparent);
	--iterator;
	iterator->setFillColor(sf::Color::Black);
	iterator_clock.restart();

}
void Menu::set_iterator_blockade()
{
	if (iterator_blockade == true) iterator_blockade = false;
	else iterator_blockade = true;
}
Menu::~Menu()
{
	texts.clear();
	buttons.clear();
}