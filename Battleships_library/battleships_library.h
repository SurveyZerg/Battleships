//battleships_library.h
#pragma once

#include "player.h"

class Ship_x1;
class Ship_x2;
class Ship_x3;
class Ship_x4;
class Player;
class Map;

extern Player A;
extern Player B;

extern std::vector <Ship_x1> ships_x1;
extern std::vector <Ship_x2> ships_x2;
extern std::vector <Ship_x3> ships_x3;
extern std::vector <Ship_x4> ships_x4;

class Game
{
private:

public:
	Game();
};

