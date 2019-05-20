//player.cpp

#include "player.h"

void  Player::Set_ship(Ship &ship, int Ox, int Oy, bool vertically)
{
	this->map.Set_ship(ship, Ox, Oy,vertically);
}
Ship* Player::Get_ship(int Ox, int Oy)
{
	return this->map.Get_ship(Ox, Oy);
}

