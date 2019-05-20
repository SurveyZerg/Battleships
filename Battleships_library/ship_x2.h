//ship_x2.h
#pragma once

#include "ship.h"

class Ship_x2 : public Ship
{
private:
public:
	Ship_x2();
	int Get_amount_of_ships() override;
	void Set_amount_of_ships(int amount_of_ships) override;
};