char tx[250];
uint8_t ack = 55;

boolean SNS = false; // sensor read flag
boolean SNT = false; // data sent flag
boolean ACK = false; // data sent ok flag

#define SLEEP 60 * 1000 * 1000 // 60 seconds

// measure your ESP VCC voltage with a good multimeter
// should be around 3.30V
#define MEASURED 3.30
// enter the ESP reported voltage
// this will fluctuate from ESP to ESP
// i've seen up to 3.39V reported
#define REPORTED 3.30
#define FACTOR 1024 * MEASURED / REPORTED
// use MQTT to send yourself a reminder to change/recharge batteries when voltage drops below 3.0-2.9V