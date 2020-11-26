/////////////////////////////////////////////////
// Firmware specific
/////////////////////////////////////////////////
#define FWN "ESPsensor"
/////////////////////////////////////////////////

//

//
// rename this file to private.h before building
// and change the values BELOW this text to your liking
//

//

/////////////////////////////////////////////////
// select sensor type
/////////////////////////////////////////////////
// to reduce power consumption to the maximum
// it is better to have the firmware expect
// the correct sensor
// uncomment one of the below options
#define SENSOR_SI7021
// #define SENSOR_BME280
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// private MAC addresses
/////////////////////////////////////////////////
// select the MAC address that your ESP-Now gateway uses
// you can pick any address from the following private ranges
// as long as it is not used by any other device
// x2-xx-xx-xx-xx-xx
// x6-xx-xx-xx-xx-xx
// xA-xx-xx-xx-xx-xx
// xE-xx-xx-xx-xx-xx
uint8_t gmac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
// using a custom mac will allow you to change the ESP on the gateway without changing
// the programming on all ESP-Now devices
// hardware mac address assigned to the ESP is unchanged, just not used in this case
// make sure to use the same gateway mac address in all your projects!
//
uint8_t mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE}; // sensors
// uint8_t mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEF}; // buttons/switches
// uint8_t mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xF0}; // door switches
// uint8_t mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xF1}; // window switches
// uint8_t mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xF2}; // movement detectors, light barriers
// ESP-GW project reserves up to 6 mac addresses following its own mac
// ESP-Now protocol allows up to 6 mac addresses in encrypted mode
// to circumvent this limitation, a single mac address is assigned to multiple
// sensors of the same type
/////////////////////////////////////////////////

//

/////////////////////////////////////////////////
// KEYS, make sure they are the same for ESPGW-NOW!
/////////////////////////////////////////////////
// pick 16 random numbers to use as device key encoding key
uint8_t kok[16] = {0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF};
// pick 16 random numbers to use as device key
uint8_t key[16] = {0xFE, 0xED, 0xFE, 0xED, 0xFE, 0xED, 0xFE, 0xED, 0xFE, 0xED, 0xFE, 0xED, 0xFE, 0xED, 0xFE, 0xED};
/////////////////////////////////////////////////

//

/////////////////////////////////////////////////
// AP settings for this unit
// AP will appear briefly for about 200ms
// even so, we will password protect it and
// hide it from prying eyes
/////////////////////////////////////////////////
// select the channel that your ESP-Now gateway uses
// must be same as your ESP-Now gateway!!!
// 1-13 are valid choices
#define WIFI_CHANNEL 1
/////////////////////////////////////////////////
// PASSWORD is given just so no one will try to connect
// if HIDE_AP is 0
// device is powered for about 200 ms, maybe these precautions
// are overkill
#define PASSWORD "password"
/////////////////////////////////////////////////
// AP is hidden?
// 0 = visible
// 1 = hidden
#define HIDE_AP 1
/////////////////////////////////////////////////

//

/////////////////////////////////////////////////
// sleep time (message rate)
/////////////////////////////////////////////////
//            min  sec  msec   usec
#define SLEEP 10 * 60 * 1000 * 1000 // 10 minutes
// #define SLEEP  5 * 60 * 1000 * 1000 // 5 minutes
// #define SLEEP  2 * 60 * 1000 * 1000 // 2 minutes
// #define SLEEP  1 * 60 * 1000 * 1000 // 1 minute
// #define SLEEP  1 * 30 * 1000 * 1000 // 30 seconds
// estimate your power consumption here:
// https://3dstar.ro/calculator-consum-baterii-acumulatori
/////////////////////////////////////////////////

//

/////////////////////////////////////////////////
// flags
/////////////////////////////////////////////////
bool PREP = false; // prepare data flag
bool SENT = false; // data sent flag
bool ACK = false;  // data sent ok flag
bool SI = false;   // SI7021 present
bool BME = false;  // BME280 present
bool DS = false;   // DS18B20 present (not yet implemented)
// DS18B20 seems too slow, no promises that it will be implemented
/////////////////////////////////////////////////

char tx[128];

/////////////////////////////////////////////////
// BME280
/////////////////////////////////////////////////
// input your correct sensor altitude in meters
#define MYALTITUDE 100 // altitude in meters
// this value is needed for correct normalized
// pressure value (USA & Canada)
//
// Info:
// OpenWeatherMap reports normalized pres. also for Europe
/////////////////////////////////////////////////
