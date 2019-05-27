//ship.h
#pragma once

#include <vector>

#define AMOUNT_OF_X1_SHIPS 3
#define AMOUNT_OF_X2_SHIPS 2
#define AMOUNT_OF_X3_SHIPS 1
#define AMOUNT_OF_X4_SHIPS 0

class Ship
{
private:
	
protected:
	int size_of_ship;
	int amount_of_ships;

public:
    Ship (int shipSize) {Set_size_of_ship(shipSize);}
    
	int Get_size_of_ship();
	void Set_size_of_ship(int size_of_ship);

	virtual int Get_amount_of_ships() = 0;
	virtual void Set_amount_of_ships(int amount_of_ships) = 0;
};
