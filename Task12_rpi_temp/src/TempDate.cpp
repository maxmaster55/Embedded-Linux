#include <tempData.h>

float TempData::read_temperature(){
    return temp_data/1000;
}
float TempData::read_humidity(){
    return hum_data/1000;
}
void TempData::set_temperature(int sensor_val){
    temp_data = sensor_val;
}
void TempData::set_humidity(int sensor_val){
    hum_data = sensor_val;
}
