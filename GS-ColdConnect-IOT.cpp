#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

#define LEDPIN 5
#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Wokwi-GUEST"; //Usando o wifi do Wokwi
const char* password = "";


// Configuração MQTT
const char* mqtt_server = "broker.hivemq.com";  // Usando um broker público
const char* mqtt_topic = "coldconnect/sensores"; // Tópico personalizado

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
}

void reconnect() {
  // Loop até conectar
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("conectado");
    } else {
      Serial.print("falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Falha ao ler do sensor DHT!");
    return;
  }

  if (temperatura <= -16) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }

  String payload = "{\"temperatura\": " + String(temperatura) + ", \"umidade\": " + String(umidade) + "}";
  
  Serial.print("Enviando mensagem: ");
  Serial.println(payload);

  client.publish(mqtt_topic, (char*) payload.c_str());

  delay(5000); // Aguarda 5 segundos antes de enviar novamente
}
