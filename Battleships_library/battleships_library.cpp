//battleships_library.cpp

#include "battleships_library.h"

Player A;
Player B;
std::vector <Ship_x1> ships_x1;
std::vector <Ship_x2> ships_x2;
std::vector <Ship_x3> ships_x3;
std::vector <Ship_x4> ships_x4;

Game::Game()
{
	ships_x1.resize(AMOUNT_OF_X1_SHIPS);
	ships_x2.resize(AMOUNT_OF_X2_SHIPS);
	ships_x3.resize(AMOUNT_OF_X3_SHIPS);
	ships_x4.resize(AMOUNT_OF_X4_SHIPS);
}

bool Game::checkWin()
{
	int winA = 1;
	int winB = 1;
	for (int Line = 0; Line < HEIGHT; Line++)
	{
		for (int Column = 0; Column < LENGTH; Column++)
		{
			if (A.Get_ship(Line, Column))
			{
				winB = 0;
			}
		}
	}
	for (int Line = 0; Line < HEIGHT; Line++)
	{
		for (int Column = 0; Column < LENGTH; Column++)
		{
			if (B.Get_ship(Line, Column))
			{
				winA = 0;
			}
		}
	}
	if (winA == 1 || winB == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}