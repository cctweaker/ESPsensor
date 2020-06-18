ADC_MODE(ADC_VCC);
#include <ESP8266WiFi.h>
extern "C"
{
#include <espnow.h>
#include <user_interface.h>
}

#include "private.h"

#include <Wire.h>
#include <SI7021.h>
#include <BME280_t.h>

SI7021 sensor;
BME280<> BMESensor;

void initVariant()
{
  WiFi.mode(WIFI_AP);
  wifi_set_macaddr(SOFTAP_IF, smac);

  WiFi.softAP(HOSTNAME, PASSWORD, WIFI_CHANNEL, HIDE_AP);
}

void setup()
{
  init_espnow();
  init_sensors();
}

void loop()
{
  if (!PREP)
    prepare_data();

  if (!SENT)
    send_data();

  if (ACK)
    goto_sleep();

  if (millis() > 1000) // sleep if data not sent in 1 second
    goto_sleep();
}

void goto_sleep()
{
  ESP.deepSleepInstant(SLEEP, RF_NO_CAL);
}

void goto_sleep_short()
{
  ESP.deepSleepInstant(60 * 1000 * 1000, RF_NO_CAL);
}