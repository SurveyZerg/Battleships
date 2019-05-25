//map.h
#pragma once

#include "ship_x1.h"
#include "ship_x2.h"
#include "ship_x3.h"
#include "ship_x4.h"

#define length 8
#define height 8

class Map
{
private:

protected:
public:
	Map();

	Ship* map[length - 1][height - 1]; // 8 ďî îńč x č 8 ďî îńč y
	
	bool checkAround ( int x, int y );
 	bool checkAvailability( int x, int y );
};
