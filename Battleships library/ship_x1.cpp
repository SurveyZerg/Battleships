//ship_x1.cpp

#include "ship_x1.h"

Ship_x1::Ship_x1()
{
	Set_amount_of_ships(3);
	Set_size_of_ship(1);
}
int Ship_x1::Get_amount_of_ships()
{
	return this->amount_of_ships;
}
void Ship_x1::Set_amount_of_ships(int amount_of_ships)
{
	this->amount_of_ships = amount_of_ships;
}