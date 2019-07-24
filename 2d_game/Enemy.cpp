#include "Enemy.h"



Enemy::Enemy(float x_size, float y_size, float max_health, float strength):
	shape_size(x_size, y_size),
	shape(shape_size),
	movement_direction(false),
	enemy_stats(max_health, strength)
{
	//shape.setOutlineThickness(2);
}

void Enemy::set_strength(unsigned int value)
{
	enemy_stats.set_strength(value);
}

void Enemy::set_current_health(unsigned int value)
{
	enemy_stats.set_current_health(value);
}

unsigned int Enemy::get_current_health()
{
	return enemy_stats.get_current_health();
}


Enemy::~Enemy()
{
}
