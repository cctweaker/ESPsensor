# ESPsensor
is covering a need for low power, cheap, battery operated sensors that you can place throughout your house.
It is designed to use an ESP-01 / ESP-01S and a SI7021 temperature and humidity sensor. BME280 sensors are also supported and add air pressure readings (real and normalized).
Communication is done through ESP-Now protocol to save a huge amount of power compared to regular WiFi.
It needs a <a href="https://github.com/cctweaker/ESPGW-Now">ESP-Now Gateway</a> to receive its output.

# Sensors supported
- SI7021 for temperature, humidity and dew point
- BME280 for temperature, humidity, dew point, pressure, normalized pressure

# Features
- perfect for infrequent small data transmissions
- no need for full blown WiFi, connects and transmits data instantly
- much faster than other solutions that rely on Wifi
- much faster trasnfer speed compared to other 2.4GHz protocols
- lower total power consumption, great for battery operated sensors/buttons
- uses a parallel network for IoT without hoarding your DHCP leases in WiFi (just the gateway is connected)

# Build
Clone in PlatformIO or download archive and extract main source folder to your Arduino projects folder.
Libraries will be automatically fetched in PlatformIO, for Arduino check below for the needed libraries.

# Setup
Rename example_private.h to private.h and edit to you liking.

# Info
Boards like NodeMCU and WeMos D1 can not measure ADC_VCC (their own voltage) because the ADC pin is connected to a voltage divider. To measure ADC_VCC the ADC pin must be floating like in ESP-01, ESP-07 and ESP-12 modules.

# Hardware
Roll your own based on the schematics inside hardware folder or get the PCB (with or without components) from <a href="https://3dstar.ro/proiecte/espsensor">3DStar.ro ESPsensor PCBs</a>

# Deep Sleep Mod
ESP-01 and ESP-01S do not have GPIO 16 available. To use them for deepsleep a small mod is necessary. GPIO 16 is nicely exposed on the bottom-left side of the ESP8266 chip. All we need to do is bridge it with a wire to RESET pin.
Pictures are available in the project's hardware folder.

# Message format
ESPsensor sends a message with the following format: <code>{"t":"sensor","n":"attic","ID":"abcdef","tmp":27.02,"hum":54.74,"dew":17.14,"prs":998.08,"prn":1008.54,"vin":3.31}</code>
- t: device type. Value can be sensor, switch or anything else you define.
- n: device name. Value can be room name or any other name you give to the device.
- ID: ESPid, last 4 bytes of the ESP's mac address.
- tmp: temperature reading
- hum: humidity reading
- dew: dew point estimation
- prs: air pressure reading (only for BME280 sensor)
- prn: normalized (sea level) air pressure reading as reported in North America (only for BME280 sensor)
- vin: ESP voltage. Good until about 2.9V. Best to change batteries when voltage falls below 3.00V

# Libraries
- <a href="https://github.com/LowPowerLab/SI7021">Si7021 by Felix Rusu</a>
<br>
- <a href="https://github.com/zen/BME280_light">BME280_Light by zen</a>

# Plans
- add more sensor types