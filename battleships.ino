#include <MD_MAX72xx.h>
#include <SPI.h>
#include <ArduinoSTL.h>
#include "battleships_library.h"

#define DEBUG 0

#if DEBUG
#define PRINT(s, v)   { Serial.print(F(s)); Serial.print(v); }      // Print a string followed by a value (decimal)
#define PRINTX(s, v)  { Serial.print(F(s)); Serial.print(v, HEX); } // Print a string followed by a value (hex)
#define PRINTB(s, v)  { Serial.print(F(s)); Serial.print(v, BIN); } // Print a string followed by a value (binary)
#define PRINTC(s, v)  { Serial.print(F(s)); Serial.print((char)v); }  // Print a string followed by a value (char)
#define PRINTS(s)     { Serial.print(F(s)); }                       // Print a string
#else
#define PRINT(s, v)   // Print a string followed by a value (decimal)
#define PRINTX(s, v)  // Print a string followed by a value (hex)
#define PRINTB(s, v)  // Print a string followed by a value (binary)
#define PRINTC(s, v)  // Print a string followed by a value (char)
#define PRINTS(s)     // Print a string
#endif

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 12
#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS

#define Button1_PIN A2
#define Button2_PIN A3

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);                      // SPI hardware interface
//MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES); // Arbitrary pins

void printPoint(int x, int y);

void show_map(Player* player)
{
  for (int Line = 0; Line < HEIGHT; Line++)
  {
    for (int Column = 0; Column < LENGTH; Column++)
    {
      if (player->map.ship_on_map[Line][Column])
      {
        //std::cout << "| ";
        printPoint(Line, Column);
      }
      else
      {
        //std::cout << "- ";
        //clearPoint(Line, Column);
      }
    }
    //std::cout << std::endl;
  }
}
void resetMatrix(void)
{
  mx.control(MD_MAX72XX::INTENSITY, MAX_INTENSITY/2);
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
  mx.clear();
}

Player* getPlayer(bool player);
void drawPlayer(bool player);
void setup() {
    mx.begin();
    resetMatrix();
    Serial.begin(9600);
    
    // Can do illustration of some default map here to show that it is a "Battleships" game
    
    //blinkingPoint(readVoltage1(), readVoltage2());
    
    Game battleships;

   // drawNumber1();
    //drawBoom();
}
    bool orientation = 1; // 1 means vertically; 0 means horisontally
    bool player = 0; // 0 means player1; 1 means player2
    int shipsCounter = 0;
    int currentShipSize = 3;
    float buttonON;
    float button2ON;
void loop() {
  
    //PRINTS("Hello"); // Does it work??????????????
     int kek = analogRead(A2);
    int kek1 = analogRead(A3);
    buttonON = kek * (5.0 / 1023.0);
    button2ON = kek1 * (5.0 / 1023.0);
    
    Serial.println(buttonON );
    Serial.println(button2ON );
    
    // Setting ships ------------------------------------------------------------------------------------
    if (buttonON < 1) {
      Serial.println("blink");
        //blinkingPoint(readVoltage1(), readVoltage2());
        blinkingShip(currentShipSize, readVoltage1(), readVoltage2(), orientation);
        //getPlayer()->show_map();
    }
    if (button2ON >=1){
        orientation = !orientation;
        Serial.println("aaaa");
    }
    if (buttonON >= 1) {
        // Put the ship here if player knocked the button
        if (getPlayer(player)->checkAroundShip( readVoltage1(), readVoltage2(), currentShipSize, orientation)) {
            // We cannot put new ships here
            //break;
            resetMatrix();
           drawPlayer(player); //???
            show_map(getPlayer(player));
        }
        else {
          if(shipsCounter ==0)
            getPlayer(player)->Set_ship(ships_x3[shipsCounter], readVoltage1(), readVoltage2(), orientation);
          if(shipsCounter <=2)
            getPlayer(player)->Set_ship(ships_x2[shipsCounter], readVoltage1(), readVoltage2(), orientation);
          if(shipsCounter <=5)
            getPlayer(player)->Set_ship(ships_x1[shipsCounter], readVoltage1(), readVoltage2(), orientation);
          if(player)
            ++shipsCounter;
            
            if (shipsCounter == 1 || shipsCounter == 3)
                --currentShipSize;
            player = !player;
            resetMatrix();
            drawPlayer(player);
            show_map(getPlayer(player));
        }
    }
    
    // Starting game ------------------------------------------------------------------------------------
    if (shipsCounter == 6) {
        // The game should begin here
        int potentiometrLine = 1;
  int potentiometrColumn = 1;
  int button = 0;
  bool shoot_finished = false;
  while (battleships.checkWin())
  {
    if (shoot_finished == false)
    {
      if (buttonON == 1)
      {
        if (A.shoot(&B, potentiometrLine - 1, potentiometrColumn - 1))
        {
          //Думаю, что здесь везде нужны временные паузы, чтобы и кнопка успела отжаться хотя бы
          //попадание
          shoot_finished = false;
        }
        else
        {
          //промах
          shoot_finished = true;
        }
      }
    }
    if (shoot_finished == true)
    {
      if (button == 1)
      {
        if (B.shoot(&A, potentiometrLine - 1, potentiometrColumn - 1))
        {
          //Думаю, что здесь везде нужны временные паузы, чтобы и кнопка успела отжаться хотя бы
          //попадание
          shoot_finished = true;
        }
        else
        {
          //промах
          shoot_finished = false;
        }
      }
    }
  }
    }

}

int readVoltage1() {
    //Serial.begin(9600);
    int sensorValue = analogRead(A0);
    int voltage = sensorValue * (8 / 1023.0);
    return voltage;
    //Serial.println(voltage);
}

int readVoltage2() {
    //Serial.begin(9600);
    int sensorValue2 = analogRead(A1);
    int voltage2 = sensorValue2 * (8 / 1023.0);
    return voltage2;
    //Serial.println(voltage2);
}

Player* getPlayer(bool player) {
    if (!player)      //means that it is player1
        return &A;
    else            //means that it is player2
        return &B;
}

void printPoint(int x, int y) {
   mx.setPoint(x,y, true);
}

void clearPoint(int x, int y) {
  mx.setPoint(x,y, false);
}

void blinkingPoint(int x,int y) { // Blinks when player chooses the location with Potentiometer
  printPoint(x,y);
  delay(100);
  clearPoint(x,y);
  delay(100);
}

/*void blinkingShip(int x, int y, int shipSize, bool orientation) {
    if (orientation) {  // vertical orientation
        for (int i=0; i<shipSize; ++i)
            printPoint(x,y+i);
        delay(100);
        for (int i=0; i<shipSize; ++i)
            clearPoint(x,y+i);
        delay(100);
    }
    else {              // horisontal orientation
        for (int i=0; i<shipSize; ++i)
            printPoint(x+i,y);
        delay(100);
        for (int i=0; i<shipSize; ++i)
            clearPoint(x+i,y);
        delay(100);
    }
}*/

void blinkingShip(int currentShipSize, int Line, int Column, bool vertically)
{
  if (vertically == false)
  {
    int a = -1; //счетчик, чтобы правильно поставить корабль, когда только часть выходит за пределы
    for (int i = 0;i < currentShipSize; i++)
    {
      if (Column + i < LENGTH)
      {
        printPoint(Column + i,Line);
        a++;
      }
      else if (Column + i >= LENGTH)
      {
        printPoint(Column - i + a,Line);
      }
    }
    delay(100);
    a = -1;
    for (int i = 0;i < currentShipSize; i++)
   {
      if (Column + i < LENGTH)
      {
        clearPoint(Column + i,Line);
        a++;
      }
      else if (Column + i >= LENGTH)
      {
        clearPoint(Column - i + a,Line);
      }
    }
    delay(100);
  }
  else if (vertically == true)
  {
    int a = -1; //счетчик, чтобы правильно поставить корабль, когда только часть выходит за пределы
    for (int i = 0; i < currentShipSize; i++)
    {
      if (Line + i < HEIGHT)
      {
        printPoint(Column,Line + i);
        a++;
      }
      else if (Line + i >= HEIGHT)
      {
        printPoint(Column,Line - i + a);
      }
    }
    delay(100);
    a = -1;
        for (int i = 0; i < currentShipSize; i++)
    {
      if (Line + i < HEIGHT)
      {
        clearPoint(Column,Line + i);
        a++;
      }
      else if (Line + i >= HEIGHT)
      {
        clearPoint(Column,Line - i + a);
      }
    }
    delay(100);
  }
}

void printRow(int x ) {
  for(int i=0; i<8;++i) 
      printPoint(x,i);
}

void printColumn(int y) {
  for(int i=0; i<8;++i) 
      printPoint(i,y);
}

void clearColumn(int y) {
  for(int i=0; i<8;++i) 
      clearPoint(i,y);
}

void printBigX() {
  for(int i=0; i<8;++i) 
      printPoint(i,i);
  for(int i=0; i<8;++i) 
      printPoint(i,7-i);
}

void printBigXblink() {
  for(int i=0; i<8;++i) {
      printPoint(i,i);
      delay(random(100));
  }
  for(int i=0; i<8;++i) {
      printPoint(i,7-i);
      delay(random(100));
  }
}

void drawPlayer(bool player) {
    if(!player) {
        drawNumber1();
        delay(700);
    }
    else {
        drawNumber2();
        delay(700);
    }
}

void drawNumber1() {
    printPoint(2,3);
    printPoint(3,2);
    printPoint(4,1);
    printColumn(5);
    delay(1000);
    clearPoint(2,3);
    clearPoint(3,2);
    clearPoint(4,1);
    clearColumn(5);
}

void drawNumber2() {
    printPoint(2,2);
    printPoint(3,1);
    printPoint(4,0);
    printPoint(5,1);
    printPoint(6,2);
    printPoint(5,3);
    printPoint(4,4);
    printPoint(3,5);
    printPoint(2,6);
    printPoint(1,7);
    printPoint(2,7);
    printPoint(3,7);
    printPoint(4,7);
    printPoint(5,7);
    delay(1000);
    clearPoint(2,2);
    clearPoint(3,1);
    clearPoint(4,0);
    clearPoint(5,1);
    clearPoint(6,2);
    clearPoint(5,3);
    clearPoint(4,4);
    clearPoint(3,5);
    clearPoint(2,6);
    clearPoint(1,7);
    clearPoint(2,7);
    clearPoint(3,7);
    clearPoint(4,7);
    clearPoint(5,7);
}

void drawBoom(){
    for (int i=0;i<8;++i) {
        drawCircle(i);
        delay(300); // Maybe must put bigger delay
    }
}

void drawCircle(int radius) {
  if (radius == 0) {
     printPoint(3,3);
     printPoint(3,4);
     printPoint(4,4);
     printPoint(4,3);
  }
  if (radius==1) {
     printPoint(3,2);
     printPoint(4,2);
     printPoint(2,3);
     printPoint(2,4);
     printPoint(3,6);
     printPoint(4,6);
     printPoint(5,3);
     printPoint(5,4);
  }
  if (radius==2) {
     printPoint(3,1);
     printPoint(4,1);
     printPoint(2,2);
     printPoint(1,3);
     printPoint(1,4);
     printPoint(2,5);
     printPoint(3,6);
     printPoint(4,6);
     printPoint(5,5);
     printPoint(6,3);
     printPoint(6,4);
     printPoint(5,2);
  }
  if (radius==3) {
    printPoint(3,0);
    printPoint(4,0);
    printPoint(2,1);
    printPoint(1,2);
    printPoint(0,3);
    printPoint(0,4);
    printPoint(1,5);
    printPoint(2,6);
    printPoint(3,7);
    printPoint(4,7);
    printPoint(5,6);
    printPoint(6,5);
    printPoint(7,3);
    printPoint(7,4);
    printPoint(6,2);
    printPoint(5,1);
  }
  if (radius==4) {
    printPoint(3,0);
    printPoint(4,0);
    printPoint(2,1);
    printPoint(1,2);
    printPoint(0,3);
    printPoint(0,4);
    printPoint(1,5);
    printPoint(2,6);
    printPoint(3,7);
    printPoint(4,7);
    printPoint(5,6);
    printPoint(6,5);
    printPoint(7,3);
    printPoint(7,4);
    printPoint(6,2);
    printPoint(5,1);
  }
  if (radius==5) {
    printPoint(2,0);
    printPoint(1,1);
    printPoint(0,2);
    printPoint(0,5);
    printPoint(1,6);
    printPoint(2,7);
    printPoint(5,7);
    printPoint(6,6);
    printPoint(7,5);
    printPoint(7,2);
    printPoint(6,1);
    printPoint(5,0);
  }
  if (radius==6) {
    printPoint(1,0);
    printPoint(0,1);
    printPoint(0,6);
    printPoint(1,7);
    printPoint(6,7);
    printPoint(7,6);
    printPoint(7,1);
    printPoint(6,0);
  }
  if (radius==7) {
    printPoint(0,0);
    printPoint(0,7);
    printPoint(7,7);
    printPoint(7,0);
  }
}
