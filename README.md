# ESPsensor
is covering a need for low power, cheap, battery operated sensors that you can place throughout your house.
It is designed to use an ESP8266 and a SI7021 temperature and himidity sensor.
Communication is done through ESP-Now protocol to save a huge amount of power compared to regular WiFi.
It needs a <a href="https://github.com/cctweaker/ESPGW-Now">ESP-Now Gateway</a> to receive its output.

# Features
- perfect for infrequent small data transmissions
- no need for full blown WiFi, connects and transmits data instantly
- much faster than other solutions that rely on Wifi
- lower total power consumption, great for battery operated sensors/buttons
- uses a parallel network for IoT without hoarding your DHCP leases in WiFi (just the gateway is connected)

# Build
Clone in PlatformIO or download archive and extract main source folder to your Arduino projects folder.
Libraries will be automatically fetched in PlatformIO, for Arduino check below the needed libraries.

# Libraries
<a href="https://github.com/LowPowerLab/SI7021">Si7021 by Felix Rusu</a>

# Setup
Rename example_private.h to private.h and edit to you liking.

# Plans
- add more sensors types