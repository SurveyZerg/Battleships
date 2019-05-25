//ship_x1.h
#pragma once

#include "ship.h"

class Ship_x1 : public Ship
{
private:
public:
	Ship_x1();
	int Get_amount_of_ships() override;
	void Set_amount_of_ships(int amount_of_ships) override;
};