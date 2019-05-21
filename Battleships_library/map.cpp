//map.cpp

#include "map.h"
#include <iostream>

Map::Map()
{
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			ship_on_map[i][j] = NULL;
		}
	}
}

void Map::Set_ship(Ship &ship, int Ox, int Oy, bool vertically) /*Нужно, чтобы игрок сначала просто выбирал точку с подсвечивающимся кораблем и была кнопка у него на вертикально
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
		int a = 0; //счетчик, чтобы правильно поставить корабль, когда только часть выходит за пределы
		for (int i = 0;i < ship.Get_size_of_ship(); i++)
		{
			if (Ox + i <= LENGTH)
			{
				ship_on_map[Ox - 1 + i][Oy - 1] = &ship;
				a++;
			}
			else if (Ox + i > LENGTH)
			{
				ship_on_map[Ox - 1 - i + a][Oy - 1] = &ship;
			}
		}
	}
	else if (vertically == true)
	{
		int a = 0; //счетчик, чтобы правильно поставить корабль, когда только часть выходит за пределы
		for (int i = 0; i < ship.Get_size_of_ship(); i++)
		{
			if (Oy + i <= HEIGHT)
			{
				ship_on_map[Ox - 1][Oy - 1 + i] = &ship;
				a++;
			}
			else if (Oy + i > HEIGHT)
			{
				ship_on_map[Ox - 1][Oy - 1 - i + a] = &ship;
			}
		}
	}

}
Ship* Map::Get_ship(int Ox, int Oy)
{
	return ship_on_map[Ox - 1][Oy - 1];
}