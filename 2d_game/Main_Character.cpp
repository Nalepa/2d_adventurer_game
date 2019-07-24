#include "Main_Character.h"



Main_Character::Main_Character() :
	shape_size(200.0f, 200.0f),
	shape{ shape_size },
	down{ sf::Vector2f(58, 2) },
	top{ sf::Vector2f(60, 2) },
	right{ sf::Vector2f(2, 150) },
	left{ sf::Vector2f(2, 150) },
	sword{ sf::Vector2f(2, 50) },

	// nr animacji, czas odswiezania, nr pierwszego rysunku, nr ostatniego rysunku
	run{ 1, 0.1f, 1, 6, sf::Vector2f{ 50, 37 } },
	stoppage{ 0, 0.15f, 0, 3 , sf::Vector2f{ 50, 37 } },
	jump{ 2, 0.4f, 0, 1, sf::Vector2f{ 50, 37 } },
	crouch{ 0, 0.15f, 4, 6, sf::Vector2f{ 50, 37 } },
	attack{ 6, 0.10f, 0, 6, sf::Vector2f{ 50, 37 } }, 

	rect{ 0, 0, 50, 43 },
	movement_direction{ true },
	is_jumping{ false }, is_gravity{ true },
	on_the_ground{ false }, on_the_trampoline{false},
	left_hurt{false}, right_hurt{false},
	is_attacking{false},
	movement_speed{ 5 },
	moving_in_x_speed{ 2 },
	active_adrenalin{false}
{
	jump_speed = max_jump_speed = -20;
	try 
	{
		if (!texture.loadFromFile("adventurer.png"))
		{
			std::string exception = "adventurer.png";
			throw exception;
		}
	}
	catch (std::string file_name)
	{
		Exceptions exception;
		exception.texture_exception(file_name);
	}
	shape.setTexture(&texture);
	shape.setTextureRect(rect);
	//shape.setOutlineThickness(1); 

	//set_position(4900, 2000);
	set_position(100, 500);
	//set_position(5700, 700);

	down.setFillColor(sf::Color::Blue);
	top.setFillColor(sf::Color::Red);
	left.setFillColor(sf::Color::Yellow);
	right.setFillColor(sf::Color::Green);
	sword.setFillColor(sf::Color::Black);

}
void Main_Character::movement(float &delta_time, sf::Clock &jump_clock)
{
	// do obslugi skoku
		if (is_jumping == true)
		{
			if (jump_clock.getElapsedTime().asSeconds() <= 0.5)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					move(1, jump_speed);
					jump.Upload(delta_time, shape, true);
					jump_speed += 1;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					move(-1, jump_speed);
					jump.Upload(delta_time, shape, false);
					jump_speed += 1;
				}
				else
				{
					move(0, jump_speed);
					if(movement_direction == true) jump.Upload(delta_time, shape, true);
					else jump.Upload(delta_time, shape, false);
					jump_speed += 1;
				}
			}
			else
			{
				is_jumping = false;
				is_gravity = true;
				jump_speed = max_jump_speed;
				shape.setFillColor(sf::Color::White);
			}
		}
		// do obslugi ataku
		if (is_attacking == true)
		{
			if (movement_direction == true)
			{
				if (attack.single_animation_upload(delta_time, shape, true) == false)
				{
					is_attacking = false;
				}
			}
			else
			{
				if (attack.single_animation_upload(delta_time, shape, false) == false)
				{
					is_attacking = false;
				}
			}
		}
	//do obslugi adrenaliny
		if (active_adrenalin == true)
		{
			if (adrenalin_clock.getElapsedTime().asSeconds() <= 5.0f)
			{
				shape.setFillColor(sf::Color::Blue);
			}
			else
			{
				active_adrenalin = false;
				shape.setFillColor(sf::Color::White);
			}
		}
	//do obslugi kolorowania postaci podczas ranienia (rany powodowane przez kolce prawe, lewe i gorne w klasie environment)
		if (hurt == true)
		{
			if (hurt_clock.getElapsedTime().asSeconds() <= 0.3f)
			{
				shape.setFillColor(sf::Color::Red);
			}
			else
			{
				shape.setFillColor(sf::Color::White);
				hurt = false;
			}
		}
	// do obslugi klawiatury
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && on_the_ground == true ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && on_the_ground == true)
		{
				movement_direction = true;
				is_jumping = true;
				is_gravity = false;
				on_the_ground = false;
				jump_clock.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && on_the_ground == true ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && on_the_ground == true)
		{
				movement_direction = false;
				is_jumping = true;
				is_gravity = false;
				on_the_ground = false;
				jump_clock.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (is_attacking == true)
			{
				attack.single_animtion_restart();
				is_attacking = false;
			}
			if (is_jumping == true)
			{
				move(2 * movement_speed, 0);
				jump.Upload(delta_time, shape, true);
			}
			else
			{
				move(movement_speed, 0);
				run.Upload(delta_time, shape, true);
			}
			movement_direction = true;

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (is_attacking == true)
			{
				attack.single_animtion_restart();
				is_attacking = false;
			}
			if (is_jumping == true)
			{
				move(-2 * movement_speed, 0);
				jump.Upload(delta_time, shape, false);
			}
			else
			{
				move(-1 * movement_speed, 0);
				run.Upload(delta_time, shape, false);
			}
			movement_direction = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && on_the_ground == true && on_the_trampoline == true ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::W) && on_the_ground == true && on_the_trampoline == true)
		{
			is_jumping = true;
			is_gravity = false;
			on_the_ground = false;
			on_the_trampoline = false;
			jump_speed = 3.5 * max_jump_speed;
			jump_clock.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && on_the_ground == true ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::W) && on_the_ground == true)
		{
				is_jumping = true;
				is_gravity = false;
				on_the_ground = false;
				jump_clock.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		{
			if (is_jumping == false && is_attacking == false)
			{
				is_attacking = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (movement_direction == true) crouch.Upload(delta_time, shape, true);
			else crouch.Upload(delta_time, shape, false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && active_adrenalin == false)
		{
				if (character_stats.use_adrenalin() == true)
				{
					active_adrenalin = true;
					adrenalin_clock.restart();
				}
		}
		else
		{
			if (is_jumping == false && is_attacking == false)
			{
				if (movement_direction == true) stoppage.Upload(delta_time, shape, true);
				else stoppage.Upload(delta_time, shape, false);
			}
		}
}
void Main_Character::draw(sf::RenderWindow &window, const float &view_centre_x, const float &view_centre_y)
{
	window.draw(shape);
	/*
	window.draw(down);
	window.draw(top);
	window.draw(right);
	window.draw(left);
	window.draw(sword);
	*/
	character_stats.draw(window, view_centre_x, view_centre_y);
}
void Main_Character::move(const float &x, const float &y)
{
	shape.move(x, y);
	down.move(x, y);
	top.move(x, y);
	right.move(x, y);
	left.move(x, y);
	if (movement_direction == true) sword.setPosition(shape.getPosition().x + 190, shape.getPosition().y + 70);
	else sword.setPosition(shape.getPosition().x + 10, shape.getPosition().y + 70);
}
void Main_Character::set_position(const float& x, const float& y)
{
	shape.setPosition(sf::Vector2f{ x,y });
	down.setPosition(x + 72, y + 200);
	top.setPosition(x + 72, y + 30);
	right.setPosition(x + 140, y + 40);
	left.setPosition(x + 60, y + 40);
	if (movement_direction == true) sword.setPosition(x + 190, y + 70);
	else sword.setPosition(x + 10, y + 70);
}
void Main_Character::add_money(int value)
{
	character_stats.add_money(value);
}
void Main_Character::add_health(int value)
{
	character_stats.add_health(value);
}
void Main_Character::add_adrenalin(int value)
{
	character_stats.add_adrenalin(value);
}
void Main_Character::add_key(int value)
{
	character_stats.add_key(value);
}
unsigned int Main_Character::get_keys()
{
	return character_stats.get_keys();
}
void Main_Character::subtract_health(int value)
{
	character_stats.subtract_health(value);
}
sf::RectangleShape & Main_Character::get_shape()
{
	return shape;
}
sf::RectangleShape & Main_Character::get_right()
{
	return right;
}
sf::RectangleShape & Main_Character::get_left()
{
	return left;
}
sf::RectangleShape& Main_Character::get_sword()
{
	return sword;
}
sf::RectangleShape & Main_Character::get_top()
{
	return top;
}
sf::RectangleShape & Main_Character::get_down()
{
	return down;
}
bool Main_Character::get_on_the_ground()
{
	return on_the_ground;
}
void Main_Character::set_on_the_ground(bool value)
{
	on_the_ground = value;
}
bool Main_Character::get_on_the_trampoline()
{
	return on_the_trampoline;
}
void Main_Character::set_on_the_trampoline(bool state)
{
	on_the_trampoline = state;
}
bool Main_Character::get_is_jumping()
{
	return is_jumping;
}
void Main_Character::set_is_jumping(bool state)
{
	is_jumping = state;
}
bool Main_Character::get_is_gravity()
{
	return is_gravity;
}
void Main_Character::set_is_gravity(bool state)
{
	is_gravity = state;
}
float Main_Character::get_movement_speed()
{
	return movement_speed;
}
void Main_Character::set_initial_jump_speed()
{
	jump_speed = max_jump_speed;
}
float Main_Character::get_moving_in_x_speed()
{
	return moving_in_x_speed;
}
bool Main_Character::get_left_hurt()
{
	return left_hurt;
}
void Main_Character::set_left_hurt(bool state)
{
	left_hurt = state;
}
bool Main_Character::get_right_hurt()
{
	return right_hurt;
}
void Main_Character::set_right_hurt(bool state)
{
	right_hurt = state;
}
void Main_Character::delete_keys()
{
	character_stats.delete_keys();
}
sf::Vector2f Main_Character::get_centre()
{
	return sf::Vector2f{ shape.getGlobalBounds().left + shape_size.x / 2, shape.getGlobalBounds().top - 100};
}
bool Main_Character::get_alive()
{
	return character_stats.get_alive();
}
bool Main_Character::get_movement_direction()
{
	return movement_direction;
}
Character_Stats* Main_Character::get_character_stats()
{
	return character_stats.get_character_stats();
}
unsigned int Main_Character::get_animation_counter()
{
	return attack.get_animation_counter();
}
unsigned int Main_Character::get_strenght()
{
	return character_stats.get_strenght();
}
bool Main_Character::get_active_adrenalin()
{
	return active_adrenalin;
}
void Main_Character::set_hurt_color()
{
	hurt = true;
	hurt_clock.restart();
}
void Main_Character::complete_adrenalin()
{
	character_stats.complete_adrenalin();
}
Main_Character* Main_Character::get_main_character()
{
	return this;
}
void Main_Character::set_movement_direction(bool value)
{
	movement_direction = value;
}
void Main_Character::set_required_number_of_keys(unsigned int value)
{
	character_stats.set_required_number_of_keys(value);
}
Main_Character::~Main_Character()
{
}
