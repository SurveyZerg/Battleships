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

void Player::show_map() 
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

bool Player::checkAround(int x, int y) {
	bool thereIsShip = 0;
	for (int i = -1; i < 2; ++i)
		thereIsShip += checkAvailability(x + i, y - 1);
	for (int i = -1; i < 2; ++i)
		thereIsShip += checkAvailability(x + i, y + 1);
	thereIsShip += checkAvailability(x + 1, y);
	thereIsShip += checkAvailability(x - 1, y);
	return thereIsShip;
}

bool Player::checkAvailability(int x, int y) {
	if (x < 0 || x>7 || y < 0 || y>7) // we cannot check there
		return 0;
	if (this->Get_ship(x,y) == 0)
		return 0;  // means this is free of ships
	else
		return 1;
}

void Player::destroyShip(Player* enemy, int Line, int Column)
{
	enemy->map.ship_on_map[Line][Column] = NULL;
}

bool Player::shoot(Player* enemy, int Line, int Column)
{
	if (enemy->Get_ship(Line, Column))
	{
		this->destroyShip(enemy, Line, Column);
		return true;
	}
	else
	{
		return false;
	}
}