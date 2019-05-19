//ship.h
#pragma once

#include <vector>

class Ship
{
private:
	
protected:
	int size_of_ship;
	int amount_of_ships;

public:
	int Get_size_of_ship();
	void Set_size_of_ship(int size_of_ship);

	virtual int Get_amount_of_ships() = 0;
	virtual void Set_amount_of_ships(int amount_of_ships) = 0;
};