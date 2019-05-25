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
}


void loop() {
  
  int sensorValue = analogRead(A0);
  int voltage = sensorValue * (8 / 1023.0);
  Serial.println(voltage);
  
  int sensorValue2 = analogRead(A1);
  int voltage2 = sensorValue2 * (8 / 1023.0);
  Serial.println(voltage2);
  
  //printBigX();
  //delay(1000);
  //printBigXblink();
  //delay(100);
   //mx.clear();
   /*for (int i=0;i<8;++i) {
      blinkingPoint(0,i);
      delay(100);
   }*/
   blinkingPoint(voltage,voltage2); // Blinks when user chooses the location with Potentiometer

}
