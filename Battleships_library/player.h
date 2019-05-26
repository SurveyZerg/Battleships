//player.h
#pragma once

#include "map.h"

class Player
{
private:
	Map map;
public:
	void Set_ship(Ship &ship, int Line, int Column, bool vertically = false);
	Ship* Get_ship(int Line, int Column);

	void show_map();
	void show_ships();

    bool checkAroundShip ( int x, int y, int shipSize, bool orientation ) {
	bool checkAround(int x, int y);
	bool checkAvailability(int x, int y);
};
