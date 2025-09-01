#include "AdafruitIO_WiFi.h"

// #define WIFI_SSID "" 
// #define WIFI_PASS "" 

// #define IO_USERNAME ""
// #define IO_KEY ""

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

#define pinLed 14 

AdafruitIO_Feed *botaoLed = io.feed("botaoled");

void handleBotaoLed(AdafruitIO_Data *data) {
  Serial.print("Recebido: ");
  Serial.println(data->toString());

  if (data->toBool()) {
    digitalWrite(pinLed, HIGH);
    Serial.println("LED ligado.");
  } else {
    digitalWrite(pinLed, LOW);
    Serial.println("LED desligado.");
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(pinLed, OUTPUT);

  Serial.print("Conectando ao Adafruit IO");
  io.connect();

  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println(io.statusText());

  botaoLed->onMessage(handleBotaoLed);
}

void loop() {
  io.run();
}