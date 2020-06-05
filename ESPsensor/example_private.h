/////////////////////////////////////////////////
// rename this file to private.h before building
// and change the values to your liking
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// select the channel that your ESP-Now gateway uses
/////////////////////////////////////////////////
#define WIFI_CHANNEL 1
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