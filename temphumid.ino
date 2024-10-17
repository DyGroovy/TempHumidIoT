#include <DHT.h>
#include <DHT_U.h>
#include "thingProperties.h"
#include <DHT.h>

#define DHTPIN 2 // D4 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();


  hum = humidity; 
  temp = temperature; 
  message = "Temperature = " + String(temp) + "  Humidity = " + String(hum);

  Serial.print("Humidity ");
  Serial.println(hum);
  Serial.print("Temperature ");
  Serial.println(temp);

  delay(1000);
}

/*
  Since Temperature is READ_WRITE variable, onTemperatureChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTemperatureChange()  {
  // Add your code here to act upon Temperature change
}

/*
  Since Humidity is READ_WRITE variable, onHumidityChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHumidityChange()  {
  // Add your code here to act upon Humidity change
}

/*
  Since Msg is READ_WRITE variable, onMsgChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMessageChange()  {
  // Add your code here to act upon Message change
  Serial.println("Message changed!");
}
/*
  Since Hum is READ_WRITE variable, onHumChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHumChange()  {
  // Add your code here to act upon Hum change
}
/*
  Since Temp is READ_WRITE variable, onTempChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTempChange()  {
  // Add your code here to act upon Temp change
}
