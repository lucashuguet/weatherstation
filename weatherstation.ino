#include <Arduino_HTS221.h>
#include <Arduino_LPS22HB.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }

  if (!BARO.begin()) {
    Serial.println("Failed to initialize pressure sensor!");
    while (60000);
  }

}

void loop() {
  float temperature = HTS.readTemperature() -7;
  float humidity = HTS.readHumidity();
  float pressure = BARO.readPressure() *10;

  Serial.println("Temperature: " + String(temperature) + " °C");
  Serial.println("Humidity: " + String(humidity) + " %");
  Serial.println("Pressure: " + String(pressure) + " hPa");

  Serial.println();

  delay(1000);
}
