#pragma once
#include "Main_Character.h"
#include "Environment.h"
#include "Animation.h"
#include "Background.h"
#include "Submenu.h"
#include "Menu.h"
#include "Automatic_Game_Saving.h"
#include "Game_Loading.h"
enum Game_Mode{new_game, manual_save, auto_save};
class Game
{
	sf::Vector2u window_size;
	sf::RenderWindow window;
	sf::Event event;
	sf::Font font;
	Environment environment;
	std::vector <sf::Text> text;
	sf::RectangleShape shape;
	sf::Vector2i mouse_position;
	sf::View view;
	Main_Character character;
	Background background;
	bool pause, display_submenu, alive;
	Submenu submenu;
	sf::Clock character_animation_clock, item_animation_clock, enemy_animation_clock;
	sf::Clock death_clock, jump_clock, hurt_clock;
	float delta_time_character, delta_time_items, delta_time_enemy;
	Game_Saving game_saving;
	Automatic_Game_Saving automatic_game_saving;
	int choice;
public:
	Game(int window_size_x, int window_size_y, Difficulty_Level difficulty_level, Game_Mode game_mode );
	void play();
	void diagnostic_tools();
	void view_support();
	void submenu_support();
	void set_pause();
	void set_display_submenu();
	void death_support();
	~Game();
};
	
		
