#include <tempData.h>

TempData::TempData()
{
}


float TempData::read_temp(){
    const float REFERENCE_VOLTAGE = 3.3f;      // Raspberry Pi 3.3V
    const float ADC_MAX = 4095.0f;             // 12-bit ADC max value
    const float LM35_GAIN = 100.0f;            // 100°C per Volt (10mV/°C)
    
    float voltage = this->data * (REFERENCE_VOLTAGE / ADC_MAX);
    float temp = voltage * LM35_GAIN;
    return temp;
}

void TempData::setTemp(int sensor_val){
    this->data = sensor_val;
}


TempData::~TempData()
{
}


