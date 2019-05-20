#include <ArduinoSTL.h>
#include "battleships_library.h"

void setup() 
{
  Game battleships;
  int kek = AMOUNT_OF_X1_SHIPS;
  for (int i = 0; i < kek;i++)
  {
     A.Set_ship(ships_x1[i],2+i,3+i);
  }
}

void loop() 
{
  

}
