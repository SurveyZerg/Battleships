//player.h
#pragma once

#include "map.h"

class Player //������, ������ ����� �����������
{
private:

public:
	void Set_ship(Ship &ship, int Ox, int Oy, bool vertically = false);
	Ship* Get_ship(int Ox, int Oy);
};