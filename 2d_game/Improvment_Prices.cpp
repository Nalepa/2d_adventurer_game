#include "Improvment_Prices.h"



Improvment_Prices::Improvment_Prices():
	health_price{ 1 },
	adrenalin_price{ 1 },
	strength_price{ 2 },
	armor_price{ 1 }
{
}

unsigned int Improvment_Prices::get_health_price()
{
	return health_price;
}

unsigned int Improvment_Prices::get_adrenalin_price()
{
	return adrenalin_price;
}

unsigned int Improvment_Prices::get_strenght_price()
{
	return strength_price;
}

unsigned int Improvment_Prices::get_armor_price()
{
	return armor_price;
}


Improvment_Prices::~Improvment_Prices()
{
}
