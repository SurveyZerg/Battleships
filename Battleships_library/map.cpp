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

void Map::Set_ship(Ship &ship, int Line, int Column, bool vertically) /*Нужно, чтобы игрок сначала просто выбирал точку с подсвечивающимся кораблем и была кнопка у него на вертикально
																или горизонтально. Когда он выберет нужное место и нажмет кнопку установить корабль, то считываются настоящее положение
																кнопки вертикально\горизонтально, а также выбранная точка, параметры передаются в этот метод и все готово*/
{
	//Проверка на состыковку кораблей, необходимость под вопросом
	/*
	for (int i = 0;i<3; i++)
	{
		for (int j = 0;j<3; j++)
		{
			if (Ox != 1 || Ox != 8 || Oy != 1 || Oy != 8)
			{
				if (ship_on_map[Ox - 1 - 1 + i][Oy - 1 - 1 + j] != 0)
				{
					std::cout << "ERROR, YOU CANT PLACE YOUR SHIP THERE, BECAUSE ANOTHER SHIP IS VERY CLOSE\n";
				}
			}
		}
	}
	*/
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
