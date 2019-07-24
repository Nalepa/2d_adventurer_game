#include "Environment.h"


Environment::Environment()
{
	try
	{
		load_textures();
	}
	catch (std::string file_name)
	{
		
		Exceptions exception;
		exception.texture_exception(file_name);
	}
}
void Environment::load_textures()
{
	//texture1 jungle
	textures.emplace_back(sf::Texture{});
	if (!textures[0].loadFromFile("jungle2.png"))
	{
		std::string exception = "jungle2.png";
		throw exception;
	}
	//texture 2 ziemia
	textures.emplace_back(sf::Texture{});
	if (!textures[1].loadFromFile("single.png"))
	{
		std::string exception = "single.png";
		throw exception;
	}
	textures[1].setRepeated(true);
	//texture 3 kwadrat
	textures.emplace_back(sf::Texture{});
	if (!textures[2].loadFromFile("square.png"))
	{
		std::string exception = "square.png";
		throw exception;
	}
	//coins
	textures.emplace_back(sf::Texture{});
	if (!textures[3].loadFromFile("coins.png"))
	{
		std::string exception = "coins.png";
		throw exception;
	}
	//heart
	textures.emplace_back(sf::Texture{});
	if (!textures[4].loadFromFile("heart.png"))
	{
		std::string exception = "heart.png";
		throw exception;
	}
	//spikes
	textures.emplace_back(sf::Texture{});
	if (!textures[5].loadFromFile("spikes.png"))
	{
		std::string exception = "spikes.png";
		throw exception;
	}
	textures[5].setRepeated(true);
	//stones
	textures.emplace_back(sf::Texture{});
	if (!textures[6].loadFromFile("stones.png"))
	{
		std::string exception = "stones.png";
		throw exception;
	}
	textures[6].setRepeated(true);
	//key
	textures.emplace_back(sf::Texture{});
	if (!textures[7].loadFromFile("key.png"))
	{
		std::string exception = "key.png";
		throw exception;
	}
	//gate
	textures.emplace_back(sf::Texture{});
	if (!textures[8].loadFromFile("gate.png"))
	{
		std::string exception = "gate.png";
		throw exception;
	}
	//skeleton
	textures.emplace_back(sf::Texture{});
	if (!textures[9].loadFromFile("skeleton.png"))
	{
		std::string exception = "skeleton.png";
		throw exception;
	}
}
void Environment::create_level_1()
{
	delete_enviroment();
	level_number = 1;
	required_number_of_keys = 3;

	// size, position, rect, texture
	collison_objects.emplace_front(Object{ sf::Vector2f{ 50, 1000 }, sf::Vector2f{ -50, 0 }, sf::IntRect{ 0, 0, 200, 40 }, &textures[1] }); // granica1
	float size_x = 1000, size_y;
	collison_objects.emplace_front(Object{ sf::Vector2f{ size_x, 200 }, sf::Vector2f{ 0, 900 }, sf::IntRect{ 0, 0, rect_ground(size_x), 40 }, &textures[1] }); // ziemia1
	
	collison_objects.emplace_front(Object{ sf::Vector2f{ 400, 400 }, sf::Vector2f{ 1000, 720 }, sf::IntRect{ 77, 13, 80, 88 }, &textures[2] }); // kwadrat1
	size_x = 1500;
	collison_objects.emplace_front(Object{ sf::Vector2f{ size_x, 200 }, sf::Vector2f{ 1400, 900 }, sf::IntRect{ 0, 0, rect_ground(size_x), 40 }, &textures[1] }); // ziemia2
	collison_objects.emplace_front(Object{ sf::Vector2f{ 600, 100 }, sf::Vector2f{ 1550, 550 }, sf::IntRect{ 0, 192, 160, 32 }, &textures[0] }); // platforma1
	collison_objects.emplace_front(Object{ sf::Vector2f{ 250, 100 }, sf::Vector2f{ 1050, 400 }, sf::IntRect{ 0, 192, 60, 32 }, &textures[0] }); // platforma2
	collison_objects.emplace_front(Object{ sf::Vector2f{ 250, 100 }, sf::Vector2f{ 600, 225 }, sf::IntRect{ 0, 192, 60, 32 }, &textures[0] }); // platforma3
	collison_objects.emplace_front(Object{ sf::Vector2f{ 250, 100 }, sf::Vector2f{ 1150, 70 }, sf::IntRect{ 0, 192, 60, 32 }, &textures[0] }); // platforma4

	moving_platforms.emplace_front(Moving_Object{ sf::Vector2f{ 300, 100 }, sf::Vector2f{ 3000, 900 }, sf::IntRect{ 0, 192, 60, 32 }, &textures[0], true, false, 2900, 4000, 0, 0 }); //poruszajaca sie platforma1

	decorative_objects.emplace_front(Object{ sf::Vector2f{ 2900, 700 }, sf::Vector2f{ 0, 1100 } });

	size_x = 205;
	spikes.emplace_front(Object{ sf::Vector2f{ size_x, 100 }, sf::Vector2f{ 2300, 810 }, sf::IntRect{ 0, 0, rect_spikes(size_x), 165 }, &textures[5] }); // kolce 1
	spikes.emplace_front(Object{ sf::Vector2f{ size_x, 100 }, sf::Vector2f{ 1730, 456 }, sf::IntRect{ 0, 0, rect_spikes(size_x), 165 }, &textures[5] }); // kolce 2
	size_x = 1300;
	spikes.emplace_front(Object{ sf::Vector2f{ size_x, 100 }, sf::Vector2f{ 2900, 1400 }, sf::IntRect{ 0, 0, rect_spikes(size_x), 165 }, &textures[5] });
	size_x = 488;
	spikes.emplace_front(Object{ sf::Vector2f{ size_x, 100 }, sf::Vector2f{ 3000, 1000 }, sf::IntRect{ 0, 0, rect_spikes(size_x), 165 }, &textures[5] });// kolce dolina1
	spikes.begin()->rotate(90);
	spikes.emplace_front(Object{ sf::Vector2f{ size_x, 100 }, sf::Vector2f{ 4100, 1500 }, sf::IntRect{ 0, 0, rect_spikes(size_x), 165 }, &textures[5] });// kolce dolina1
	spikes.begin()->rotate(270);

	size_x = 700;
	collison_objects.emplace_front(Object{ sf::Vector2f{ size_x, 200 }, sf::Vector2f{ 4200, 900 }, sf::IntRect{ 0, 0, rect_ground(size_x), 40 }, &textures[1] }); // ziemia3

	decorative_objects.emplace_front(Object{ sf::Vector2f{ 1500, 300 }, sf::Vector2f{ 2900, 1500 } });

	collison_objects.emplace_front(Object{ sf::Vector2f{ 700, 1000 }, sf::Vector2f{ 4200, 1100 } }); // tunel 1
	collison_objects.emplace_front(Object{ sf::Vector2f{ 1000, 1300 }, sf::Vector2f{ 5200, 1100 } }); // tunel 2

	size_x = 4200;
	size_y = 300;
	collison_objects.emplace_front(Object{ sf::Vector2f{ size_x, size_y }, sf::Vector2f{ 2200, 2400 }, sf::IntRect{ 0, 0, rect_stones(size_x), rect_stones(size_y) }, &textures[6] }); // kamienie 1
	size_x = 620;
	spikes.emplace_front(Object{ sf::Vector2f{ size_x, 100 }, sf::Vector2f{ 4850, 2200 }, sf::IntRect{ 0, 0, rect_spikes(size_x), 165 }, &textures[5] }); // kolce podziemne 1
	spikes.begin()->rotate(180);

	size_x = 205;
	spikes.emplace_front(Object{ sf::Vector2f{ size_x, 100 }, sf::Vector2f{ 3850, 2300 }, sf::IntRect{ 0, 0, rect_spikes(size_x), 165 }, &textures[5] }); // kolce podziemne 2

	collison_objects.emplace_front(Object{ sf::Vector2f{ 1000, 700 }, sf::Vector2f{ 2200, 1800 } });// tunel 3


	size_x = 800;
	collison_objects.emplace_front(Object{ sf::Vector2f{ size_x, 200 }, sf::Vector2f{ 5200, 900 }, sf::IntRect{ 0, 0, rect_ground(size_x), 40 }, &textures[1] }); // ziemia 4
	collison_objects.emplace_front(Object{ sf::Vector2f{ 400, 400 }, sf::Vector2f{ 6000, 720 }, sf::IntRect{ 77, 13, 80, 88 }, &textures[2] }); // kwadrat2
	collison_objects.emplace_front(Object{ sf::Vector2f{ 250, 100 }, sf::Vector2f{ 5500, 550 }, sf::IntRect{ 0, 192, 60, 32 }, &textures[0] }); // platforma5
	collison_objects.emplace_front(Object{ sf::Vector2f{ 250, 100 }, sf::Vector2f{ 6000, 400 }, sf::IntRect{ 0, 192, 60, 32 }, &textures[0] }); // platforma6
	collison_objects.emplace_front(Object{ sf::Vector2f{ 250, 100 }, sf::Vector2f{ 5500, 220 }, sf::IntRect{ 0, 192, 60, 32 }, &textures[0] }); // platforma7

	moving_platforms.emplace_front(Moving_Object{ sf::Vector2f{ 300, 100 }, sf::Vector2f{ 5000, 0 }, sf::IntRect{ 0, 192, 60, 32 }, &textures[0], false, true, 0, 0, -500, 350 }); //poruszajaca sie platforma2
	collison_objects.emplace_front(Object{ sf::Vector2f{ 250, 100 }, sf::Vector2f{ 5500, -500 }, sf::IntRect{ 0, 192, 60, 32 }, &textures[0] }); // platforma8

	size_x = 1500;
	collison_objects.emplace_front(Object{ sf::Vector2f{ size_x, 200 }, sf::Vector2f{ 6400, 900 }, sf::IntRect{ 0, 0, rect_ground(size_x), 40 }, &textures[1] }); // ziemia 5
	decorative_objects.emplace_front(Object{ sf::Vector2f{ 1800, 700 }, sf::Vector2f{ 6200, 1100 } });

	collison_objects.emplace_front(Object{ sf::Vector2f{ 50, 1000 }, sf::Vector2f{ 7860, 0 }, sf::IntRect{ 0, 0, 200, 40 }, &textures[1] }); // granica2

	collison_objects.emplace_front(Object{ sf::Vector2f{ 200, 50 }, sf::Vector2f{ 4985, 2350 } }); // wyrzutnia 1
	collison_objects.begin()->setFillColor(sf::Color::Red);

	gate = std::make_unique<Gate>(required_number_of_keys, sf::Vector2f{ 7350, 575 }, &textures[8]);
	enemy = std::make_unique<Skeleton>(6500, 7900, sf::Vector2f{ 7150, 710 }, &textures[9]);
	
}
void Environment::create_level_1_items()
{
	
	items.emplace_back(Item{ coin, sf::Vector2f{ 695, 140 }, &textures[3] });
	items.emplace_back(Item{ coin, sf::Vector2f{ 400, 400 }, &textures[3] });
	items.emplace_back(Item{ coin, sf::Vector2f{ 2000, 400 }, &textures[3] });
	items.emplace_back(Item{ heart, sf::Vector2f{ 1240, -20 }, &textures[4] });

	items.emplace_back(Item{ coin, sf::Vector2f{ 3950, 2200 }, &textures[3] }); // itemy pod ziemia
	items.emplace_back(Item{ heart, sf::Vector2f{ 3600, 2300 }, &textures[4] });
	items.emplace_back(Item{ key, sf::Vector2f{ 3250, 2300 }, &textures[7] });

	items.emplace_back(Item{ key, sf::Vector2f{ 5550, -600 }, &textures[7] });
	
}
void Environment::create_level_2()
{
	delete_enviroment();
	level_number = 2;
	required_number_of_keys = 2;
							// size, position, rect, texture
	collison_objects.emplace_front(Object{ sf::Vector2f{ 50, 2000 }, sf::Vector2f{ -50, 0 }, sf::IntRect{ 0, 0, 200, 40 }, &textures[1] }); // granica1
	float size_x = 1000, size_y;
	collison_objects.emplace_front(Object{ sf::Vector2f{ size_x, 200 }, sf::Vector2f{ 0, 900 }, sf::IntRect{ 0, 0, rect_ground(size_x), 40 }, &textures[1] }); // ziemia1

	gate = std::make_unique<Gate>(required_number_of_keys, sf::Vector2f{ 7350, 575 }, &textures[8]);
	enemy = std::make_unique<Skeleton>(6500, 7900, sf::Vector2f{ 7150, 710 }, &textures[9]);
	
}
void Environment::delete_enviroment()
{
	collison_objects.clear();
	moving_platforms.clear();
	spikes.clear();
	decorative_objects.clear();
	items.clear();
	gate.reset();
	enemy.reset();
}
 inline int Environment::rect_ground(float ground_length)
{
	 return static_cast<int>(0.2 * ground_length);
}

 inline int Environment::rect_spikes(float spikes_length)
 {
	 return static_cast<int>(1.6 * spikes_length);
 }

 inline int Environment::rect_stones(float stones_size)
 {
	 return static_cast<int>(1.6 * stones_size);
 }

void Environment::draw(sf::RenderWindow &window, float &delta_time)
{
	for (auto &i : spikes)
		window.draw(i);
	
	if (gate)
	{
		gate->draw(window);
		if (gate->get_during_the_opening() == true)
		{
			if (gate->update_single_animation(delta_time) == false)
			{
				gate->set_during_the_opening(false);
				gate->set_is_open(true);
			}
		}
	}
	if(enemy) enemy->draw(window);

	for (auto &i : collison_objects)
		window.draw(i);
	
	for (auto &i : moving_platforms)
		window.draw(i);

	for (auto &i : decorative_objects)
		window.draw(i);
	
	for (auto &i : items)
	{
		if (i.get_type() == coin) i.Update(delta_time);
		window.draw(i);
	}
}
void Environment::move_platform()
{
	for (auto &i: moving_platforms)
		i.move_platform();
}
void Environment::collision(Main_Character *character)
{
	float movement_speed = character->get_movement_speed();
	for (auto &i: collison_objects)
	{
		if (character->get_right().getGlobalBounds().intersects(i.getGlobalBounds()) == true && character->get_left().getGlobalBounds().intersects(i.getGlobalBounds()) == true && character->get_down().getGlobalBounds().intersects(i.getGlobalBounds()) == true)
			character->move(0, -1 * movement_speed);
		if (character->get_top().getGlobalBounds().intersects(i.getGlobalBounds()) == true)
		{
			character->set_is_jumping(false);
			character->set_is_gravity(true);
			character->set_initial_jump_speed();
		}
		if (character->get_right().getGlobalBounds().intersects(i.getGlobalBounds()) == true)
		{
			if (character->get_is_jumping() == true) character->move(-2.2 * movement_speed, 0);
			else character->move(-1 * movement_speed, 0);

		}
		if (character->get_left().getGlobalBounds().intersects(i.getGlobalBounds()) == true)
		{
			if (character->get_is_jumping() == true) character->move(2.2 * movement_speed, 0);
			else character->move(movement_speed, 0);
		}
	}
}
void Environment::item_collision(Main_Character *character)
{
	for (auto iterator = items.begin(); iterator != items.end(); iterator++)
	{
		if (character->get_right().getGlobalBounds().intersects(iterator->getGlobalBounds()) == true || character->get_left().getGlobalBounds().intersects(iterator->getGlobalBounds()) == true || character->get_down().getGlobalBounds().intersects(iterator->getGlobalBounds()) == true || character->get_top().getGlobalBounds().intersects(iterator->getGlobalBounds()) == true)
		{
			if (iterator->get_type() == coin) character->add_money(iterator->get_value());
			else if (iterator->get_type() == heart) character->add_health(iterator->get_value());
			else if (iterator->get_type() == key) character->add_key(iterator->get_value());
			iterator = items.erase(iterator);
			if (iterator == items.end()) return;
		}
	}
}
void Environment::moving_platforms_collision(Main_Character *character)
{
	float movement_speed = character->get_movement_speed();
	for (auto &i: moving_platforms)
	{
		if (character->get_right().getGlobalBounds().intersects(i.getGlobalBounds()) == true && character->get_left().getGlobalBounds().intersects(i.getGlobalBounds()) == true && character->get_down().getGlobalBounds().intersects(i.getGlobalBounds()) == true)
		{
			character->move(0, -2 * movement_speed);
		}
		if (character->get_top().getGlobalBounds().intersects(i.getGlobalBounds()) == true)
		{
			character->set_is_jumping(false);
			character->set_is_gravity(true);
			character->set_initial_jump_speed();
		}
		if (character->get_right().getGlobalBounds().intersects(i.getGlobalBounds()) == true)
		{
			if (i.get_direction_x() == false)
			{
				if (character->get_is_jumping() == true) character->move(-4 * movement_speed, 0);
				else character->move(-1 * movement_speed, 0);
			}
			else
			{
				if (character->get_is_jumping() == true) character->move(-2.2 * movement_speed, 0);
				else character->move(-1 * movement_speed, 0);
			}
		}
		if (character->get_left().getGlobalBounds().intersects(i.getGlobalBounds()) == true)
		{
			if (i.get_direction_x() == true)
			{
				if (character->get_is_jumping() == true) character->move(4 * movement_speed, 0);
				else character->move(movement_speed, 0);
			}
			else
			{
				if (character->get_is_jumping() == true) character->move(2.2 * movement_speed, 0);
				else character->move(movement_speed, 0);
			}
		}
	}
}
void Environment::gate_collision(Main_Character* character)
{
	
	if (gate)
	{
			if (character->get_right().getGlobalBounds().intersects(gate->getGlobalBounds()) == true
				|| character->get_left().getGlobalBounds().intersects(gate->getGlobalBounds()) == true
				|| character->get_down().getGlobalBounds().intersects(gate->getGlobalBounds()) == true
				|| character->get_top().getGlobalBounds().intersects(gate->getGlobalBounds()) == true)
			{
				if (gate->get_is_open() == false && character->get_keys() == gate->get_required_number_of_keys() && sf::Keyboard::isKeyPressed(sf::Keyboard::E))
				{
					gate->set_during_the_opening(true);
					character->delete_keys();
				}
				else if (gate->get_is_open() == true && sf::Keyboard::isKeyPressed(sf::Keyboard::E))
				{
					character->set_position( 100, 500 );
					create_level_2();
				}
			}
	}
	
}
void Environment::gravity(Main_Character *character)
{
	if (character->get_is_gravity() == true)
	{
		float movement_speed = character->get_movement_speed();
		// grawitacja z poruszajacymi sie platformami
		for (auto &i: moving_platforms)
		{
			if (character->get_down().getGlobalBounds().intersects(i.getGlobalBounds()) == true)
			{
				character->set_on_the_ground(true);
				if (i.get_is_moving_in_x() == true)
				{
					if (i.get_direction_x() == true) character->move(movement_speed, 0);
					else character->move(-1 * movement_speed, 0);
				}
				if (i.get_is_moving_in_y() == true)
				{
					if (i.get_direction_y() == true) character->move(0, movement_speed);
					else character->move(0, -1 * movement_speed);
				}

				// dodaje przemieszczenie aby postac nie stala w miejscu podczas ruchu w przeciwnym kierunku do kierunku platformy
				if (i.get_direction_x() == false && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					if (character->get_is_jumping() == true) character->move(2 * movement_speed, 0);
					else character->move(movement_speed, 0);
				}
				else if (i.get_direction_x() == true && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					if (character->get_is_jumping() == true) character->move(-2 * movement_speed, 0);
					else character->move(-1 * movement_speed, 0);
				}
				return;
			}
		}
		// grawitacja z trampolina
		if (collison_objects.begin() != collison_objects.end())
		{
			if (character->get_down().getGlobalBounds().intersects(collison_objects.begin()->getGlobalBounds()) == true)
			{
				if (character->get_on_the_ground() == false)
				{
					character->set_on_the_ground(true);
					character->set_on_the_trampoline(true);
					character->get_shape().setFillColor(sf::Color::White);
				}
				return;
			}
		}
		
		// grawitacja z zwyklymi obiektami
		for (auto iterator = collison_objects.begin()++; iterator != collison_objects.end(); iterator++)
		{ 
			if (character->get_down().getGlobalBounds().intersects(iterator->getGlobalBounds()) == true)
			{
				if (character->get_on_the_ground() == false)
				{
					character->set_on_the_ground(true);
					character->set_on_the_trampoline(false);
				}
				return;
			}
		}
		character->move(0, 2 * movement_speed);
		character->set_on_the_ground(false);
	}
}
void Environment::enemy_support(Main_Character* character, float& delta_time)
{
	if (enemy)
	{
		enemy->collision(character);
		enemy->being_attacked(character);
		enemy->death_animation(delta_time);
		enemy->attacking(character, delta_time);
		enemy->attack_animation(delta_time);
		enemy->attacking(character, delta_time);
		enemy->movement(delta_time);
	}
}
unsigned int Environment::get_required_number_of_keys()
{
	return required_number_of_keys;
}
void Environment::set_difficulty_level(int value)
{
	difficulty_level = static_cast<Difficulty_Level>(value);
	set_difficulty_values();
}
Difficulty_Level Environment::get_difficulty_level()
{
	return difficulty_level;
}
void Environment::set_difficulty_values()
{
	if (difficulty_level == easy)
	{
		spikes_hurt = 5;
		enemy->set_strength(1);
	}
	else if (difficulty_level == normal)
	{
		spikes_hurt = 20;
		enemy->set_strength(2);
	}
	else
	{
		spikes_hurt = 90;
		enemy->set_strength(4);
	}
}
Environment* Environment::get_environment()
{
	return this;
}
int Environment::get_level_number()
{
	return level_number;
}
void Environment::set_level_number(int value)
{
	level_number = value;
}
std::list<Item>& Environment::get_items()
{
	return items;
}
unsigned int Environment::get_enemy_current_health()
{
	return enemy->get_current_health();
}
void Environment::set_enemy_current_health(unsigned int value)
{
	enemy->set_current_health(value);
}
void Environment::add_item(const float& x, const float& y, Item_type item_type)
{
	if (item_type == coin) items.emplace_back(Item(coin, sf::Vector2f{ x, y }, &textures[3]));
	else if (item_type == heart) items.emplace_back(Item(heart, sf::Vector2f{ x, y }, &textures[4]));
	else if (item_type == key) items.emplace_back(Item(key, sf::Vector2f{ x, y }, &textures[7]));
}
void Environment::set_gate_during_the_opening(bool value)
{
	gate->set_during_the_opening(value);
}
bool Environment::get_gate_is_open()
{
	return gate->get_is_open();
}
void  Environment::hurtful_collision(Main_Character *character, sf::Clock &jump_clock, sf::Clock &hurt_clock)
{
	float moving_in_x_speed = character->get_moving_in_x_speed();
	for (auto iterator = spikes.begin(); iterator != spikes.end(); iterator++)
	{
		// obsluga starych kolizji (down obslugiwane przez movement() w klasie main_character)
		if (character->get_right_hurt() == true)
		{
			if (hurt_clock.getElapsedTime().asSeconds() <= 0.1)
			{
				character->move(moving_in_x_speed, 0);
			}
			else
			{
				character->set_right_hurt(false);
				character->get_shape().setFillColor(sf::Color::White);
			}
		}
		if (character->get_left_hurt() == true)
		{
			if (hurt_clock.getElapsedTime().asSeconds() <= 0.1)
			{
				character->move(-1 * moving_in_x_speed, 0);
			}
			else
			{
				character->set_left_hurt(false);
				character->get_shape().setFillColor(sf::Color::White);
			}
		}

		// nowe kolizje
		if (character->get_down().getGlobalBounds().intersects(iterator->getGlobalBounds()) == true)
		{
			character->set_is_jumping(true);
			character->set_is_gravity(false);
			character->set_on_the_ground(false);
			jump_clock.restart();
			character->get_shape().setFillColor(sf::Color::Red);
			character->subtract_health(spikes_hurt);
		}
		if (character->get_top().getGlobalBounds().intersects(iterator->getGlobalBounds()) == true)
		{
			character->set_is_jumping(false);
			character->set_is_gravity(true);
			character->set_initial_jump_speed();
			character->get_shape().setFillColor(sf::Color::Red);
			character->subtract_health(spikes_hurt);
			character->set_hurt_color();
		}
		if (character->get_right().getGlobalBounds().intersects(iterator->getGlobalBounds()) == true)
		{
			character->set_left_hurt(true);
			hurt_clock.restart();
			character->get_shape().setFillColor(sf::Color::Red);
			character->subtract_health(spikes_hurt);

		}
		if (character->get_left().getGlobalBounds().intersects(iterator->getGlobalBounds()) == true)
		{
			character->set_right_hurt(true);
			hurt_clock.restart();
			character->get_shape().setFillColor(sf::Color::Red);
			character->subtract_health(spikes_hurt);
		}
	}

}
Environment::~Environment()
{
	collison_objects.clear();
	moving_platforms.clear();
	spikes.clear();
	decorative_objects.clear();
	items.clear();
	textures.clear();
}
