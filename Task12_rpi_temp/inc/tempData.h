#pragma once


class TempData
{
private:
    float data;
public:
    TempData();
    float read_temp();
    void setTemp(int sensor_val);
    ~TempData();
};