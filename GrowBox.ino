#define RELE D7
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>

int numberOfSensors = 4;     // Number of sensors
int mainSensor = 0;          // Main sensor for control of temperature inside growbox
int initialTemperature = 23; // Initial temperature
int fanState = 1;            // Default fan state
bool temperatureLimit;

#define ONE_WIRE_BUS D2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

char auth[] = "YOUR_BLYNK_TOKEN";
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  sensors.begin();
  pinMode(RELE, OUTPUT);
}

BLYNK_WRITE(V21) {
  initialTemperature = param.asInt();
  Serial.println("Temperature :" + String(initialTemperature));
}

BLYNK_WRITE(V22) {
  fanState = param.asInt();
  Serial.println("Changed fan state: " + String(fanState == 0 ? "Off" : "On"));
}

void sendTemps() {
  sensors.requestTemperatures();

  int count = 0;
  while (count < numberOfSensors) {
    float temp = sensors.getTempCByIndex(count);
    Serial.print("t°" + String(count + 1) + ": " + String(temp));
    Serial.println();

    if (count == mainSensor) {
      if (temp > initialTemperature) {
        temperatureLimit = 1;
      } else {
        temperatureLimit = 0;
      }
    }

    Blynk.virtualWrite(count + 1, temp);

    ++count;
  }

  Serial.println("Fan state: " + String(initialTemperature == 0 ? "Off" : "On"));

  if (fanState == 0) {
    digitalWrite(RELE, 0);
  } else {
    digitalWrite(RELE, temperatureLimit);
  }
}

void loop () {
  Blynk.run();
  sendTemps();
}
