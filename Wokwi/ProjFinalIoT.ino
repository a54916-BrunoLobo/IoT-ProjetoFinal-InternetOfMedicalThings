#include <WiFi.h>
#include <PubSubClient.h>
#include "DHTesp.h"

DHTesp dht1, dht2, dht3, dht4;

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  WiFi.begin("Wokwi-GUEST", "");
  Serial.print("Conectando ao Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" conectado!");
}

void callback(char* topic, byte* payload, unsigned int length) {
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("A tentar conectar ao MQTT...");
    if (client.connect("ESP32-Pacientes")) {
      Serial.println(" conectado.");
    } else {
      Serial.print("Falhou. rc=");
      Serial.print(client.state());
      Serial.println(" a tentar novamente em 2s...");
      delay(2000);
    }
  }
}

void publicarTemperaturas() {
  TempAndHumidity t1 = dht1.getTempAndHumidity();
  TempAndHumidity t2 = dht2.getTempAndHumidity();
  TempAndHumidity t3 = dht3.getTempAndHumidity();
  TempAndHumidity t4 = dht4.getTempAndHumidity();

  float sensores[4] = {
    isnan(t1.temperature) ? 36.5 : t1.temperature,
    isnan(t2.temperature) ? 36.5 : t2.temperature,
    isnan(t3.temperature) ? 36.5 : t3.temperature,
    isnan(t4.temperature) ? 36.5 : t4.temperature
  };

  String json = "{";
  json += "\"paciente1\":" + String(sensores[0], 1);
  for (int i = 2; i <= 4; i++) {
    json += ",\"paciente" + String(i) + "\":" + String(sensores[i - 1], 1);
  }
  json += "}";

  Serial.println(json);
  client.publish("IoT/pacientes/temperaturas", json.c_str());
}

void setup() {
  Serial.begin(115200);

  dht1.setup(18, DHTesp::DHT22);
  dht2.setup(19, DHTesp::DHT22);
  dht3.setup(25, DHTesp::DHT22);
  dht4.setup(26, DHTesp::DHT22);

  setup_wifi();
  client.setServer("broker.emqx.io", 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  publicarTemperaturas();

  delay(3000);
}
