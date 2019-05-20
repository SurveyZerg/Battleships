//player.cpp

#include "player.h"

void  Player::Set_ship(Ship &ship, int Ox, int Oy, bool vertically)
{
	map.Set_ship(ship, Ox, Oy,vertically);
}
Ship* Player::Get_ship(int Ox, int Oy)
{
	return map.Get_ship(Ox, Oy);
}

