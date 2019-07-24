#include "Animation.h"

Animation::Animation(int row, float change_time, unsigned int begin_number, unsigned int end_number, sf::Vector2f simple_image_size) : 
current_image(begin_number, row), simple_image_size{ simple_image_size },
change_time(change_time), totaltime(0.0f), 
rect(begin_number * simple_image_size.x, row * simple_image_size.y, simple_image_size.x, simple_image_size.y),
end_number(end_number), begin_number(begin_number),
animation_counter(0)
{}
void Animation::Upload(float &delta_time, sf::RectangleShape &shape, bool right)
{
	totaltime += delta_time;
	if (totaltime >= change_time)
	{
		totaltime -= change_time;
		
		if (current_image.x >= end_number) current_image.x = begin_number;
		else current_image.x++;
		
			if (right)
			{
				rect.left = current_image.x * simple_image_size.x;
				rect.width = abs(rect.width);
			}
			else
			{
				rect.left = (current_image.x + 1) * simple_image_size.x;
				rect.width = -abs(rect.width);
			}
	
		shape.setTextureRect(rect);
	}
}

bool Animation::single_animation_upload(float& delta_time, sf::RectangleShape& shape, bool right)
{
	totaltime += delta_time;
	if (totaltime >= change_time)
	{
		totaltime -= change_time;

		if (current_image.x >= end_number)
		{
			current_image.x = begin_number;
			animation_counter = 0;
			return false;
		}
		else current_image.x++;

		if (right)
		{
			rect.left = current_image.x * simple_image_size.x;
			rect.width = abs(rect.width);
		}
		else
		{
			rect.left = (current_image.x + 1) * simple_image_size.x;
			rect.width = -abs(rect.width);
		}
		++animation_counter;
		shape.setTextureRect(rect);
	}
	return true;
}

void Animation::single_animtion_restart()
{
	current_image.x = begin_number;
	animation_counter = 0;
}

unsigned int Animation::get_animation_counter()
{
	return animation_counter;
}

Animation::~Animation()
{
}
