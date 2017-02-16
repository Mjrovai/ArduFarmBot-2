/***************************************************************************************************************
 *  ArduFarmBot using NodeMCU ESP-12 Develop Kit V1.0
 *  DHT connected to NodeMCU pin D3 (Ambient Temperature and Relative Humidity)
 *  Soil Moister Sensor connected to A0
 *  Sensor Data on local OLED Display
 *  Local Command via buttons 
 *  OLED Display is off as default. Press Sensor Button to update and display data
 *  Introduced the function "waitButtonPress (int waitTime)", to break initial loop
 *       
 *  Version 1.0 - Manual and Local Control - Developed by MJRovai 15 Feb 2017
 ********************************************************************************************************************************/
#define SW_VERSION "   SW Ver. 1,0" // SW version will appears at innitial LCD Display
#include "stationDefines.h"       // Project definitions

/* ESP */
#include <ESP8266WiFi.h>

/* TIMER */
#include <SimpleTimer.h>
SimpleTimer timer;

/* OLED */
#include <ACROBOTIC_SSD1306.h> // library for OLED: SCL ==> D1; SDA ==> D2
#include <SPI.h>
#include <Wire.h>

/* DHT22*/
#include "DHT.h"
DHT dht(DHTPIN, DHTTYPE);

/* DS18B20 Temperature Sensor */
#include <OneWire.h>
#include <DallasTemperature.h>
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);

void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println("ArduFarmBot 2");
  Serial.println(".... Starting Setup");
  Serial.println(" ");

  pinMode(PUMP_PIN, OUTPUT);
  pinMode(LAMP_PIN, OUTPUT);
  pinMode(PUMP_ON_BUTTON, INPUT_PULLUP);
  pinMode(LAMP_ON_BUTTON, INPUT_PULLUP);
  pinMode(SENSORS_READ_BUTTON, INPUT_PULLUP);
  pinMode(soilMoisterVcc, OUTPUT);
  
  oledStart();
  dht.begin();
  DS18B20.begin();

  digitalWrite(PUMP_PIN, LOW);
  digitalWrite(LAMP_PIN, LOW);
  digitalWrite (soilMoisterVcc, LOW);

  waitButtonPress (10); // Wait 10 seconds for Sensor Button to be pressed 
  oled.clearDisplay();
  startTimers();
}

void loop()
{
  timer.run(); // Initiates SimpleTimer
}

/****************************************************************
* Read local commands (Pump and Lamp buttons are normally "HIGH"):
****************************************************************/
void readLocalCmd() 
{  
  boolean digiValue = debounce(PUMP_ON_BUTTON);
  if (!digiValue) 
  {
    pumpStatus = !pumpStatus;
    aplyCmd();
  }

  digiValue = debounce(LAMP_ON_BUTTON);
  if (!digiValue) 
  {
    lampStatus = !lampStatus;
    aplyCmd();
  }

  digiValue = debounce(SENSORS_READ_BUTTON);
  if (!digiValue) 
  {
    turnOffOLED = !turnOffOLED;
    if (!turnOffOLED)
    {
      oled.setTextXY(0,0); oled.putString("UPDATING SENSORS");
      getDhtData();
      getSoilMoisterData();
      getSoilTempData();
      oledStart();
      displayData();
    }else oled.clearDisplay();
  }
}

/***************************************************
* Receive Commands and act on actuators
****************************************************/
void aplyCmd()
{
  if (pumpStatus == 1) 
  {
    digitalWrite(PUMP_PIN, HIGH);
    if (!turnOffOLED) displayData(); 
  }
  else
      {
        digitalWrite(PUMP_PIN, LOW);
        if (!turnOffOLED) displayData();
      }
  
  if (lampStatus == 1) 
  {
    digitalWrite(LAMP_PIN, HIGH);
    if (!turnOffOLED) displayData();
  }
  else
      {
        digitalWrite(LAMP_PIN, LOW);
        if (!turnOffOLED) displayData();
      }
}



