#include "Skeleton.h"





Skeleton::Skeleton(float _x1, float _x2, sf::Vector2f position, sf::Texture* texture) :
	Enemy(100.0f, 200.0f, 100, 1),
	body(shape_size),
	run(0, 0.1f, 0, 12, sf::Vector2f(22, 34)),
	attack(2, 0.15f, 0, 17, sf::Vector2f{ 43, 37 }),
	death(1, 0.15f, 0, 14, sf::Vector2f(32.6, 33))
{
	shape.setPosition(position);
	body.setPosition(position);
	body.setFillColor(sf::Color::Transparent);
	//body.setOutlineThickness(2);
	//body.setOutlineColor(sf::Color::Black);
	x1 = _x1;
	x2 = _x2;
	shape.setTexture(texture);
	movement_speed = 2;
}

void Skeleton::movement(float& delta_time)
{
	if (enemy_stats.get_alive() == true && enemy_stats.get_attack_animation() == false)
	{
		if (shape.getPosition().x <= x1)
		{
			movement_direction = true;
			move(movement_speed, 0);
		}
		else if (shape.getPosition().x + shape.getSize().y >= x2)
		{
			movement_direction = false;
			move(-1 * movement_speed, 0);
		}
		else
		{
			if (movement_direction == true)
			{
				move(movement_speed, 0);
				run.Upload(delta_time, shape, true);
			}

			else
			{
				move(-1 * movement_speed, 0);
				run.Upload(delta_time, shape, false);
			}
		}
	}
}

void Skeleton::collision(Main_Character* character)
{
	if (enemy_stats.get_alive() == true)
	{
		if (character->get_down().getGlobalBounds().intersects(body.getGlobalBounds()) == true)
		{
			if (character->get_movement_direction() == true)
			{
				character->move(-2.2 * character->get_movement_speed(), 0);
			}
			else
			{
				character->move(2.2 * character->get_movement_speed(), 0);
			}

		}
		else if (character->get_right().getGlobalBounds().intersects(body.getGlobalBounds()) == true)
		{
			character->set_position(body.getPosition().x - 142, character->get_shape().getPosition().y);
		}
		else if (character->get_left().getGlobalBounds().intersects(body.getGlobalBounds()) == true)
		{
			character->set_position(body.getPosition().x + body.getSize().x - 60, character->get_shape().getPosition().y);
		}
	}
}

void Skeleton::being_attacked(Main_Character* character)
{
	if (character->get_animation_counter() == 3 && enemy_stats.get_alive() == true && character->get_sword().getGlobalBounds().intersects(body.getGlobalBounds()))
	{
		if(character->get_active_adrenalin() == false) enemy_stats.subtrack_health(character->get_strenght());
		else enemy_stats.subtrack_health(2 * character->get_strenght());

		if (enemy_stats.get_alive() == false)
		{
			character->complete_adrenalin();
			character->add_money(1);
			character->add_key(1);
		}
	}
}

void Skeleton::attacking(Main_Character* character, float& delta_time)
{
	if (character->get_shape().getGlobalBounds().intersects(shape.getGlobalBounds()) == true && enemy_stats.get_alive() == true)
	{
		//rozpoczecie nowej animacji ataku
		if (enemy_stats.get_attack_animation() == false)
		{
			if (movement_direction == true)
			{
				if (shape.getPosition().x >= character->get_shape().getPosition().x) movement_direction = false;
			}
			else
			{
				if (shape.getPosition().x <= character->get_shape().getPosition().x) movement_direction = true;
			}
			enemy_stats.set_attack_animation(true);
			shape.setSize(sf::Vector2f(shape_size.x * 2.2, shape_size.y));
			if (movement_direction == true) shape.move(-10, -10);
			else shape.move(-110, -10);
			delta_time = 0.15f;
		}
		//sprawdzenie czy cios zadal obrazenia
		else if (character->get_left().getGlobalBounds().intersects(shape.getGlobalBounds()) == true && attack.get_animation_counter() == 8
			|| character->get_right().getGlobalBounds().intersects(shape.getGlobalBounds()) == true && attack.get_animation_counter() == 8)
		{
			character->subtract_health(enemy_stats.get_strength());
			character->set_hurt_color();
		}
	}
}

void Skeleton::draw(sf::RenderWindow& window)
{
	window.draw(shape);
	//window.draw(body);
	if(enemy_stats.get_alive() == true) enemy_stats.draw(window, body.getPosition().x, body.getPosition().y);
}

void Skeleton::death_animation(float &delta_time)
{
	if (enemy_stats.get_death_animation() == true)
	{
		enemy_stats.set_attack_animation(false);
		shape.setSize(shape_size);
		shape.setPosition(body.getPosition());
		if (death.single_animation_upload(delta_time, shape, movement_direction) == false)
		{
			enemy_stats.set_death_animation(false);
		}
	}
}

void Skeleton::attack_animation(float& delta_time)
{
	if (enemy_stats.get_attack_animation() == true)
	{
		if (attack.single_animation_upload(delta_time, shape, movement_direction) == false)
		{
			enemy_stats.set_attack_animation(false);
			shape.setSize(shape_size);
			shape.setPosition(body.getPosition());
			delta_time = 0.15f;
		}
	}
}

void Skeleton::move(const float& x, const float& y)
{
	shape.move(x, y);
	body.move(x, y);
}

Skeleton::~Skeleton()
{
}
