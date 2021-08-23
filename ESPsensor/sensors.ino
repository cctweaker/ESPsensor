void init_sensors()
{
#ifdef SENSOR_SI7021
    // if (sensor.begin(0, 2)) // testboard
    if (sensor.begin(2, 0)) // PCB
        SI = true;
#endif

#ifdef SENSOR_BME280
    // Wire.begin(0, 2); // testboard
    Wire.begin(2, 0); // PCB
    if (BMESensor.begin())
        BME = true;
#endif

#ifdef SENSOR_DS1820
    // todo
    DS = true;
#endif
}

//

void prepare_data()
{
#ifdef SENSOR_SI7021
    if (SI)
    {
        si7021_env data = sensor.getHumidityAndTemperature();

        float temp = data.celsiusHundredths / 100.0F;
        float hum = data.humidityBasisPoints / 100.0F;
        float dew = 243.04 * (log(hum / 100.0) + ((17.625 * temp) / (243.04 + temp))) / (17.625 - log(hum / 100.0) - ((17.625 * temp) / (243.04 + temp)));

        sprintf(tx, "{\"t\":\"%s\",\"v\":%.2f,\"ID\":\"%x\",\"vcc\":%d,\"tmp\":%.2f,\"hum\":%.2f,\"dew\":%.2f}", FWN, VERSION, ESP.getChipId(), ESP.getVcc(), temp, hum, dew);
    }
#endif

#ifdef SENSOR_BME280
    if (BME)
    {
        BMESensor.refresh();

        // on the first reading, only after power down, BME280 reports erroneous values!

        float temp = BMESensor.temperature;
        float hum = BMESensor.humidity;
        float dew = 243.04 * (log(hum / 100.0) + ((17.625 * temp) / (243.04 + temp))) / (17.625 - log(hum / 100.0) - ((17.625 * temp) / (243.04 + temp)));
        float relativepressure = BMESensor.seaLevelForAltitude(MYALTITUDE) / 100.0F;

        sprintf(tx, "{\"t\":\"%s\",\"v\":%.2f,\"ID\":\"%06x\",\"vcc\":%d,\"tmp\":%.2f,\"hum\":%.2f,\"dew\":%.2f,\"prs\":%.2f,\"prn\":%.2f}", FWN, VERSION, ESP.getChipId(), ESP.getVcc(), temp, hum, dew, BMESensor.pressure / 100.0F, relativepressure);
    }
#endif

    if (!SI && !BME && !DS)
    {
        // no sensor detected, send some data!
        sprintf(tx, "{\"t\":\"%s\",\"v\":%.2f,\"ID\":\"%x\",\"vcc\":%d}", FWN, VERSION, ESP.getChipId(), ESP.getVcc());
    }

    PREP = true;
}