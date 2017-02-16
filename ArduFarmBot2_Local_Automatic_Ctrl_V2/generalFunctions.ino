
/***************************************************
* Wait Button to be pressed a defined time in seconds
****************************************************/
void waitButtonPress (int waitTime)
{
  long startTiming = millis();
  while (debounce(SENSORS_READ_BUTTON)) 
  { 
    if ((millis()-startTiming) > (waitTime*1000)) break;
  }
}

/***************************************************
* Starting Timers
****************************************************/
void startTimers(void)
{
  timer.setInterval(READ_BUTTONS_TM*1000, readLocalCmd);
  timer.setInterval(READ_SOIL_TEMP_TM*1000, getSoilTempData);
  timer.setInterval(READ_AIR_DATA_TM*1000, getDhtData);
  timer.setInterval(READ_SOIL_HUM_TM*1000, getSoilMoisterData);
  timer.setInterval(AUTO_CTRL_TM*1000, autoControlPlantation);
  //timer.setInterval(DISPLAY_DATA_TM*1000, displayData);
}

/***************************************************
* Debouncing a key
****************************************************/
boolean debounce(int pin)
{
  boolean state;
  boolean previousState;
  const int debounceDelay = 30;
  
  previousState = digitalRead(pin);
  for(int counter=0; counter< debounceDelay; counter++)
  {
    delay(1);
    state = digitalRead(pin);
    if(state != previousState)
    {
      counter = 0;
      previousState = state;
    } 
  }
  return state;
}
