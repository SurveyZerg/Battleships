//ship_x3.cpp

#include "ship_x3.h"

Ship_x3::Ship_x3()
{
	Set_amount_of_ships(AMOUNT_OF_X3_SHIPS);
	Set_size_of_ship(3);
}
int Ship_x3::Get_amount_of_ships()
{
	return this->amount_of_ships;
}
void Ship_x3::Set_amount_of_ships(int amount_of_ships)
{
	this->amount_of_ships = amount_of_ships;
}