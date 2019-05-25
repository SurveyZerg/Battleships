//player.h
#pragma once

#include "map.h"

class Player //Опасно, скорее всего неправильно
{
private:
	Map map;
public:
	void Set_ship(Ship &ship, int Line, int Column, bool vertically = false);
	Ship* Get_ship(int Line, int Column);

	void show_map();
	void show_ships();
};