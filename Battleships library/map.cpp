//map.cpp

#include "map.h"

Map::Map()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < height; j++)
		{
			map[i][j] = 0;
		}
	}
}

bool checkAround ( int x, int y ) {
	bool thereIsShip;
	for (int i=-1 ; i<2; ++i )
		thereIsShip += checkAvailability( x+i, y-1 );
	for (int i=-1 ; i<2; ++i )
		thereIsShip += checkAvailability( x+i, y+1 );
	thereIsShip += checkAvailability( x+1, y );
	thereIsShip += checkAvailability( x-1, y );
	return thereIsShip;
   }
  
bool checkAvailability( int x, int y ) {
	if (x<0 || x>7 || y<0 || y>7). // we cannot check there
		return 0;
	if (map[x][y] == 0)
		return 0;  // means this is free of ships
	else
		return 1;
}
