/***************************************************
 * Start OLED
 **************************************************/
void oledStart(void)
{
  Wire.begin();  
  oled.init();                      // Initialze SSD1306 OLED display
  clearOledDisplay();
  //oled.setFont(font5x7);            // Set font type (default 8x8)
  oled.clearDisplay();              // Clear screen
  oled.setTextXY(0,0);              
  oled.putString("  ArduFarmBot 2 ");
  oled.setTextXY(1,0);              
  oled.putString(String(SW_VERSION));
  oled.setTextXY(7,0); 
  oled.putString("Sensor Key ==>>");
}

/***************************************************
 * Display data at Serial Monitora & OLED Display
 **************************************************/
void displayData(void)
{ 
  oled.setTextXY(3,0); oled.putString("AirTmp [C] ");
  oled.setTextXY(3,11); oled.putString("     ");
  oled.setTextXY(3,11); oled.putString(String(airTemp));

  oled.setTextXY(4,0); oled.putString("AirHum [%] ");
  oled.setTextXY(4,11); oled.putString("     ");
  oled.setTextXY(4,11); oled.putString(String(airHum));

  oled.setTextXY(5,0); oled.putString("SoilTmp[C] ");
  oled.setTextXY(5,11); oled.putString("     ");
  oled.setTextXY(5,11); oled.putString(String(soilTemp));

  oled.setTextXY(6,0); oled.putString("SoilHum[%] ");
  oled.setTextXY(6,11); oled.putString("     ");
  oled.setTextXY(6,11); oled.putString(String(soilMoister));

  oled.setTextXY(7,0); oled.putString("PUMP: ");
  oled.setTextXY(7,6); oled.putString(String(pumpStatus));

  oled.setTextXY(7,7); oled.putString("  LAMP: ");
  oled.setTextXY(7,15); oled.putString(String(lampStatus));
}

/***************************************************
 * Clear OLED Display
 **************************************************/
void clearOledDisplay()
{
  oled.setFont(font8x8);
  oled.setTextXY(0,0); oled.putString("                ");
  oled.setTextXY(1,0); oled.putString("                ");
  oled.setTextXY(2,0); oled.putString("                ");
  oled.setTextXY(3,0); oled.putString("                ");
  oled.setTextXY(4,0); oled.putString("                ");
  oled.setTextXY(5,0); oled.putString("                ");
  oled.setTextXY(6,0); oled.putString("                ");
  oled.setTextXY(7,0); oled.putString("                ");
  oled.setTextXY(0,0); oled.putString("                ");              
}

