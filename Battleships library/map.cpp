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
