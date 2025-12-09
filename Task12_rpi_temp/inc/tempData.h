#pragma once


class TempData
{
private:
    float temp_data;
    float hum_data;
public:
    float read_temperature();
    float read_humidity();
    void set_temperature(int sensor_val);
    void set_humidity(int sensor_val);
};