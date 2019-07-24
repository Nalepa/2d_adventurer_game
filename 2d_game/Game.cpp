#include "Game.h"
#pragma warning( disable : 26495)
Game::Game(int window_size_x, int window_size_y , Difficulty_Level difficulty_level, Game_Mode game_mode):
	window_size{ window_size_x, window_size_y },
	window{ sf::VideoMode{window_size.x, window_size.y, 32 }, "2d adventurer game", sf::Style::Fullscreen },
	//sf::Style::Fullscreen
	view{ sf::FloatRect{0.f, 0.f, static_cast<float>(window_size.x), static_cast<float>(window_size.y) } },
	background{ window_size},
	pause{false},
	display_submenu{false},
	alive{true},
	submenu{character.get_character_stats()},
	game_saving(character.get_main_character(), character.get_character_stats(), environment.get_environment(), "manual_save.txt"),
	automatic_game_saving(character.get_main_character(), character.get_character_stats(), environment.get_environment(), "auto_save.txt")
{
	font.loadFromFile("RevMiniPixel.ttf");
	for(int i = 0; i < 3; i++)
	{
		text.push_back(sf::Text{ "", font, 40 });
		text[i].setFillColor(sf::Color::White);
	}
	text[2].setString("You Died");
	text[2].setFillColor(sf::Color::Red);
	text[2].setCharacterSize(100);

	shape.setFillColor(sf::Color::Black);
	shape.setSize(sf::Vector2f(window_size.x, 100));

	window.setVerticalSyncEnabled(true);
	
		if (game_mode == new_game)
		{
			environment.create_level_1();
			environment.create_level_1_items();
			environment.set_difficulty_level(difficulty_level);
		}
		else if (game_mode == manual_save)
		{
			Game_Loading game_loading{ character.get_main_character(), character.get_character_stats(), environment.get_environment(), "manual_save.txt" };
			game_loading.load_game();
		}
		else
		{
			Game_Loading game_loading{ character.get_main_character(), character.get_character_stats(), environment.get_environment(), "auto_save.txt" };
			game_loading.load_game();
		}
		character.set_required_number_of_keys(environment.get_required_number_of_keys());
}

void Game::play()
{

	while (window.isOpen())
	{
		delta_time_character = character_animation_clock.restart().asSeconds();
		delta_time_items = item_animation_clock.restart().asSeconds();
		delta_time_enemy = enemy_animation_clock.restart().asSeconds();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P && alive == true||
				event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && alive == true)
			{
				set_pause();
				set_display_submenu();
			}
		}
		if (pause == false)
		{
			environment.move_platform();
			character.movement(delta_time_character, jump_clock);
			environment.gravity(&character);
			environment.collision(&character);
			environment.moving_platforms_collision(&character);
			environment.item_collision(&character);
			environment.hurtful_collision(&character, jump_clock, hurt_clock);

			environment.gate_collision(&character);
			environment.enemy_support(&character, delta_time_enemy);

			if (character.get_alive() == false)
			{
				alive = false;
				death_clock.restart();
				set_pause();
			}
			view_support();
		}
			window.clear(sf::Color{ 100, 172, 164, 255 });
			//diagnostic_tools();
			background.draw(window);
			environment.draw(window, delta_time_items);
			character.draw(window, view.getCenter().x, view.getCenter().y);
			death_support();
			if (display_submenu == true)
			{
				submenu.iterator_support();
				submenu_support();
				submenu.statement_support();
				submenu.draw(window, view.getCenter().x, view.getCenter().y);
			}
			if (game_saving.get_statement_displying() == true) game_saving.statement_support(window, view.getCenter().x, view.getCenter().y);
			if (alive == true) automatic_game_saving.auto_save();
			if (automatic_game_saving.get_statement_displying() == true) automatic_game_saving.statement_support(window, view.getCenter().x, view.getCenter().y);
			
			window.display();
	}
}
void Game::view_support()
{
	if (character.get_centre().x < window_size.x / 2 ) view.setCenter(window_size.x / 2, character.get_centre().y);
	else if(character.get_centre().x > 6900) view.setCenter(6900, character.get_centre().y);
	else view.setCenter(character.get_centre());
	window.setView(view);
}
void Game::submenu_support()
{
	choice = submenu.enter_support();

	if(choice == 1)
	{
		//zamkniecie submenu
		set_pause();
		set_display_submenu();
	}
	else if(choice == 2)
	{
		//zapis gry
		game_saving.save();
		set_pause();
		set_display_submenu();
	}
	else if (choice == 3)
	{
		// powrot do menu
		Menu menu{};
		window.close();
		menu.main_menu();
	}
}
void Game::set_pause()
{
	if (pause == true) pause = false;
	else pause = true;
}
void Game::set_display_submenu()
{
	if (display_submenu == true) display_submenu = false;
	else display_submenu = true;

}
void Game::death_support()
{
	if (alive == false)
	{
		if (death_clock.getElapsedTime().asSeconds() <= 5.0f)
		{
			shape.setPosition(view.getCenter().x - 960, view.getCenter().y - 60);
			window.draw(shape);
			text[2].setPosition(view.getCenter().x - 230, view.getCenter().y - 70);
			window.draw(text[2]);
		}
		else
		{
			Menu menu{};
			window.close();
			menu.main_menu();
		}
	}
}
void Game::diagnostic_tools()
{
	mouse_position = sf::Mouse::getPosition();
	text[0].setString(std::to_string(mouse_position.x) + " , " + std::to_string(mouse_position.y));
	text[1].setPosition(character.get_centre());
	text[1].setString(std::to_string(static_cast<int>(character.get_shape().getGlobalBounds().left)) + " , " + std::to_string(static_cast<int>(character.get_shape().getGlobalBounds().top)));
	text[0].setPosition(view.getCenter().x + 500, view.getCenter().y - 500);
	window.draw(text[0]);
	window.draw(text[1]);
}
Game::~Game()
{
	text.clear();
}