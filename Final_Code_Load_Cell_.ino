/**
 *
 * HX711 library for Arduino - example file
 * https://github.com/bogde/HX711
 *
 * MIT License
 * (c) 2018 Bogdan Necula
 *
**/
#include "HX711.h"

#define calibration_factor -7050.0 


const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 4;


HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 Demo");

  Serial.println("Initializing the scale");

  
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());    
  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));   
  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));   

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);  


  scale.set_scale(-7050.f);                      
  scale.tare();               

  Serial.println("After setting up the scale:");

  Serial.print("read: \t\t");
  Serial.println(scale.read());         
          
  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20));       

  Serial.print("get value: \t\t");
  Serial.println(scale.get_value(5));   
  
  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);       
  

  Serial.println("Readings:");
}

void loop() {
  Serial.print("one reading:\t");
  
  Serial.print(scale.get_units()*15.67);
  Serial.print("\n");
 // de
 // Serial.println(scale.get_units(10),10);

  scale.power_down();             
  delay(100);
  scale.power_up();
}
