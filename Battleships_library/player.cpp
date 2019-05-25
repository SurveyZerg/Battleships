//player.cpp

#include <iostream>
#include "player.h"

void  Player::Set_ship(Ship &ship, int Line, int Column, bool vertically)
{
	this->map.Set_ship(ship, Line, Column, vertically);
}
Ship* Player::Get_ship(int Line, int Column)
{
	return this->map.Get_ship(Line, Column);
}

//ниже точно все работает правильно

void Player::show_map() //Какое-то смещение всей карты
{
	for (int Line = 0; Line < HEIGHT; Line++)
	{
		for (int Column = 0; Column < LENGTH; Column++)
		{
			if (map.ship_on_map[Line][Column])
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
	for (int Line = 0; Line < HEIGHT; Line++)
	{
		for (int Column = 0; Column < LENGTH; Column++)
		{
			std::cout << map.ship_on_map[Line][Column];
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}