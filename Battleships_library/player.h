//player.h
#pragma once

#include "map.h"

class Player
{
private:
	Map map;

	void destroyShip(Player* enemy, int Line, int Column);
public:
	void Set_ship(Ship &ship, int Line, int Column, bool vertically = false);
	Ship* Get_ship(int Line, int Column);

	void show_map();
	void show_ships();

	bool checkAround(int x, int y);
	bool checkAvailability(int x, int y);

	bool shoot(Player* enemy, int Line, int Column);
};