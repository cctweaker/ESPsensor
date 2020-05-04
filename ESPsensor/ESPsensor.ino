ADC_MODE(ADC_VCC);
#include <ESP8266WiFi.h>
extern "C"
{
#include <espnow.h>
#include <user_interface.h>
}

#include "private.h"
#include "variables.h"

#include <Wire.h>
#include <SI7021.h>

SI7021 sensor;

void initVariant()
{
  WiFi.mode(WIFI_AP);
  wifi_set_macaddr(SOFTAP_IF, smac);
}

void setup()
{
  if (!sensor.begin(0, 2)) // connect SDA to GPIO0 and SCL to GPIO2
    gotoSleep();

  if (esp_now_init() != 0)
    gotoSleep();

  esp_now_set_kok(kok, 16);

  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);

  esp_now_add_peer(gmac, ESP_NOW_ROLE_SLAVE, WIFI_CHANNEL, key, 16);
  esp_now_set_peer_key(gmac, key, 16);

  esp_now_register_send_cb(txcb);
  esp_now_register_recv_cb(rxcb);
}

void loop()
{
  if (!SNS)
    readSensor();
  if (!SNT)
    sendData();
  if (ACK)
    gotoSleep();
}

void readSensor()
{

  si7021_env data = sensor.getHumidityAndTemperature();

  tmp = (float)data.celsiusHundredths / 100;
  hum = (float)data.humidityBasisPoints / 100;
  bat = (float)ESP.getVcc() / BATTFACTOR;

  SNS = true;
}

void sendData()
{
  sprintf(sendingData.text, "{\"t\":\"%s\",\"n\":\"%s\",\"tmp\":%.2f,\"hum\":%.2f\",\"bat\":%.2f}", TIP, NUME, tmp, hum, bat);

  uint8_t byteArray[sizeof(sendingData)];
  memcpy(byteArray, &sendingData, sizeof(sendingData));
  esp_now_send(gmac, byteArray, sizeof(sendingData));
  SNT = true;
}

void txcb(uint8_t *mac, uint8_t sendStatus)
{
  if (sendStatus == 0)
    ACK = true;
}

void rxcb(uint8_t *senderMac, uint8_t *incomingData, uint8_t len) {}

void gotoSleep()
{
  ESP.deepSleepInstant(SLEEP, RF_NO_CAL);
}