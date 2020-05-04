struct __attribute__((packed)) DataStruct
{
    char text[128];
};
struct __attribute__((packed)) ReplyStruct
{
    uint8_t ack = 55;
};

DataStruct sendingData;
ReplyStruct receivedData;

boolean SNS = false;
boolean SNT = false;
boolean ACK = false;

#define SLEEP 60 * 1000 * 1000 // 60 seconds

float tmp = 0;
float hum = 0;
float bat = 0;

// measure your ESP VCC voltage with a good multimeter
// should be around 3.30V
#define MEASURED 3.30
// enter the ESP reported voltage
// this will fluctuate from ESP to ESP
// i've seen up to 3.39V reported
#define REPORTED 2.85
#define BATTFACTOR 1024 * MEASURED / REPORTED