#pragma once


class TempData
{
private:
    float data;
public:
    TempData();
    float read_temp();
    ~TempData();
};