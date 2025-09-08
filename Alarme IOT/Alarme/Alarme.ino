#include "AdafruitIO_WiFi.h"
#include "NewPing.h"

#define BUZZER_PIN 27
#define LED_ALARME 13
#define BOTAO_FISICO 26
#define TRIG_PIN 12
#define ECHO_PIN 14

//Configuração do ultrassonico
#define MAX_DISTANCE 100
NewPing Sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_ALARME, OUTPUT);
  pinMode(BOTAO_FISICO, INPUT);

  Serial.begin(115200);

  while (!Serial);

  delay(1000);

}

void loop() {
  // Serial.print(F("Distancia Lida: "));
  // Serial.println(Sonar.ping_cm());
  // delay(500);

}
