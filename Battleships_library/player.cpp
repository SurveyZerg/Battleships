//player.cpp

#include <iostream>
#include "player.h"

void  Player::Set_ship(Ship &ship, int Ox, int Oy, bool vertically)
{
	this->map.Set_ship(ship, Ox, Oy,vertically);
}
Ship* Player::Get_ship(int Ox, int Oy)
{
	return this->map.Get_ship(Ox, Oy);
}

void Player::show_map() //Какое-то смещение всей карты
{
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (this->Get_ship(i + 1, j + 1))
			{
				std::cout << "| ";
			}
			else
			{
				std::cout << "- ";
			}
		}
		std::cout << std::endl;
	}
}

void Player::show_ships()
{
	for (int j = 1; j < 9; j++)
	{
		for (int i = 1; i < 9; i++)
		{
			std::cout << map.Get_ship(j, i) << std::endl;
		}
		std::cout << std::endl;
	}
}