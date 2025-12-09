#pragma once 

#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <inttypes.h>
#include <errno.h>
#include <string>

class DHT_Sensor {
private:
    int temp_fd;
    int hum_fd;
    
public:
    DHT_Sensor(int pin);
    ~DHT_Sensor();
        
    int read_temperature();
    int read_humidity();
};

