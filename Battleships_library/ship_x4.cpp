//ship_x4.cpp

#include "ship_x4.h"

Ship_x4::Ship_x4()
{
	Set_amount_of_ships(AMOUNT_OF_X4_SHIPS);
	Set_size_of_ship(4);
}
int Ship_x4::Get_amount_of_ships()
{
	return this->amount_of_ships;
}
void Ship_x4::Set_amount_of_ships(int amount_of_ships)
{
	this->amount_of_ships = amount_of_ships;
}