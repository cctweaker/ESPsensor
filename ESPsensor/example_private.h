
// rename file to private.h before building
// and change the values to your liking

// select the channel that your ESP-Now gateway uses
#define WIFI_CHANNEL 1

// select the MAC address that your ESP-Now gateway uses
// you can pick any address fro the following private ranges
// as long as it is not used by any other device
// x2-xx-xx-xx-xx-xx
// x6-xx-xx-xx-xx-xx
// xA-xx-xx-xx-xx-xx
// xE-xx-xx-xx-xx-xx
uint8_t gmac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
// using a custom mac will allow you to change the ESP on the gateway without changing the programming on sensors or buttons
// hardware mac address assigned to the ESP is unchanged, just not used in this case


uint8_t smac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE};  // sensors
uint8_t bmac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEF};  // buttons/switches


// pick 16 random numbers to use as key for message encoding
uint8_t KEY[16] = {0xDE, 0xAD, 0xBE, 0xEF,0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF};
#define KEYlen 16


// TIP will be sent json message
#define TIP "s"         // sensor
// #define TIP "l"      // light switch
// #define TIP "g"      // gateway MQTT

// NAME will be sent in json message
#define NAME "attic"
// #define NAME "kitchen"
// #define NAME "gameroom"
// #define NAME "basement"
// #define NAME "stairs"
