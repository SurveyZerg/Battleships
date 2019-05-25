//map.h
#pragma once

#include "ship_x1.h"
#include "ship_x2.h"
#include "ship_x3.h"
#include "ship_x4.h"

#include <vector>

#define LENGTH 8
#define HEIGHT 8

class Map
{
private:

protected:

public:
	Map();

	std::vector <std::vector <Ship*>> ship_on_map; // 8 ïî îñè x è 8 ïî îñè y

	void Set_ship(Ship &ship, int Line, int Column,bool vertically = false);

	Ship* Get_ship(int Line, int Column);
	
	bool checkAround ( int x, int y );
 	bool checkAvailability( int x, int y );
};
