# ArduFarmBot-2
Automatic Gardening System with NodeMCU and Blynk
<p> This complete tutorial can be found at: https://www.instructables.com/id/Automatic-Gardening-System-With-NodeMCU-and-Blynk-/ </p>
<p>Some time ago, we developed a similar project: <a href="https://www.instructables.com/id/ArduFarmBot-Controlling-a-Tomato-Home-Farm-Using-A/">"ArduFarmBot: Controlling a Tomato Home Farm using Arduino and IoT"</a>. On this new version, the <strong><em>ArduFarmBot 2,</em></strong> the main specification of the original project will be kept. We will develop a fully automated Gardening System based on NodeMCU ESP8266 and an IoT app, the BLYNK. </p><p>Basically, information from a plantation will be captured, temperature and humidity, both from air and soil. Based on those data, the ArduFarmBot 2 will decide the right amount (and when) the plantation should receive heat and water. Also the project should allow manual intervention of an operator in order to control a water pump and an electric lamp to generate heat for the plantation. The manual intervention must be both, local and remote via Internet.</p><p>In short, the system should receive as<strong> input</strong>:</p><ul>           
<li>Sensors:           
<ul>           
<li>Air Temperature               
</li><li>Air Relative Humidity                     
</li><li>Soil Temperature
</li><li>Soil Moisture (humidity)</li></ul></li></ul><ul> 
<li>Buttons:           
<ul>           
<li>Pump ON/OFF              
</li><li>Lamp ON/OFF</li></ul></li></ul><p>The system should provide as an <strong>output</strong>:</p><ul>           
<li>Actuators:           
<ul>           
<li>Relay for Pump control              
</li><li>Relay for Lamp control</li></ul></li></ul><ul> 
<li>Messages
<ul>
<li>Automatic messages must be sent on main events as:
<ul>
<li>Pump ON
</li><li>Lamo On
</li><li>System Off-line </li></ul></li></ul></li></ul><ul>
<li>Data Display           
<ul>           
<li>All analog and digital data should be available for instant  evaluation</li></ul></li></ul><ul> 
<li>Data Storage
<ul>
<li>
<p>Historic data should be storage remotely</p></li></ul></li></ul><p>The block diagram shows the main components of the project.</p>
<p> </p>
<img src=https://github.com/Mjrovai/ArduFarmBot-2/blob/master/ArduFarmBot2_Block_Diagram.png?raw=true alt="ArduFarmBot2 Block Diagram">
