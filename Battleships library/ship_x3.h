//ship_x3.h
#pragma once

#include "ship.h"

class Ship_x3 : public Ship
{
private:
	std::vector <Ship_x3> ships_x3;
public:
	Ship_x3();
	int Get_amount_of_ships() override;
	void Set_amount_of_ships(int amount_of_ships) override;
};