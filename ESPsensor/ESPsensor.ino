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
  if (!sensor.begin(2, 0))
    goto_sleep();

  if (esp_now_init() != 0)
    goto_sleep();

  esp_now_set_kok(kok, 16);

  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);

  esp_now_add_peer(gmac, ESP_NOW_ROLE_SLAVE, WIFI_CHANNEL, key, 16);
  esp_now_set_peer_key(gmac, key, 16);

  esp_now_register_send_cb(txcb);
  esp_now_register_recv_cb(rxcb);
}

void loop()
{
  if (!SENT)
    send_data();

  if (ACK)
    goto_sleep();

  if (millis() > 1000) // sleep if data not sent in 1 second
    goto_sleep();
}

void send_data()
{
  char tx[128];

  float tmp = 0;
  float hum = 0;
  float vin = 0;

  si7021_env data = sensor.getHumidityAndTemperature();

  tmp = (float)data.celsiusHundredths / 100;
  hum = (float)data.humidityBasisPoints / 100;
  vin = (float)ESP.getVcc() / FACTOR;

  sprintf(tx, "{\"t\":\"%s\",\"n\":\"%s\",\"ID\":\"%x\",\"tmp\":%.2f,\"hum\":%.2f\",\"vin\":%.2f}", TIP, NAME, ESP.getChipId(), tmp, hum, vin);

  uint8_t byteArray[sizeof(tx)];
  memcpy(byteArray, &tx, sizeof(tx));
  esp_now_send(gmac, byteArray, sizeof(tx));

  SENT = true;
}

void txcb(uint8_t *mac, uint8_t sendStatus)
{
  if (sendStatus == 0)
    ACK = true;
}

void rxcb(uint8_t *senderMac, uint8_t *incomingData, uint8_t len) {}

void goto_sleep()
{
  ESP.deepSleepInstant(SLEEP, RF_NO_CAL);
}