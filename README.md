# ESPsensor
is covering a need for low power, cheap, battery operated sensors that you can place throughout your house.
It is designed to use an ESP-01 / ESP-01S and a SI7021 temperature and humidity sensor.
Communication is done through ESP-Now protocol to save a huge amount of power compared to regular WiFi.
It needs a <a href="https://github.com/cctweaker/ESPGW-Now">ESP-Now Gateway</a> to receive its output.

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

# Libraries
<a href="https://github.com/LowPowerLab/SI7021">Si7021 by Felix Rusu</a>

# Setup
Rename example_private.h to private.h and edit to you liking.

# Plans
- add more sensor types

# Info
Boards like NodeMCU and WeMos D1 can not measure ADC_VCC (their own voltage) because the ADC pin is connected to a voltage divider. To measure ADC_VCC the ADC pin must be floating like in ESP-01, ESP-07 and ESP-12 modules.

# Hardware
Roll your own based on the schematics inside hardware folder or get the PCB (with or without components) from <a href="https://3dstar.ro/proiecte/espsensor">3DStar.ro ESPsensor PCBs</a>

# Deep Sleep Mod
ESP-01 and ESP-01S do not have GPIO 16 available. To use them for deepsleep a small mod is necessary. GPIO 16 is nicely exposed on the bottom-left side of the ESP8266 chip. All we need to do is bridge it with a wire to RESET pin.
Pictures are available in the project's hardware folder.