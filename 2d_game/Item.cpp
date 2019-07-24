#include "Item.h"
#pragma warning( disable : 26495)

Item::Item(Item_type type, const sf::Vector2f &position, sf::Texture *texture) :
	type{ type },
	Object{ sf::Vector2f{ 70, 70 }, position, sf::IntRect{0, 0, 16, 16}, texture },
	animation{ 6, 0.15f, 0, 4, sf::Vector2f{16, 16} }
{
	if (type == coin) value = 1;
	else if (type == heart) value = 30;
	else if (type == key)
	{
		setSize(sf::Vector2f(130, 50));
		rect.width = 236;
		rect.height = 106;
		setTextureRect(rect);
		value = 1;
	}
	//setOutlineThickness(1);
}

Item_type Item::get_type()
{
	return type;
}

int Item::get_value()
{
	return value;
}

void Item::Update(float &delta_time)
{
	animation.Upload(delta_time, *this, true);
}


Item::~Item()
{
}
