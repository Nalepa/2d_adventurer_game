#pragma once
class Improvment_Prices
{
	const unsigned int strength_price, armor_price, health_price, adrenalin_price;
public:
	Improvment_Prices();
	unsigned int get_health_price();
	unsigned int get_adrenalin_price();
	unsigned int get_strenght_price();
	unsigned int get_armor_price();
	~Improvment_Prices();
};

