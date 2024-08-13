#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int RELAY_PIN = 3;

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

// the loop function runs over and over again forever
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    return;
  }
  if (t >= 14 ) {
    digitalWrite(RELAY_PIN, HIGH);
        
  } else {
    digitalWrite(RELAY_PIN, LOW);
  }
  Serial.print(t);
  Serial.print(F("°C "));
  delay(2000);
}
