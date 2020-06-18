/////////////////////////////////////////////////
// rename this file to private.h before building
// and change the values to your liking
/////////////////////////////////////////////////

/////////////////////////////////////////////////
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
// using a custom mac will allow you to change the ESP on the gateway without changing the programming on all sensors and buttons
// hardware mac address assigned to the ESP is unchanged, just not used in this case
// make sure to use the same gateway mac address in all projects!
//
uint8_t smac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE}; // sensors
// uint8_t bmac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEF}; // buttons/switches
// uint8_t dmac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xF0}; // door switches
// uint8_t wmac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xF1}; // window switches
// uint8_t mmac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xF2}; // movement detectors, light barriers
// ESP-GW can load up to 6 mac addresses following its own mac
// ESP-Now protocol allows up to 6 mac addresses in encrypted mode
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// KEYS, make sure they are the same for ESPGW-NOW!
/////////////////////////////////////////////////
// pick 16 random numbers to use as device key encoding key
uint8_t kok[16] = {0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF};
// pick 16 random numbers to use as device key
uint8_t key[16] = {0xFE, 0xED, 0xFE, 0xED, 0xFE, 0xED, 0xFE, 0xED, 0xFE, 0xED, 0xFE, 0xED, 0xFE, 0xED, 0xFE, 0xED};
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// TIP will be sent in json message
/////////////////////////////////////////////////
#define TIP "sensor" // sensor
// #define TIP "switch"   // light switch
// #define TIP "door"     // door switch
// #define TIP "window"   // window switch
// #define TIP "movement" // presence detectors, light barriers, etc
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// NAME will be sent in json message
/////////////////////////////////////////////////
#define NAME "attic"
// #define NAME "kitchen"
// #define NAME "gameroom"
// #define NAME "basement"
// #define NAME "stairs"
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// AP settings for this unit
// AP will appear briefly for about 200ms
// even so, we will password protect it and
// hide it from prying eyes
/////////////////////////////////////////////////
// select the channel that your ESP-Now gateway uses
// must be same as your ESP-Now gateway!!!
#define WIFI_CHANNEL 1
/////////////////////////////////////////////////
// HOSTNAME is used as AP name
// necessary to correctly set up the WIFI channel
#define HOSTNAME TIP "_" NAME
/////////////////////////////////////////////////
// PASSWORD is given just so no one will try to connect
#define PASSWORD "password"
/////////////////////////////////////////////////
// AP is hidden
#define HIDE_AP 1
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// sleep time (message rate)
/////////////////////////////////////////////////
#define SLEEP 10 * 60 * 1000 * 1000 // 1 minute
//            min  sec  msec   usec
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// measure your ESP VCC voltage with a good multimeter
// should be around 3.30V
#define MEASURED 3.27
// enter the ESP reported voltage
// this will fluctuate from ESP to ESP
// i've seen up to 3.39V reported
#define REPORTED 3.42
#define FACTOR 1024 * MEASURED / REPORTED
// use MQTT to send yourself a reminder to change/recharge batteries when voltage drops below 3.0-2.9V
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// flags
/////////////////////////////////////////////////
bool PREP = false; // prepare data flag
bool SENT = false; // data sent flag
bool ACK = false;  // data sent ok flag
bool SI = false;   // SI7021 present
bool BME = false;  // BME280 present
bool DS = false;   // DS18B20 present
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
// OpenWeatherMap reports normalized pres. for Europe
/////////////////////////////////////////////////
