//player.cpp

#include "player.h"

Ship* Player::Get_ship(int Ox, int Oy)
{
	return map[Ox - 1][Oy - 1];
}

void Player::Set_ship(Ship &ship, int Ox, int Oy)
{
	if (this->Get_ship(Ox, Oy) != 0)
	{
		//std::cout << "It is already busy\n";
	}
	else if (this->Get_ship(Ox, Oy) == 0)
	{
		map[Ox - 1][Oy - 1] = &ship;
	}
}
