void init_sensors()
{
    if (sensor.begin(2, 0))
    {
        SI = true;
        return;
    }

    if (BMESensor.begin())
    {
        BME = true;
        return;
    }

    // add DS18B20 init here

    if (!SI && !BME && !DS)
        goto_sleep();
}

void prepare_data()
{

    float vin = (float)ESP.getVcc() / FACTOR;

    if (SI)
    {
        si7021_env data = sensor.getHumidityAndTemperature();

        float temp = data.celsiusHundredths / 100.0F;
        float hum = data.humidityBasisPoints / 100.0F;
        float dew = 243.04 * (log(hum / 100.0) + ((17.625 * temp) / (243.04 + temp))) / (17.625 - log(hum / 100.0) - ((17.625 * temp) / (243.04 + temp)));

        sprintf(tx, "{\"t\":\"%s\",\"n\":\"%s\",\"ID\":\"%x\",\"v\":%d,\"tmp\":%.2f,\"hum\":%.2f,\"dew\":%.2f,\"vin\":%.2f}", TIP, NAME, ESP.getChipId(), VERSION, temp, hum, dew, vin);
    }

    if (BME)
    {
        BMESensor.refresh();
        // on the first reading, only after power down, BME280 reports erroneous values.
        // will need to discard the first reading in next version

        float temp = BMESensor.temperature;
        float hum = BMESensor.humidity;
        float dew = 243.04 * (log(hum / 100.0) + ((17.625 * temp) / (243.04 + temp))) / (17.625 - log(hum / 100.0) - ((17.625 * temp) / (243.04 + temp)));
        float relativepressure = BMESensor.seaLevelForAltitude(MYALTITUDE) / 100.0F;

        sprintf(tx, "{\"t\":\"%s\",\"n\":\"%s\",\"ID\":\"%x\",\"v\":%d,\"tmp\":%.2f,\"hum\":%.2f,\"dew\":%.2f,\"prs\":%.2f,\"prn\":%.2f,\"vin\":%.2f}", TIP, NAME, ESP.getChipId(), VERSION, temp, hum, dew, BMESensor.pressure / 100.0F, relativepressure, vin);
    }

    PREP = true;
}