//ship_x2.cpp

#include "ship_x2.h"

Ship_x2::Ship_x2()
{
	Set_amount_of_ships(AMOUNT_OF_X2_SHIPS);
	Set_size_of_ship(2);
}
int Ship_x2::Get_amount_of_ships()
{
	return this->amount_of_ships;
}
void Ship_x2::Set_amount_of_ships(int amount_of_ships)
{
	this->amount_of_ships = amount_of_ships;
}