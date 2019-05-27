//main.cpp

#include "battleships_library.h"
#include <iostream>

int main()
{
	Game battleships;

	A.Set_ship(ships_x1[0], 0, 0);
	A.Set_ship(ships_x1[1], 3, 7);
	A.Set_ship(ships_x1[2], 5, 3);

	B.Set_ship(ships_x1[0], 4, 4);
	B.Set_ship(ships_x1[1], 1, 3);
	B.Set_ship(ships_x1[2], 2, 7);

	int potentiometrLine = 1;
	int potentiometrColumn = 1;
	int button = 0;
	bool shoot_finished = false;
	while (battleships.checkWin())
	{
		if (shoot_finished == false)
		{
			std::cout << "Your turn, player #1" << std::endl;
			A.show_map();
			std::cout << "Line " << std::endl;
			std::cin >> potentiometrLine;
			std::cout << "Column " << std::endl;
			std::cin >> potentiometrColumn;
			std::cout << "Ready? " << std::endl;
			std::cin >> button;
			if (button == 1)
			{
				if (A.shoot(&B, potentiometrLine - 1, potentiometrColumn - 1))
				{
					std::cout << "NICE SHOOT" << std::endl;
					shoot_finished = false;
				}
				else
				{
					std::cout << "HA-HA MISS" << std::endl;
					shoot_finished = true;
				}
			}
		}
		if (shoot_finished == true)
		{
			std::cout << "Your turn, player #2" << std::endl;
			B.show_map();
			std::cout << "Line " << std::endl;
			std::cin >> potentiometrLine;
			std::cout << "Column " << std::endl;
			std::cin >> potentiometrColumn;
			std::cout << "Ready? " << std::endl;
			std::cin >> button;
			if (button == 1)
			{
				if (B.shoot(&A, potentiometrLine - 1, potentiometrColumn - 1))
				{
					std::cout << "NICE SHOOT" << std::endl;
					shoot_finished = true;
				}
				else
				{
					std::cout << "HA-HA MISS" << std::endl;
					shoot_finished = false;
				}
			}
		}
	}
	/*
	//Основной цикл игры
	int potentiometrLine = 1;
	int potentiometrColumn = 1;
	int button = 0;
	bool shoot_finished = false;
	while (battleships.checkWin())
	{
		if (shoot_finished == false)
		{
			if (button == 1)
			{
				if (A.shoot(&B, potentiometrLine - 1, potentiometrColumn - 1))
				{
					//Думаю, что здесь везде нужны временные паузы, чтобы и кнопка успела отжаться хотя бы
					//попадание
					shoot_finished = false;
				}
				else
				{
					//промах
					shoot_finished = true;
				}
			}
		}
		if (shoot_finished == true)
		{
			if (button == 1)
			{
				if (B.shoot(&A, potentiometrLine - 1, potentiometrColumn - 1))
				{
					//Думаю, что здесь везде нужны временные паузы, чтобы и кнопка успела отжаться хотя бы
					//попадание
					shoot_finished = true;
				}
				else
				{
					//промах
					shoot_finished = false;
				}
			}
		}
	}
	*/
	
	system("pause");
	return 0;
}