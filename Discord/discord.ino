#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include "Discord.h"

#define BMP280_ADDRESS 0x76
Adafruit_BMP280 bmp;

float Temperature, Pressure, Altitude;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  
  unsigned status;
  status = bmp.begin(BMP280_ADDRESS);
  if(!status) {
    Serial.println("No BMP280 sensor found");
  }
  connect_WIFI();
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop() {
  Temperature = bmp.readTemperature();
  Pressure =  bmp.readPressure();
  Altitude = bmp.readAltitude(1013.25);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  Send_MSG("Temperature: " + String(Temperature) + "*C Pressure: " + String(Pressure) + "Pa Altitude: " + String(Altitude) + "m");
  delay(10000);

}

