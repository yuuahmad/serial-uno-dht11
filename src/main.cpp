// #include <Arduino.h>
// #include <Adafruit_Sensor.h>
// #include <DHT.h>
// #include <DHT_U.h>
// #define DHTPIN 2      // Digital pin connected to the DHT sensor
// #define DHTTYPE DHT11 // DHT 11
// DHT_Unified dht(DHTPIN, DHTTYPE);

// uint32_t delayMS;

// void setup()
// {
//   Serial.begin(9600);
//   // Initialize device.
//   dht.begin();
//   sensor_t sensor;
//   delayMS = sensor.min_delay / 1000;
// }

// void loop()
// {
//   // Delay between measurements.
//   delay(delayMS);
//   // Get temperature event and print its value.
//   sensors_event_t event;
//   dht.temperature().getEvent(&event);
//   dht.humidity().getEvent(&event);
//   if (isnan(event.temperature) || isnan(event.relative_humidity))
//   {
//     Serial.println(F("#0#0#$"));
//   }
//   else
//   {
//     Serial.print(F("#"));
//     Serial.print(event.temperature);
//     Serial.print(F("#"));
//     Serial.print(event.relative_humidity);
//     Serial.println(F("#$"));
//   }
// }

#include <Arduino.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2 // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment the type of sensor in use:
#define DHTTYPE DHT11 // DHT 11
// #define DHTTYPE DHT22 // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

// See guide for details on sensor wiring and usage:
//   https://learn.adafruit.com/dht/overview

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup()
{
  Serial.begin(9600);
  // Initialize device.
  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));
  // Print temperature sensor details.
  sensor_t sensor;
  delayMS = sensor.min_delay / 1000;
}

void loop()
{
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature))
  {
    Serial.println(F("#0#0#$"));
  }
  Serial.print(F("#"));
  Serial.print(event.temperature);

  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity))
  {
    Serial.println(F("#0#0#$"));
  }
  Serial.print(F("#"));
  Serial.print(event.relative_humidity);
  Serial.print(F("#"));
  Serial.println(F("$"));
}