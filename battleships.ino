#include <MD_MAX72xx.h>
#include <SPI.h>

#include <drawBattleships.h>

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

#define Button1_PIN 7
#define Button2_PIN 8

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);                      // SPI hardware interface
//MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES); // Arbitrary pins

void resetMatrix(void)
{
  mx.control(MD_MAX72XX::INTENSITY, MAX_INTENSITY/2);
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
  mx.clear();
}


void setup() {
    mx.begin();
    resetMatrix();
    #if DEBUG
    Serial.begin(57600);
    #endif
    Serial.begin(9600);
    
    // Can do illustration if some map here to show that it is a "Battleships" game
    blinkingPoint(readVoltage1(), readVoltage2());
    
    Game battleships;

}


void loop() {
  
    PRINTS("Hello"); // Does it work??????????????
  
    bool buttonON = digitalRead(Button1_PIN);
    bool button2ON = digitalRead(Button2_PIN);
    bool orientation = 1; // 1 means vertically; 0 means horisontally
    
    bool User = 0; // 0 means User1; 1 means User2
    
    int shipsCounter = 0;
    
    while (!buttonON) {
        blinkingPoint(readVoltage1(), readVoltage2()); // Blinks when user chooses the location with Potentiometer
    }
    if (button2ON)
        orientation = !orientation;
    if (buttonON) {
        if (checkAround( readVoltage1(), readVoltage2() )) {
            // We cannot put new ships here
            break;
        }
        else {
            // Put the ship here if user knocked the button
            // where to get shipPtr ??????
            map1.Set_ship(shipPtr, readVoltage1(), readVoltage2(), orientation);
            ++shipsCounter;
            User = !User;
        }
    }
    if (shipsCounter == 12)
        // The game should begin here
       

}


if (checkAround( readVoltage1(), readVoltage2() ))
// We cannot put new ships here
else
// Put the ship here if user knocked the button

//printBigX();
//delay(1000);
//printBigXblink();
//delay(100);
//mx.clear();
/*for (int i=0;i<8;++i) {
 blinkingPoint(0,i);
 delay(100);
 }*/

