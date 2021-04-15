#include <TM1637.h>
#define CLK 2 
#define DIO 3 
TM1637 Display1(CLK, DIO);

#define CHAR_BLANK 127
const int ldrPin = A0;

void setup() {
  Serial.begin(9600);
  Display1.init();
  Display1.set(BRIGHTEST); // BRIGHT_TYPICAL = 2 , BRIGHT_DARKEST = 0 , BRIGHTEST = 7

void loop() {
  int ldrStatus = 100 - ((double) analogRead(ldrPin)) / 1024 * 100; // Normalize data to 100
  Serial.println(ldrStatus);
  int8_t number[] = {0,0, ldrStatus / 10 , ldrStatus % 10}; // Send to LCD
  Display1.display(number);  
  delay(1000); 
}