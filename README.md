# ArduFarmBot-2
Automatic Gardening System with NodeMCU and Blynk

Some time ago, we developed a similar project: "ArduFarmBot: Controlling a Tomato Home Farm using Arduino and IoT". On this new version, the ArduFarmBot 2, the main specification of the original project will be kept. We will develop a fully automated Gardening System based on NodeMCU ESP8266 and an IoT app, the BLYNK.

Basically, information from a plantation will be captured, temperature and humidity, both from air and soil. Based on those data, the ArduFarmBot 2 will decide the right amount (and when) the plantation should receive heat and water. Also the project should allow manual intervention of an operator in order to control a water pump and an electric lamp to generate heat for the plantation. The manual intervention must be both, local and remote via Internet.

In short, the system should receive as input:
  Sensors: Air Temperature, Air Relative Humidity, Soil Temperature and Soil Moisture (humidity)
  Buttons: Pump ON/OFF, Lamp ON/OFF and Sensors READ

The system should provide as an output:
  Actuators: Relay for Pump control and Relay for Lamp control
  Messages: Automatic messages must be sent on main events as: "Pump ON" and "Lamp On" and System Off-line
  Data Display: All analog and digital data should be available for instant evaluation
  Data Storage: Historic data should be storage remotely
