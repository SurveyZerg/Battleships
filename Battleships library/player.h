//player.h
#pragma once

#include "map.h"

class Player : public Map //Опасно, скорее всего неправильно
{
private:
	
public:
	Ship* Get_ship(int Ox, int Oy);

	void Set_ship(Ship &ship, int Ox, int Oy);
};