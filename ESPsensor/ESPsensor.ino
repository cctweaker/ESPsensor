ADC_MODE(ADC_VCC);
#include <ESP8266WiFi.h>
extern "C"
{
#include <espnow.h>
#include <user_interface.h>
}
#include <Wire.h>
#include "example_private.h"

//

#ifdef SENSOR_SI7021
#include <SI7021.h>
SI7021 sensor;
#endif

//

#ifdef SENSOR_BME280
#include <BME280_t.h>
BME280<> BMESensor;
#endif

//

#ifdef SENSOR_DS1820
// todo
#endif

//

void initVariant()
{
  WiFi.mode(WIFI_AP);
  wifi_set_macaddr(SOFTAP_IF, mac);

  char HOSTNAME[32];
  sprintf(HOSTNAME, "%s_%06x", FWN, ESP.getChipId());

  WiFi.softAP(HOSTNAME, PASSWORD, WIFI_CHANNEL, HIDE_AP);
}

//

void setup()
{
  init_espnow();
  init_sensors();
}

//

void loop()
{
  if (!PREP)
    prepare_data();

  if (!SENT)
    send_data();

  if (ACK)
    goto_sleep();

  if (millis() > 600) // sleep if data not yet sent/acknowledged
    goto_sleep();
}

//

void goto_sleep()
{
  ESP.deepSleepInstant(SLEEP, RF_NO_CAL);
}
