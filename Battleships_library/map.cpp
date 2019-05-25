//map.cpp

#include "map.h"
#include <iostream>

Map::Map()
{
	ship_on_map.resize(8, std::vector<Ship*>(8));
	for (int Line = 0; Line < HEIGHT; Line++)
	{
		for (int Column = 0; Column < LENGTH; Column++)
		{
			ship_on_map[Line][Column] = NULL;
		}
	}
}

void Map::Set_ship(Ship &ship, int Line, int Column, bool vertically)
{
	//Установка корабля на карту, проверяя границы поля
	if (vertically == false)
	{
		int a = -1; //счетчик, чтобы правильно поставить корабль, когда только часть выходит за пределы
		for (int i = 0;i < ship.Get_size_of_ship(); i++)
		{
			if (Column + i < LENGTH)
			{
				ship_on_map[Line][Column + i] = &ship;
				a++;
			}
			else if (Column + i >= LENGTH)
			{
				ship_on_map[Line][Column - i + a] = &ship;
			}
		}
	}
	else if (vertically == true)
	{
		int a = -1; //счетчик, чтобы правильно поставить корабль, когда только часть выходит за пределы
		for (int i = 0; i < ship.Get_size_of_ship(); i++)
		{
			if (Line + i < HEIGHT)
			{
				ship_on_map[Line + i][Column] = &ship;
				a++;
			}
			else if (Line + i >= HEIGHT)
			{
				ship_on_map[Line - i + a][Column] = &ship;
			}
		}
	}
}
Ship* Map::Get_ship(int Line, int Column)
{
	return ship_on_map[Line][Column];
}
