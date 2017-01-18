////Including libraries and varaiables for screen
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

//Including libraries for temperature sensor
#include <math.h>
int sensorPin = A3; // select the input pin for the potentiometer

//Maths for temperature conversion:
double Thermistor(int RawADC) {
  double Temp;
  Temp = log(10000.0*((1024.0/RawADC-1))); 
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;            // Convert Kelvin to Celcius
   //Temp = (Temp * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
   return Temp;
}

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize wi
  
  display.clearDisplay();
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
//  display.setCursor(30,30);
}

void loop() {
 int readVal=analogRead(sensorPin);
 
 display.setCursor(0,20);
 display.println("Current temperature:");
 
 display.setCursor(50,55);
 display.println("Menu");



 double temp =  Thermistor(readVal);
 display.setCursor(0,30);
 display.print(temp);
 display.println(" C");
 display.display();
 //Serial.println(readVal);  // display tempature
 delay(500);
 display.clearDisplay();
  
}
