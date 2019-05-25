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

void Map::Set_ship(Ship &ship, int Line, int Column, bool vertically) /*�����, ����� ����� ������� ������ ������� ����� � ���������������� �������� � ���� ������ � ���� �� �����������
																��� �������������. ����� �� ������� ������ ����� � ������ ������ ���������� �������, �� ����������� ��������� ���������
																������ �����������\�������������, � ����� ��������� �����, ��������� ���������� � ���� ����� � ��� ������*/
{
	//�������� �� ���������� ��������, ������������� ��� ��������
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
	//��������� ������� �� �����, �������� ������� ����
	if (vertically == false)
	{
		int a = -1; //�������, ����� ��������� ��������� �������, ����� ������ ����� ������� �� �������
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
		int a = -1; //�������, ����� ��������� ��������� �������, ����� ������ ����� ������� �� �������
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