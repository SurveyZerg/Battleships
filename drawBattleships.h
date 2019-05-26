// Library for Battleships for drawing different things

#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 12
#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);                      // SPI hardware interface
//MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES); // Arbitrary pins

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

void printPoint(int x, int y) {
   mx.setPoint(x,y, true);
}

void clearPoint(int x, int y) {
  mx.setPoint(x,y, false);
}

void blinkingPoint(int x,int y) {
  mx.setPoint(x,y, true);
  delay(100);
  mx.setPoint(x,y, false);
  delay(100);
}

void printRow(int x ) {
  for(int i=0; i<8;++i) 
      printPoint(x,i);
}

void printColumn(int y) {
  for(int i=0; i<8;++i) 
      printPoint(i,y);
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

void drawBoom(){
  for (int i=0;i<8;++i) {
    drawCircle(i);
    delay(300); // Maybe must put bigger delay
  }
}
