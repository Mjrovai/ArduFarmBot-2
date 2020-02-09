/***************************************************
 * Get DHT data
 **************************************************/
void getDhtData(void)
{
  float tempIni = airTemp;
  float humIni = airHum;
  airTemp = bme.readTemperature();
  airHum = bme.readHumidity();
  if (isnan(airHum) || isnan(airTemp))   // Check if any reads failed and exit early (to try again).
  {
    Serial.println("Failed to read from DHT sensor!");
    airTemp = tempIni;
    airHum = humIni;
    return;
  }
}

/***************************************************
 * Get Soil Moister Sensor data
 **************************************************/
void getSoilMoisterData(void)
{
  soilMoister = 0;
  digitalWrite (soilMoisterVcc, HIGH);
  delay (500);
  int N = 3;
  for(int i = 0; i < N; i++) // read sensor "N" times and get the average
  {
    soilMoister += analogRead(soilMoisterPin);   
    delay(150);
  }
  digitalWrite (soilMoisterVcc, LOW);
  soilMoister = soilMoister/N; 
  soilMoister = map(soilMoister, 600, 0, 0, 100); //LM393 on 5V (+Vin)
}

/***************************************************
 * Get SoilTemp sensor data
 **************************************************/
void getSoilTempData()
{
  DS18B20.requestTemperatures(); 
  soilTemp = DS18B20.getTempCByIndex(0);

  int newData = ((soilTemp + 0.05) * 10); //fix soilTemp value to 1 decimal place.
  soilTemp = (newData / 10.0);
}
