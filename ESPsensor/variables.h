boolean SENT = false; // data sent flag
boolean ACK = false;  // data sent ok flag

#define SLEEP 1 * 60 * 1000 * 1000 // 1 minute

// measure your ESP VCC voltage with a good multimeter
// should be around 3.30V
#define MEASURED 3.3
// enter the ESP reported voltage
// this will fluctuate from ESP to ESP
// i've seen up to 3.39V reported
#define REPORTED 3.38
#define FACTOR 1024 * MEASURED / REPORTED
// use MQTT to send yourself a reminder to change/recharge batteries when voltage drops below 3.0-2.9V